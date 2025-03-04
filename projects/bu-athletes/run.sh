#!/usr/bin/env bash


echo "COMPILING..."
g++ proj5-NCAAAthlete.cpp proj5-BUAthlete.cpp proj5-BUAthleteList.cpp proj5-main.cpp -Wall -g -o main.o
echo "RUNNING..."
./main.o
