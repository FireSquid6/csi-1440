#!/usr/bin/env bash

echo "COMPILING..."
g++ main.cpp person.cpp -Wall -g -o main.o
echo "RUNNING..."
./main.o
