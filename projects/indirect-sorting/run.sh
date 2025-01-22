#!/usr/bin/env bash

echo "COMPILING..."
g++ testmain.cpp main.cpp person.cpp -Wall -o main.o
echo "RUNNING..."
./main.o
