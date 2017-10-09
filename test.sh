#!/bin/bash

flag=""

if [ "$1" = "-v" ]; then
    flag="-v"
    program=$2
    directory=$3
else
    program=$1
    directory=$2
fi
rm -f s_out.out
rm -f out.err
for i in $directory/test*.in; do
    ./$program $flag <$i >>s_out.out 2>out.err
    DIFF=$(diff ${i::-3}.out s_out.out)
    if [ "$DIFF" ]; then
	    printf "Błędny test $i\n";
    fi
    if [ "$flag" = "-v" ]; then
	    DIFF=$(diff ${i::-3}.err out.err)
	    if [ "$DIFF" ]; then
		    printf "Błędny test $i\n";
	    fi
    fi
    rm s_out.out
    rm out.err
done
