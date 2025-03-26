#!/usr/bin/env bash


echo "COMPILING..."
g++ ./main.cpp -Wall -g -o main.o
echo "RUNNING..."
./main.o
