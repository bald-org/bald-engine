#!/usr/bin/env bash

mkdir build_debug && cd build_debug
../cmake-3.15.3-win32-x86/bin/cmake.exe -DDEFINE_DEBUG=ON -DWINDOWS_BUILD=ON -DTRAVIS_BUILD=ON ../
../cmake-3.15.3-win32-x86/bin/cmake.exe --build . -j12 --config Debug
cd ../
mkdir build_release && cd build_release
../cmake-3.15.3-win32-x86/bin/cmake.exe -DDEFINE_RELEASE=ON -DWINDOWS_BUILD=ON -DTRAVIS_BUILD=ON ../
../cmake-3.15.3-win32-x86/bin/cmake.exe --build . -j12 --config Release