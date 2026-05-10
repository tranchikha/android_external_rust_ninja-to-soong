#!/usr/bin/env bash
# Copyright 2025 ninja-to-soong authors
# Copyright 2025 KonstaKANG
# SPDX-License-Identifier: Apache-2.0

set -xe

[ $# -eq 3 ]
SRC_PATH="$1"
BUILD_PATH="$2"
NDK_PATH="$3"

SCRIPT_DIR="$(dirname "$(realpath "${BASH_SOURCE[0]}")")"
MESON_LOCAL_PATH="${HOME}/.local/share/meson/cross"
AOSP_AARCH64="aosp-aarch64"
ANDROID_PLATFORM="36"
mkdir -p "${MESON_LOCAL_PATH}"
ANDROID_PLATFORM="${ANDROID_PLATFORM}" NDK_PATH="${NDK_PATH}" \
envsubst < "${SCRIPT_DIR}/${AOSP_AARCH64}.template" > "${MESON_LOCAL_PATH}/${AOSP_AARCH64}"

meson setup \
    --cross-file "${AOSP_AARCH64}" \
    --libdir lib64 \
    --sysconfdir=/system/vendor/etc \
    -Dandroid-libbacktrace=disabled \
    -Dbuildtype=release \
    -Dplatforms=android \
    -Dllvm=disabled \
    -Degl=enabled \
    -Dplatform-sdk-version=${ANDROID_PLATFORM} \
    -Dandroid-stub=true \
    -Degl-lib-suffix=_mesa \
    -Dgles-lib-suffix=_mesa \
    -Dgbm-backends-path=/apex/com.android.hardware.graphics.allocator.minigbm_dmabuf/lib64 \
    -Dcpp_rtti=false \
    -Dlmsensors=disabled \
    -Dgallium-drivers=panfrost \
    -Dvulkan-drivers=panfrost \
    -Dtools= \
    -Dgbm=enabled \
    -Dgbm-backends-path=/vendor/lib64 \
    -Dmesa-clc=system \
    -Dprecomp-compiler=system \
    -Dallow-fallback-for=libdrm \
    -Dstrip=true \
    --reconfigure \
    --wipe \
    "${BUILD_PATH}" \
    "${SRC_PATH}"
