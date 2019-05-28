#!/bin/bash

for i in `ls build_debug/bin`;
do
    ./engine/build_debug/bin/${i}
    if [[ $? != 0 ]]
        then
            exit $?
    fi
done

for i in `ls build_release/bin`;
do
    ./engine/build_debug/bin/${i}
    if [[ $? != 0 ]]
        then
            exit $?
    fi
done

exit 0