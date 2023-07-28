#!/bin/sh
export CC=/opt/cross-pi-gcc/bin/arm-linux-gnueabihf-gcc
export CXX=/opt/cross-pi-gcc/bin/arm-linux-gnueabihf-g++
make clean

make -j$(nproc)
make install
