#!/usr/bin/env bash

mkdir build_debug && cd build_debug
cmake -GNinja -DDEFINE_DEBUG=ON -DLINUX_BUILD=ON -DTRAVIS_BUILD=ON ../
cmake --build . --config Debug
cd bin
./../../scripts/travis/run_examples.sh
exit_code=$?
if [[ ${exit_code} != 0 ]]
	then
	exit ${exit_code}
fi
cd ../../
mkdir build_release && cd build_release
cmake -GNinja -DDEFINE_RELEASE=ON -DLINUX_BUILD=ON -DTRAVIS_BUILD=ON ../
cmake --build . --config Release
cd bin
./../../scripts/travis/run_examples.sh
exit_code=$?
if [[ ${exit_code} != 0 ]]
	then
	exit ${exit_code}
fi