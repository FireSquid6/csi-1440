/**
 * file: proj8-bFileSort.cpp
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: Binary File Sort
 * due date: 4/13/2025
 *
 *
 * date modified: 3/23/2025
 * - create the file
 *
 * Contains the completed main function to add
 * a number to a sorted file
 *
 */

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  const string FILENAME = "sortedInts";
  int newValue;

  cout << "Enter an integer to insert: ";
  cin >> newValue;

  fstream file(FILENAME, ios::in | ios::out | ios::binary);

  if (!file.is_open()) {
    cout << "File does not exist" << endl;
    return 0;
  }

  file.seekg(0, ios::end);
  int fileSize = file.tellg();
  int numInts = fileSize / sizeof(int);

  // edge case if the file is empty
  // it was easier just to handle here honestly
  if (numInts == 0) {
    file.clear();
    file.seekp(0, ios::beg);
    file.write(reinterpret_cast<const char *>(&newValue), sizeof(int));

    cout << "File was empty. Added value: " << newValue << endl;

    cout << "Current contents of the file: " << newValue << endl;
    file.close();
    return 0;
  }

  int lastValue;
  file.seekg(-static_cast<int>(sizeof(int)), ios::end);
  file.read(reinterpret_cast<char *>(&lastValue), sizeof(int));

  // If the new value is greater or equal to the last value, append it
  if (lastValue <= newValue) {
    file.clear();
    file.seekp(0, ios::end);
    file.write(reinterpret_cast<const char *>(&newValue), sizeof(int));
  // otherwise we need to find an insert position
  } else {
    int pos = numInts - 1;
    int currValue;

    // Find the insert position
    while (pos >= 0 && currValue > newValue) {
      file.seekg(pos * sizeof(int), ios::beg);
      file.read(reinterpret_cast<char *>(&currValue), sizeof(int));

      pos--;
    }

    int insertPos = (pos + 1) * sizeof(int);

    // Move each value that is > newValue up one position
    for (int i = numInts - 1; i > pos; i--) {
      file.seekg(i * sizeof(int), ios::beg);
      file.read(reinterpret_cast<char *>(&currValue), sizeof(int));

      file.seekp((i + 1) * sizeof(int), ios::beg);
      file.write(reinterpret_cast<const char *>(&currValue), sizeof(int));
    }

    // insert the number in
    file.seekp(insertPos, ios::beg);
    file.write(reinterpret_cast<const char *>(&newValue), sizeof(int));
  }

  file.close();

  // Reopen to print all values
  ifstream readFile(FILENAME, ios::binary);
  int value;

  cout << "Current contents of the file: ";
  while (readFile.read(reinterpret_cast<char *>(&value), sizeof(int))) {
    cout << value << " ";
  }
  cout << endl;

  return 0;
}
