#!/usr/bin/env bash

# Build all C_EXAMPLE programs on Linux.
# Output directory: C_EXAMPLE/build

set -uo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
SDK_DIR="$(cd -- "$SCRIPT_DIR/../C_SDK" && pwd)"
BUILD_DIR="$SCRIPT_DIR/build"

CXX="${CXX:-g++}"

SDK_LIBRARY="$SDK_DIR/libGentoSDK.so"

INC_DIRS=(
    "-I$SDK_DIR/Common"
    "-I$SDK_DIR/L0Control"
    "-I$SDK_DIR/L1Robot"
    "-I$SDK_DIR/Kinematics"
    "-I$SDK_DIR/Kinematics/ArmKinematics"
    "-I$SDK_DIR/Kinematics/BaseMath"
    "-I$SDK_DIR/Kinematics/DynaIdent"
    "-I$SDK_DIR/Kinematics/KineCommon"
    "-I$SDK_DIR/Kinematics/MotionPlanner"
    "-I$SDK_DIR/Kinematics/SkyeBodyKinematics"
    "-I$SDK_DIR/FileClient"
)

CXX_FLAGS=(
    -Wall
    -Wextra
    -O2
    -DCMPL_LIN
)

LINK_FLAGS=(
    "-L$SDK_DIR"
    -lGentoSDK
    '-Wl,-rpath,$ORIGIN/../../C_SDK'
    -pthread
    -lrt
)

if ! command -v "$CXX" >/dev/null 2>&1; then
    echo "Error: compiler not found: $CXX"
    echo "Install it with:"
    echo "  sudo apt install build-essential"
    exit 1
fi

if [[ ! -f "$SDK_LIBRARY" ]]; then
    echo "Error: SDK library not found:"
    echo "  $SDK_LIBRARY"
    echo
    echo "Please build the SDK first from the repository root:"
    echo "  ./linux_auto_compile.sh"
    exit 1
fi

mkdir -p "$BUILD_DIR"

mapfile -d '' SOURCES < <(
    find "$SCRIPT_DIR" \
        -maxdepth 1 \
        -type f \
        -name '*.cpp' \
        -print0 |
    sort -z
)

if [[ ${#SOURCES[@]} -eq 0 ]]; then
    echo "Error: no .cpp files found in:"
    echo "  $SCRIPT_DIR"
    exit 1
fi

SUCCESS_COUNT=0
FAILED_COUNT=0
FAILED_SOURCES=()

echo "========================================"
echo "Building all C_EXAMPLE programs"
echo "Compiler : $CXX"
echo "SDK      : $SDK_DIR"
echo "Output   : $BUILD_DIR"
echo "Examples : ${#SOURCES[@]}"
echo "========================================"
echo

for source_file in "${SOURCES[@]}"; do
    source_name="$(basename -- "$source_file")"
    target_name="${source_name%.cpp}"
    target_file="$BUILD_DIR/$target_name"

    echo "[$((SUCCESS_COUNT + FAILED_COUNT + 1))/${#SOURCES[@]}] Building $source_name"

    if "$CXX" \
        "$source_file" \
        "${INC_DIRS[@]}" \
        "${CXX_FLAGS[@]}" \
        "${LINK_FLAGS[@]}" \
        -o "$target_file"; then

        echo "  OK: build/$target_name"
        ((SUCCESS_COUNT += 1))
    else
        echo "  FAILED: $source_name"
        ((FAILED_COUNT += 1))
        FAILED_SOURCES+=("$source_name")
        rm -f -- "$target_file"
    fi

    echo
done

echo "========================================"
echo "Build summary"
echo "Success: $SUCCESS_COUNT"
echo "Failed : $FAILED_COUNT"
echo "Output : $BUILD_DIR"
echo "========================================"

if [[ $FAILED_COUNT -gt 0 ]]; then
    echo
    echo "Failed examples:"

    for source_name in "${FAILED_SOURCES[@]}"; do
        echo "  - $source_name"
    done

    exit 1
fi

echo
echo "All examples built successfully."