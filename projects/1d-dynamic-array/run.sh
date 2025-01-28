#!/usr/bin/env bash


echo "COMPILING..."
g++ ./proj2-arrayFunctions.cpp ./proj2-main.cpp -Wall -g -o main.o
echo "RUNNING..."
./main.o
