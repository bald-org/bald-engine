#!/usr/bin/env bash

for i in `ls *.exe`;
do
    echo "Running ->" ${i}
    ./${i} > output.txt
    exit_code=$?
    if [[ ${exit_code} != 0 ]]
        then
            echo "Failed -> "${i}
            cat output.txt
            exit ${exit_code}
    fi
    echo "Ending ->" ${i}
done

exit 0