#!/usr/bin/env bash

echo "COMPILING..."
g++ test.cpp person.cpp -Wall -g -o test.o
echo "TESTING..."
./main.o
