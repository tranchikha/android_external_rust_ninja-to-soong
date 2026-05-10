#!/bin/bash
#
mesa_path=$1

export mydir=`pwd`
MAJOR_VERSION=18
sudo apt install \
     meson-1.5 \
     libclang-${MAJOR_VERSION}-dev \
     libclang-cpp${MAJOR_VERSION}{,-dev} \
     libclc-${MAJOR_VERSION}{,-dev} \
     libllvmspirvlib-${MAJOR_VERSION}-dev \
     llvm-${MAJOR_VERSION}-{dev,tools} \
     glslang-tools \
     python3-{mako,ply} \
     libwayland-egl-backend-dev \
     libxcb-randr0-dev \
     libxcb-glx0-dev libxcb-present-dev libx11-xcb-dev \
     libxcb-dri3-dev -y

cd $mesa_path

meson  setup build-host -Dtools=panfrost -Dmesa-clc=enabled -Dinstall-mesa-clc=true -Dprecomp-compiler=enabled -Dinstall-precomp-compiler=true -Dgallium-drivers=panfrost -Dvulkan-drivers=panfrost
ninja -C build-host
find build-host/ -name "mesa-clc"
find build-host/ -name "mesa_clc"
find build-host/ -name "vtn_bindgen2"
find build-host/ -name "panfrost_compile"
ls -lah build-host/src/compiler/clc/mesa_clc build-host/src/compiler/spirv/vtn_bindgen2 build-host/src/panfrost/clc/panfrost_compile
sudo cp -rf build-host/src/compiler/clc/mesa_clc /usr/local/bin/
sudo cp -rf build-host/src/compiler/spirv/vtn_bindgen2 /usr/local/bin/
sudo cp -rf build-host/src/panfrost/clc/panfrost_compile /usr/local/bin/

cd $mydir
