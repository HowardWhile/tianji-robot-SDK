#!/usr/bin/env bash
# Download the v4.7.2 prebuilt Gento SDK for the current Linux architecture.
set -euo pipefail

REPOSITORY="HowardWhile/tianji-robot-SDK"
RELEASE_TAG="v4.7.2"
INSTALL_DIR="/usr/lib/fiibot"
API_URL="https://api.github.com/repos/${REPOSITORY}/releases/tags/${RELEASE_TAG}"

die() {
    echo "[ERROR] $*" >&2
    exit 1
}

command -v wget >/dev/null 2>&1 || die "wget is required."

case "$(uname -m)" in
    x86_64|amd64)
        architecture="x86_64"
        ;;
    aarch64|arm64)
        architecture="arm64"
        ;;
    *)
        die "Unsupported CPU architecture: $(uname -m). Supported: x86_64, arm64."
        ;;
esac

metadata_file="$(mktemp)"
trap 'rm -f "$metadata_file"' EXIT

echo "[INFO] Detecting release ${RELEASE_TAG} for ${architecture}..."
wget -qO "$metadata_file" "$API_URL" \
    || die "Could not fetch release ${RELEASE_TAG} metadata from GitHub."

# Releases publish libraries as libGentoSDK-<version>-<architecture>.so.
asset_name="libGentoSDK-${RELEASE_TAG}-${architecture}.so"
expected_url="https://github.com/${REPOSITORY}/releases/download/${RELEASE_TAG}/${asset_name}"
asset_url="$({
    sed -n 's/.*"browser_download_url"[[:space:]]*:[[:space:]]*"\([^"]*\)".*/\1/p' "$metadata_file" \
        | grep -Fx "$expected_url" \
        | head -n 1
} || true)"

[ -n "$asset_url" ] || die "No libGentoSDK .so asset for ${architecture} was found in release ${RELEASE_TAG}."

asset_name="${asset_url##*/}"
case "$asset_name" in
    *.so) ;;
    *) die "Refusing unexpected release asset name: ${asset_name}" ;;
esac

temporary_library="$(mktemp)"
trap 'rm -f "$metadata_file" "$temporary_library"' EXIT

echo "[INFO] Downloading ${asset_name}..."
wget -q --show-progress -O "$temporary_library" "$asset_url" \
    || die "Failed to download ${asset_name}."
[ -s "$temporary_library" ] || die "Downloaded library is empty."

install_command=()
if [ "$(id -u)" -ne 0 ]; then
    command -v sudo >/dev/null 2>&1 || die "sudo is required to install into $INSTALL_DIR."
    install_command=(sudo)
fi

"${install_command[@]}" install -d -m 755 "$INSTALL_DIR"
"${install_command[@]}" install -m 644 "$temporary_library" "$INSTALL_DIR/$asset_name"
"${install_command[@]}" ln -sfnT "$asset_name" "$INSTALL_DIR/libGentoSDK.so"

echo "[OK] Installed: $INSTALL_DIR/$asset_name"
echo "[OK] Symlink:   $INSTALL_DIR/libGentoSDK.so -> $asset_name"
