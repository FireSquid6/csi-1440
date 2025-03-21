/**
 * file: proj2-testmain.cpp 
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: project 2
 * due date: 2/2/2025
 *
 * date modified: 1/30/2025
 * - create the file
 *
 * tests the array functions file
 *
 */
#include "proj2-arrayFunctions.h"
#include <cassert>
#include <iostream>

using namespace std;

// not gonna do function comments in this file because I don't wanna
// and it's redundant anyways
//
// we also aren't testing if a negative or incorrect size is inputted.
// if I were programming this "for real" those cases would throw an
// exception (or return some sort of option monad in a language that
// supports that), but I don't think we've covered exceptions or error
// handling in C++

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void testBubbleSort() {
  cout << "Testing bubbleSort..." << endl;

  int arr1[] = {64, 34, 25, 12, 22, 11, 90};
  int size1 = 7;
  bubbleSort(arr1, size1);
  assert(arr1[0] == 11 && arr1[6] == 90);
  cout << "Test case 1 passed: Regular array" << endl;

  int arr2[] = {1, 2, 3, 4, 5};
  int size2 = 5;
  bubbleSort(arr2, size2);
  assert(arr2[0] == 1 && arr2[4] == 5);
  cout << "Test case 2 passed: Already sorted array" << endl;

  int arr3[] = {3, 1, 3, 2, 1};
  int size3 = 5;
  bubbleSort(arr3, size3);
  assert(arr3[0] == 1 && arr3[4] == 3);
  cout << "Test case 3 passed: Array with duplicates" << endl;
}

void testLargestValue() {
  cout << "\nTesting largestValue..." << endl;

  int arr1[] = {64, 34, 25, 12, 22, 11, 90};
  assert(largestValue(arr1, 7) == 90);
  cout << "Test case 1 passed: Regular array" << endl;

  int arr2[] = {1, 1, 1, 1};
  assert(largestValue(arr2, 4) == 1);
  cout << "Test case 2 passed: Array with same values" << endl;

  int arr3[] = {-5, -2, -10, -1};
  assert(largestValue(arr3, 4) == -1);
  cout << "Test case 3 passed: Array with negative numbers" << endl;
}

void testSmallestValue() {
  cout << "\nTesting smallestValue..." << endl;

  int arr1[] = {64, 34, 25, 12, 22, 11, 90};
  assert(smallestValue(arr1, 7) == 11);
  cout << "Test case 1 passed: Regular array" << endl;

  int arr2[] = {1, 1, 1, 1};
  assert(smallestValue(arr2, 4) == 1);
  cout << "Test case 2 passed: Array with same values" << endl;

  int arr3[] = {-5, -2, -10, -1};
  assert(smallestValue(arr3, 4) == -10);
  cout << "Test case 3 passed: Array with negative numbers" << endl;
}

void testAverageValue() {
  cout << "\nTesting averageValue..." << endl;

  int arr1[] = {2, 4, 6, 8, 10};
  assert(averageValue(arr1, 5) == 6.0);
  cout << "Test case 1 passed: Even numbers" << endl;

  int arr2[] = {1, 2, 3};
  assert(averageValue(arr2, 3) == 2.0);
  cout << "Test case 2 passed: Small array" << endl;

  int arr3[] = {-2, 0, 2};
  assert(averageValue(arr3, 3) == 0.0);
  cout << "Test case 3 passed: Array with negative numbers" << endl;
}

void testMedianValue() {
  cout << "\nTesting medianValue..." << endl;

  int arr1[] = {1, 3, 5, 7, 9};
  assert(medianValue(arr1, 5) == 5);
  cout << "Test case 1 passed: Odd-sized array" << endl;

  int arr2[] = {1, 2, 3, 4};
  assert(medianValue(arr2, 4) == 2); // Should return smaller of middle values
  cout << "Test case 2 passed: Even-sized array" << endl;

  int arr3[] = {5};
  assert(medianValue(arr3, 1) == 5);
  cout << "Test case 3 passed: Single element array" << endl;
}

int main() {
  cout << "Starting array functions test suite..." << endl;

  testBubbleSort();
  testLargestValue();
  testSmallestValue();
  testAverageValue();
  testMedianValue();

  cout << "\nAll tests passed successfully!" << endl;
  return 0;
}
