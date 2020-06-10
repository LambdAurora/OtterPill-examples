#!/bin/sh

git submodule update --init # Sanity check for the submodules.
mkdir -p build
cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchains/arm_none_eabi_gcc.cmake
