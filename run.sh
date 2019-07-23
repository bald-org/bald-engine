#!/bin/bash

for i in `ls build_debug/bin`;
do
    ./build_debug/bin/${i}
    exit_code=$?
    if [[ ${exit_code} != 0 ]]
        then
            exit ${exit_code}
    fi
done

for i in `ls build_release/bin`;
do
    ./build_debug/bin/${i}
    exit_code=$?
    if [[ ${exit_code} != 0 ]]
        then
            exit ${exit_code}
    fi
done

exit 0