#include "proj4-ItemInfo.h"

using namespace std;

// please just let us use these I'm tired of writing them every time
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

char *strcat(char *dest, const char *src) {
  int i = 0;
  int j = 0;
  while (dest[i] != '\0') {
    i++;
  }

  while (src[j] != '\0') {
    dest[i] = src[j];
    j++;
    i++;
  }

  dest[i] = '\0';

  return dest;
}

int strcmp(const char *s1, const char *s2) {
  int i = 0;

  while (s1[i] != '\0' && s2[i] != '\0') {
    int diff = s1[i] - s2[i];
    if (diff != 0) {
      return diff;
    }
    i += 1;
  }

  return 0;
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
  double n = 0;
  int i = 0;
  bool isNegative = false;
  bool inDecimal = false;

  if (s[i] == '-') {
    isNegative = true;
    i++;
  }

  while ((s[i] >= '0' && s[i] <= '9') || s[i] == '.') {
    if (s[i] == '.') {
      inDecimal = false;
    } else {
      if (inDecimal) {

      } else {
        n = n * 10 + (s[i] - '0');
      }
    }
  }
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

ItemInfoArray::ItemInfoArray() {}
ItemInfoArray::ItemInfoArray(const ItemInfoArray &) {}
ItemInfoArray::~ItemInfoArray() {}
ItemInfoArray &ItemInfoArray::operator=(const ItemInfoArray &) {}

ItemInfo& ItemInfoArray::at(int i) {}

int ItemInfoArray::getSize() {
  return size;
}

void ItemInfoArray::push(ItemInfo &item) {

  
}

ItemInfo ItemInfoArray::pop() {
  ItemInfo info = ItemInfo(data[size - 1]);

  size--;
  return info;
}
