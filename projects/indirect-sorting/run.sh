#!/usr/bin/env bash

echo "COMPILING..."
g++ proj1-main.cpp proj1-person.cpp -Wall -g -o main.o
echo "RUNNING..."
./main.o
