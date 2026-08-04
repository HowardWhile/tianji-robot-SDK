#!/usr/bin/env bash
# Download the latest prebuilt Gento SDK for the current Linux architecture.
set -euo pipefail

REPOSITORY="HowardWhile/tianji-robot-SDK"
INSTALL_DIR="$HOME/.local/lib/fiibot"
API_URL="https://api.github.com/repos/${REPOSITORY}/releases/latest"

die() {
    echo "[ERROR] $*" >&2
    exit 1
}

command -v wget >/dev/null 2>&1 || die "wget is required."

case "$(uname -m)" in
    x86_64|amd64)
        architecture="x86_64"
        asset_pattern='(x86_64|amd64|x64|linux[-_.]?x86[-_.]?64)'
        ;;
    aarch64|arm64)
        architecture="arm64"
        asset_pattern='(aarch64|arm64)'
        ;;
    *)
        die "Unsupported CPU architecture: $(uname -m). Supported: x86_64, arm64."
        ;;
esac

metadata_file="$(mktemp)"
trap 'rm -f "$metadata_file"' EXIT

echo "[INFO] Detecting the latest release for ${architecture}..."
wget -qO "$metadata_file" "$API_URL" \
    || die "Could not fetch the latest-release metadata from GitHub."

# Releases publish libraries as libGentoSDK-<architecture>.so.  Accept common
# architecture spellings so future release assets can use equivalent names.
asset_url="$({
    sed -n 's/.*"browser_download_url"[[:space:]]*:[[:space:]]*"\([^"]*\)".*/\1/p' "$metadata_file" \
        | grep -Ei "/[^/]*libGentoSDK[^/]*${asset_pattern}[^/]*\\.so$" \
        | head -n 1
} || true)"

[ -n "$asset_url" ] || die "No libGentoSDK .so asset for ${architecture} was found in the latest release."

asset_name="${asset_url##*/}"
case "$asset_name" in
    *.so) ;;
    *) die "Refusing unexpected release asset name: ${asset_name}" ;;
esac

mkdir -p "$INSTALL_DIR"
temporary_library="$INSTALL_DIR/.${asset_name}.tmp.$$"
trap 'rm -f "$metadata_file" "$temporary_library"' EXIT

echo "[INFO] Downloading ${asset_name}..."
wget -q --show-progress -O "$temporary_library" "$asset_url" \
    || die "Failed to download ${asset_name}."
[ -s "$temporary_library" ] || die "Downloaded library is empty."

mv -f "$temporary_library" "$INSTALL_DIR/$asset_name"
ln -sfn "$asset_name" "$INSTALL_DIR/libGentoSDK.so"

echo "[OK] Installed: $INSTALL_DIR/$asset_name"
echo "[OK] Symlink:   $INSTALL_DIR/libGentoSDK.so -> $asset_name"
