#!/bin/bash
# ============================================================================
#  多架构兼容性编译脚本 — 在 Docker 容器内构建 x86_64 与 ARM64 共享库
#
#  默认使用 ubuntu:20.04（glibc 2.31），分别使用交叉工具链生成：
#    C_SDK/libGentoSDK-x86_64.so
#    C_SDK/libGentoSDK-arm64.so
#
#  完成后会依据执行脚本的宿主机架构，选择对应的产物复制到
#  C_EXAMPLE_USE_DLL_SO/libGentoSDK.so，保持现有 C++ 示例的链接方式。
#
#  用法:
#    ./linux_auto_compile_compitable.sh
#    BASE_IMAGE=ubuntu:18.04 ./linux_auto_compile_compitable.sh
# ============================================================================
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
SDK_DIR="$SCRIPT_DIR/C_SDK"
C_SO_DIR="$SCRIPT_DIR/C_EXAMPLE_USE_DLL_SO"

# 默认用 Ubuntu 20.04 编译（glibc 2.31，覆盖主流系统）
BASE_IMAGE="${BASE_IMAGE:-ubuntu:20.04}"

CPP_FILES="
  ./L0Control/*.cpp
  ./FileClient/*.cpp
  ./L1Robot/*.cpp
  ./Kinematics/*.cpp
  ./Kinematics/ArmKinematics/*.cpp
  ./Kinematics/BaseMath/*.cpp
  ./Kinematics/DynaIdent/*.cpp
  ./Kinematics/KineCommon/*.cpp
  ./Kinematics/MotionPlanner/*.cpp
  ./Kinematics/SkyeBodyKinematics/*.cpp
"

INC_DIRS="
  -I./Common
  -I./Kinematics
  -I./Kinematics/ArmKinematics
  -I./Kinematics/BaseMath
  -I./Kinematics/DynaIdent
  -I./Kinematics/KineCommon
  -I./Kinematics/MotionPlanner
  -I./Kinematics/SkyeBodyKinematics
  -I./FileClient
  -I./L0Control
  -I./L1Robot
"

compile_for_arch() {
    local arch="$1"
    local compiler="$2"
    local output="libGentoSDK-${arch}.so"

    echo "============================================"
    echo "Building ${output}"
    echo "============================================"
    "$compiler" $CPP_FILES $INC_DIRS \
      -Wall -O2 -fPIC -shared \
      -Wl,-soname,libGentoSDK.so \
      -Wl,--hash-style=both \
      -o "$output" \
      -DCMPL_LIN -DL1_SDK_EXPORTS \
      -static-libgcc -static-libstdc++ \
      -lpthread -lrt
    echo "[OK] ${output} built."
}

host_arch() {
    local machine="${HOST_ARCH:-$(uname -m)}"

    case "$machine" in
        x86_64|amd64) echo "x86_64" ;;
        aarch64|arm64) echo "arm64" ;;
        *)
            echo "[ERROR] Unsupported host architecture: $machine" >&2
            echo "[INFO] Built libraries remain available in C_SDK/." >&2
            return 1
            ;;
    esac
}

do_compile() {
    mkdir -p "$C_SO_DIR"
    cd "$SDK_DIR"

    compile_for_arch "x86_64" "g++"
    echo
    compile_for_arch "arm64" "aarch64-linux-gnu-g++"

    cd "$SCRIPT_DIR"

    local native_arch
    native_arch="$(host_arch)"
    local source_so="$SDK_DIR/libGentoSDK-${native_arch}.so"

    echo
    echo "============================================"
    echo "Copying ${native_arch} SO to target folder..."
    echo "============================================"

    if [ ! -f "$source_so" ]; then
        echo "[FAIL] Source file not found: $source_so"
        exit 1
    fi

    cp -v "$source_so" "$C_SO_DIR/libGentoSDK.so"
    echo "[OK] libGentoSDK-${native_arch}.so -> C_EXAMPLE_USE_DLL_SO/libGentoSDK.so"
}

if [ "${1:-}" = "--in-container" ]; then
    do_compile
    exit 0
fi

echo "[INFO] Docker multi-architecture compatibility build (image: $BASE_IMAGE)"
echo "[INFO] Produces x86_64 and ARM64 libraries using Ubuntu 20.04-era glibc."

if ! command -v docker &>/dev/null; then
    echo "[ERROR] Docker not found. Please install Docker and try again."
    exit 1
fi

HOST_ARCH="$(host_arch)"

docker run --rm \
  --platform linux/amd64 \
  -e HOST_ARCH="$HOST_ARCH" \
  -v "$SCRIPT_DIR":/work \
  -w /work \
  "$BASE_IMAGE" \
  bash -c "
    set -e
    echo '[INFO] Container glibc: '\$(ldd --version 2>&1 | head -1)
    apt-get update -qq
    apt-get install -y -qq --no-install-recommends \\
      g++ \\
      g++-aarch64-linux-gnu
    echo '[INFO] x86_64 compiler: '\$(g++ --version | head -1)
    echo '[INFO] ARM64 compiler: '\$(aarch64-linux-gnu-g++ --version | head -1)
    bash linux_auto_compile_compitable.sh --in-container
  "
