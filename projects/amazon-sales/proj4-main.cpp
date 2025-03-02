/**
 * file: proj4-main.cpp
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: project 4
 * due date: 03/02/2025
 *
 * date modified:  03/02/2025
 *    - file created
 *
 * The main program that sorts a csv file
 */
#include "proj4-ItemInfo.h"
#include <fstream>
#include <iostream>

// only works for 40 characters. The description of ItemInfo makes this
// assumption as well so I think it's a fair one
void customGetline(char *buffer, char *line, int *bufferPosition,
                    char delimit) {
  int i = 0;
  while (buffer[*bufferPosition] != delimit && buffer[*bufferPosition] != '\0') {
    line[i] = buffer[*bufferPosition];
    *bufferPosition += 1;
    i += 1;
  }
  
  *bufferPosition += 1;
  line[i] = '\0';
}

ItemInfo* resizeItemInfoArray(ItemInfo* original, int size, int newCapacity) {
  ItemInfo* newArray = new ItemInfo[newCapacity];

  for (int i = 0; i < size; i++) {
    newArray[i] = original[i];
  }

  delete[] original;
  return newArray;
}

void sortByProft(ItemInfo* array, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j].calcProfit() < array[j + 1].calcProfit()) {
        swap(array[j], array[j + 1]);
      }
    }
  }
}

int main() {
  ifstream file;
  file.open("proj4-productServices.csv");

  char buffer[500];
  int i = 0;
  char c;

  int capacity = 2;
  int size = 0;
  ItemInfo* array = new ItemInfo[capacity];

  const char* const ordinalItems[] = {"firstItem", "secondItem", "thirdItem", "fourthItem", "fifthItem"};

  while (file.get(c)) {
    buffer[i] = c;
    i += 1;

    if (c == '\n') {
      buffer[i] = '\0';
      int bufferPosition = 0;
      char id[40];
      char description[40];
      char manCost[40];
      char sellCost[40];

      customGetline(buffer, id, &bufferPosition, ',');
      customGetline(buffer, description, &bufferPosition, ',');
      customGetline(buffer, manCost, &bufferPosition, ',');
      customGetline(buffer, sellCost, &bufferPosition, ',');

      ItemInfo info = ItemInfo();
      info.setItemId(id);
      info.setDescription(description);
      info.setManCost(manCost);
      info.setSellPrice(sellCost);

      if (size == capacity) {
        capacity += 2;
        array = resizeItemInfoArray(array, size, capacity);
      }

      array[size] = info;
      size += 1;
      i = 0;
    }
  }

  file.close();

  sortByProft(array, size);


  // add the first bit of the JSON
  printCString(cout, "\"DeissStore\": [\n");

  for (int i = 0 ; i < 5; i++) {
    printCString(cout, "\t\"");
    printCString(cout, ordinalItems[i]);
    printCString(cout, "\": {\n");
    array[i].toAmazonJSON(cout);

    printCString(cout, "\t}");

    // no trailing commas on the last one
    if (i != 4) {
      cout.put(',');
    }
    cout.put('\n');
  }

  // output the last ] of the JSON
  cout.put(']');
  cout.put('\n');

  delete[] array;

  return 0;
}
