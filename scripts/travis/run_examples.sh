#!/usr/bin/env bash

for i in `ls`;
do
    ./${i}
    exit_code=$?
    if [[ ${exit_code} != 0 ]]
        then
            exit ${exit_code}
    fi
done

exit 0