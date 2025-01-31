#include "proj2-arrayFunctions.h"
#include <iostream>

using namespace std;

void bubbleSort(int *array, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(array[j], array[j + 1]);
      }
    }
  }
}

int largestValue(int *array, int size) { 
  if (size == 0) {
    return -1;
  }
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  return max;
}

int smallestValue(int *array, int size) { 
  if (size == 0) {
    return -1;
  }
  int min = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }

  return min;
}

double averageValue(int *array, int size) {
  double total = 0;

  for (int i = 0; i < size; i++) {
    total += array[i];
  }

  return total / size;
}

// assumes that the array is already sorted
int medianValue(int *array, int size) { 
  int index = (size - 1) / 2;
  return array[index];
}
