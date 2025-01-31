/**
 * file: proj2-arrayFunctions.cpp
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: project 2
 * due date: 2/2/2025
 *
 * date modified: 1/30/2025
 * - create the file
 *
 * Contains the implementation for various integer array utilities
 *
 */
#include "proj2-arrayFunctions.h"
#include <iostream>

using namespace std;

/**
 * bubbleSort
 *
 * sorts the array by the bubble sort (O(n^2)) method
 *
 * Parameters:
 * array - the array to sort
 * size - the size of the array
 *
 * Output:
 * return: void
 */
void bubbleSort(int *array, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(array[j], array[j + 1]);
      }
    }
  }
}

/**
 * largestValue
 *
 * gets the maximum in an array 
 *
 * Parameters:
 * array - the array to find the max of
 * size - the size of the array
 *
 * Output:
 * return: int maximum
 */
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

/**
 * smallestValue
 *
 * finds the minimum of an array
 *
 * Parameters:
 * array - the array to find the min of
 * size - the size of the array
 *
 * Output:
 * return: int minimum
 */
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

/**
 * averageValue
 *
 * finds the mean of an array
 *
 * Parameters:
 * array - the array to find the average of
 * size - the size of the array
 *
 * Output:
 * return: the average value
 */
double averageValue(int *array, int size) {
  double total = 0;

  for (int i = 0; i < size; i++) {
    total += array[i];
  }

  return total / size;
}

/**
 * medianValue
 *
 * returns the median value of an ALREADY SORTED array
 *
 * Parameters:
 * array - the array to find the median of
 * size - the size of the array
 *
 * Output:
 * return: median of the array
 */
int medianValue(int *array, int size) { 
  int index = (size - 1) / 2;
  return array[index];
}
