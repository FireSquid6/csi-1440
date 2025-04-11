#!/usr/bin/env bash

echo "COMPILING..."
g++ generate-sorted-file.cpp -Wall -g -o generator.o
echo "RUNNING..."
./generator.o
