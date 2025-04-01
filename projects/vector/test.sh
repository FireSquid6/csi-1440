#!/usr/bin/env bash


echo "COMPILING..."
g++ proj7-TestMain.cpp -Wall -g -o test.o
echo "TESTING..."
./test.o
