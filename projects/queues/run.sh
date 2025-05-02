#!/usr/bin/env bash


echo "COMPILING..."
g++ ./proj10-driver.cpp -Wall -g -o main.o
echo "RUNNING..."
./main.o
