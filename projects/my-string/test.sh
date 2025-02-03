#!/usr/bin/env bash


echo "COMPILING..."
g++ ./proj3-MyString.cpp ./proj3-testMain.cpp -Wall -g -o main.o
echo "RUNNING..."
./main.o
