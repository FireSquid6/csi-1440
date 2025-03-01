#include "proj4-ItemInfo.h"
#include <fstream>
#include <vector>
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
  vector<ItemInfo> vec;


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

      vec.push_back(info);

      i = 0;
    }
  }

  file.close();


  for (int i = 0 ; i < vec.size(); i++) {
    cout << "ITEM " << i << endl;
    vec.at(i).displayItemInfo(cout);
    cout << endl;
  }

  return 0;
}
