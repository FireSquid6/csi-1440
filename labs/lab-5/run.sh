#!/usr/bin/env bash

if [ -z "$1" ]; then
  echo "Expected first argument"
  exit 1
fi

if [ ! -f "$1.cpp" ]; then
  echo "file not found"
  exit 1
fi

g++ ./"$1".cpp -o "$1".o
./"$1".o

