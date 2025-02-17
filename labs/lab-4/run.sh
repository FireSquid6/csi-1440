#!/usr/bin/env bash

echo "COMPILING..."
g++ lab4-testmain.cpp lab4-IntArray.cpp -Wall -g -o main.o
echo "RUNNING..."
./main.o
