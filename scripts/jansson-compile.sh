#!/bin/sh
export CROSS_PREFIX=/opt/cross-pi-gcc/bin/arm-linux-gnueabihf-
export CC=${CROSS_PREFIX}gcc
export CXX=${CROSS_PREFIX}g+
export INSTALL_DIR=/home/vienchau/build-example/pi/

./configure --prefix=${INSTALL_DIR} --host=arm-linux 

make -j $(nproc)
make install
