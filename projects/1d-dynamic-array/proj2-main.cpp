/**
 * file: proj2-main.cpp
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: project 2
 * due date: 2/2/2025
 *
 * date modified: 1/30/2025
 * - create the file
 *
 * the main file for parsing a text file of arrays
 *
 */
#include "proj2-arrayFunctions.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;

const string FILENAME = "arrays.txt";

int main() {
  ifstream inFile;
  int size;
  int totalMax = 0;
  int index = 1;
  int totalMin = 0;
  bool setExtrema = false;

  inFile.open(FILENAME);
  
  if (!inFile.is_open()) {
    cout << "Error: file not open" << endl;
    return 0;
  }

  while (inFile >> size) {
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
      int temp;
      inFile >> temp;
      array[i] = temp;
    }

    bubbleSort(array, size);

    int median = medianValue(array, size);
    int average = averageValue(array, size);
    int min = smallestValue(array, size);
    int max = largestValue(array, size);

    if (setExtrema) {
      if (min < totalMin) {
        totalMin = min;
      }
      if (max < totalMax) {
        totalMax = max;
      }
    } else {
      totalMax = max;
      totalMin = min;
    }

    cout << "Array " << index << endl;
    cout << "  Median: " << median << endl;
    cout << "  Mean: " << average << endl;
    cout << "  Max: " << max << endl;
    cout << "  Min: " << min << endl;
    cout << endl;

    delete[] array;
    index += 1;
  }
  cout << "Over all arrays:" << endl;
  cout << "  Max: " << totalMax << endl;
  cout << "  Min: " << totalMin << endl;

  inFile.close();
  return 0;
}
