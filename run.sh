#!/bin/bash

for i in `ls engine/build_debug/bin`;
do
    ./engine/build_debug/bin/${i}
    if [[ $? == 0 ]]
        then
            exit $?
    fi
done

exit 0