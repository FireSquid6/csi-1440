#!/usr/bin/env bash

echo "COMPILING..."
g++ proj5-NCAAAthlete.cpp proj5-BUAthlete.cpp proj5-BUAthleteList.cpp proj5-testmain.cpp -Wall -g -o test.o
echo "TESTING..."
./test.o
