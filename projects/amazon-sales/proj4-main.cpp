#include "proj4-ItemInfo.h"
#include <fstream>
#include <iostream>

// only works for 40 characters
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

// assumes no part is longer than 40 chars
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

  // TODO - sort the array

  // add the first bit of the JSON
  printCString(cout, "\"DeissStore\": [\n");

  for (int i = 0 ; i < 5; i++) {
    printCString(cout, "\t\"");
    printCString(cout, ordinalItems[i]);
    printCString(cout, "\": {\n");
    array[i].toAmazonJSON(cout);

    printCString(cout, "\t}");

    // JSON doesn't support trailing commas. Even though it probably
    // isn't a big deal if I put them there since we're not actually
    // outputting JSON but a gross molestation of a pretty good format
    // I'll still make sure to check and not put trailing commas in
    // the spirit of JSON
    if (i != 4) {
      cout.put(',');
    }
    cout.put('\n');
  }

  // output the last ] of the JSON
  // (even though this isn't how JSON works)
  cout.put(']');
  cout.put('\n');

  return 0;
}
