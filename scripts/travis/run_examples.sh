#!/usr/bin/env bash

for i in `ls`;
do
    echo "Running ->" ${i}
    ./${i}
    exit_code=$?
    if [[ ${exit_code} != 0 ]]
        then
            echo "Failed -> "${i}
            exit ${exit_code}
    fi
    echo "Ending ->" ${i}
done

exit 0