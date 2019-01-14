#!/bin/bash
# Script to run and compile C Files

for i in *.c
do
    echo "gcc -g3 -o3 -c -Wall -lm $i -o ${i%.c}.out"
    gcc -g3 -o3 -c -Wall "$i" -o "${i%.c}.out" -lm
    done
