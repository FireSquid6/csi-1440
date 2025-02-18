#!/usr/bin/env bash


echo "COMPILING..."
g++ ./proj4-ItemInfo.cpp ./proj4-main.cpp -Wall -g -o main.o
echo "RUNNING..."
./main.o
