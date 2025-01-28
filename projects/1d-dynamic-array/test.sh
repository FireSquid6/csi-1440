#!/usr/bin/env bash

echo "COMPILING..."
g++ ./proj2-arrayFunctions.cpp ./proj2-testmain.cpp -Wall -g -o test.o
echo "TESTING..."
./test.o
