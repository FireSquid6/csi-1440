#!/usr/bin/env bash


echo "COMPILING..."
g++ proj7-TestMain.cpp -Wall -g -o main.o
echo "TESTING..."
./main.o
