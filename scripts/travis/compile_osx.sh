#!/usr/bin/env bash

mkdir build_debug && cd build_debug
$HOME/cmake-3.15.4-Darwin-x86_64/CMake.app/Contents/bin/cmake -GNinja -DDEFINE_DEBUG=ON -DLINUX_BUILD=ON -DTRAVIS_BUILD=ON ../
$HOME/cmake-3.15.4-Darwin-x86_64/CMake.app/Contents/bin/cmake --build . --config Debug
cd bin
./../../scripts/travis/run_examples.sh
exit_code=$?
if [[ ${exit_code} != 0 ]]
	then
	exit ${exit_code}
fi
cd ../../
mkdir build_release && cd build_release
$HOME/cmake-3.15.4-Darwin-x86_64/CMake.app/Contents/bin/cmake -GNinja -DDEFINE_RELEASE=ON -DLINUX_BUILD=ON -DTRAVIS_BUILD=ON ../
$HOME/cmake-3.15.4-Darwin-x86_64/CMake.app/Contents/bin/cmake --build . --config Release
cd bin
./../../scripts/travis/run_examples.sh
exit_code=$?
if [[ ${exit_code} != 0 ]]
	then
	exit ${exit_code}
fi