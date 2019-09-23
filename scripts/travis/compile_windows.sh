#!/usr/bin/env bash

mkdir build_debug && cd build_debug
../cmake-3.15.3-win32-x86/bin/cmake.exe -DDEFINE_DEBUG=ON -DWINDOWS_BUILD=ON -DTRAVIS_BUILD=ON ../
#export PATH=$MSBUILD_PATH:$PATH
#MSBuild.exe bald.sln
../cmake-3.15.3-win32-x86/bin/cmake.exe --build . --config Debug
cd bin/Debug/
./../../../scripts/travis/run_examples.sh
cat output.txt
cd ../../../
mkdir build_release && cd build_release
../cmake-3.15.3-win32-x86/bin/cmake.exe -DDEFINE_RELEASE=ON -DWINDOWS_BUILD=ON -DTRAVIS_BUILD=ON ../
#export PATH=$MSBUILD_PATH:$PATH
#MSBuild.exe bald.sln
../cmake-3.15.3-win32-x86/bin/cmake.exe --build . --config Release
cd bin/Debug/
./../../../scripts/travis/run_examples.sh
cat output.txt