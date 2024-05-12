#!/bin/bash

set -ueo pipefail

result="";

function main()
{
    for i in {2..19}
    do
        result="$(./../target/debug/project_3 --generate < ./benchmark_data/$i)";

    done

}

main $result