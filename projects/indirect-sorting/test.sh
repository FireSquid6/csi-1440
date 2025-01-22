#!/usr/bin/env bash

echo "COMPILING..."
g++ test.cpp person.cpp -Wall -o main.o
echo "TESTING..."
./main.o
