#!/usr/bin/env bash

mkdir build_debug && cd build_debug
cmake -GNinja -DDEFINE_DEBUG=ON -DLINUX_BUILD=ON -DTRAVIS_BUILD=ON ../
ninja
ls
cd bin
ls
./../../scripts/travis/run_examples.sh
cd ../../
mkdir build_release && cd build_release
cmake -GNinja -DDEFINE_RELEASE=ON -DLINUX_BUILD=ON -DTRAVIS_BUILD=ON ../
ninja
./../../scripts/travis/run_examples.sh 