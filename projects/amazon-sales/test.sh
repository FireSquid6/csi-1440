#!/usr/bin/env bash

echo "COMPILING..."
g++ ./proj4-ItemInfo.cpp ./proj4-testmain.cpp -Wall -g -o test.o
echo "TESTING..."
./test.o
