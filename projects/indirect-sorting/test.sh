#!/usr/bin/env bash

echo "COMPILING..."
g++ proj1-testmain.cpp proj1-person.cpp -Wall -g -o test.o
echo "TESTING..."
./main.o
