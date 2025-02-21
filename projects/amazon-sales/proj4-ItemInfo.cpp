#include "proj4-ItemInfo.h"

using namespace std;

// please just let us import these I'm tired of rewriting them every time
int strlen(const char *str) {
  int size = 0;

  while (str[size] != '\0') {
    size += 1;
  }

  return size;
}

void strcpy(char *dest, const char *src) {
  int i = 0;

  while (src[i] != '\0') {
    dest[i] = src[i];
    i += 1;
  }

  dest[i] = '\0';
}

int strToInt(const char *s) {
  int n = 0;
  int i = 0;

  bool isNegative = false;
  if (s[i] == '-') {
    isNegative = true;
    i++;
  }

  while (s[i] >= '0' && s[i] <= '9') {
    n = n * 10 + (s[i] - '0');
    i++;
  }

  return isNegative ? -n : n;
}

double strToDouble(const char *s) {
  bool isNegative = false;
  int i = 0;
  double n = 0;

  if (s[i] == '-') {
    isNegative = true;
    i++;
  }

  while (s[i] >= '0' && s[i] <= '9') {
    n = n * 10.0 + (s[i] - '0');
    i++;
  }

  if (s[i] == '.') {
    i++;
    double fraction = 0.0;
    double divisor = 10.0;

    while (s[i] >= '0' && s[i] <= '9') {
      fraction += (s[i] - '0') / divisor;
      divisor *= 10;
      i++;
    }

    n += fraction;
  }

  return isNegative ? n : -n;
}

void dblToStr(char *cstr, double num) {
  int i = 0;

  if (num < 0) {
    cstr[i] = '-';
    i++;
  }

  if (num == 0.0) {}


}

ostream &printStr(ostream &out, const char *src) {
  int i = 0;

  while (src[i] != '\0') {
    out.put(src[i]);
  }

  return out;
}

ItemInfo::ItemInfo() {
  itemId = 0;
  *description = '\0';
  manCost = 0.0;
  sellPrice = 0.0;
}

void ItemInfo::setItemId(const char *num) { itemId = strToInt(num); }

void ItemInfo::setDescription(const char *desc) { strcpy(description, desc); }

void ItemInfo::setManCost(const char *num) { manCost = strToDouble(num); }

void ItemInfo::setSellPrice(const char *num) { sellPrice = strToDouble(num); }

const char *ItemInfo::getDescription() { return description; }

double ItemInfo::getManCost() { return manCost; }

double ItemInfo::getSellPrice() { return sellPrice; }

void ItemInfo::displayItemInfo(ostream &out) {
  out << "itemId: " << itemId << endl;
  out << "description: " << description << endl;
  out << "manCost: " << manCost << endl;
  out << "sellPrice: " << sellPrice << endl;
  out << "calculatedProfit: " << calcProfit() << endl;
  // TODO
}

void ItemInfo::toAmazonJSON(ostream &out) {
  out << '{' << endl << '\t' << '\t';
  out << "itemId: " << itemId << ',';
  out << endl << '\t' << '\t';
  out << "description: " << '"' << description << "\",";
  out << endl << '\t' << '\t';
  out << "manPrice: " << manCost << ',';
  out << endl << '\t' << '\t';
  out << "sellPrice: " << sellPrice;
  out << endl << '\t' << '}' << endl;
}

double ItemInfo::calcProfit() { return sellPrice - manCost; }

ItemInfoArray::ItemInfoArray() {
  size = 0;
  capacity = 2;
  data = new ItemInfo[capacity];
}
ItemInfoArray::ItemInfoArray(const ItemInfoArray &other) {
  capacity = other.capacity;
  size = other.size;
  data = new ItemInfo[capacity];

  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
}

ItemInfoArray::~ItemInfoArray() { delete[] data; }

ItemInfoArray &ItemInfoArray::operator=(const ItemInfoArray &rhs) {
  ItemInfoArray *array = new ItemInfoArray(rhs);
  return *array;
}

void ItemInfoArray::resizeTo(int newCapacity) {
  ItemInfo *newData = new ItemInfo[newCapacity];

  for (int i = 0; i < size; i++) {
    newData[i] = data[i];
  }

  capacity = newCapacity;
  delete[] data;

  data = newData;
}

ItemInfo &ItemInfoArray::at(int i) { return data[i]; }

int ItemInfoArray::getSize() { return size; }

void ItemInfoArray::push(ItemInfo item) {
  if (size >= capacity) {
    resizeTo(capacity + 2);
  }

  data[size] = item;
  size += 1;
}

ItemInfo ItemInfoArray::pop() {
  ItemInfo info = data[size - 1];
  size--;
  

  return info;
}

void ItemInfoArray::sort() {
  // TODO
}
