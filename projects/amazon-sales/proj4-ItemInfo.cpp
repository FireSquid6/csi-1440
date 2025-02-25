#include "proj4-ItemInfo.h"
#include <cmath>

int strToInt(const char *cstr) {
  int n = 0;
  int i = 0;
  int multiplier = 1;

  while (cstr[i] != '\0') {
    i += 1;
  }
  i -= 1;

  while (i >= 0) {
    n += (cstr[i] - '0') * multiplier;
    multiplier *= 10;

    i -= 1;
  }

  return n;
}

ostream &printCString(ostream &out, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    out.put(src[i]);
    i += 1;
  }

  return out;
}

int stuCstrLen(const char *src) {
  int i = 0;

  while (src[i] != '\0') {
    i += 1;
  }

  return i;
}

void stuCstrCpy(char *dest, const char *src) {
  int i = 0;

  while (src[i] != '\0') {
    dest[i] = src[i];
    i += 1;
  }

  dest[i] = '\0';
}

void stuDblToCstr(char *cstr, double num) {
  int intPart = (int)num;
  double fractPart = num - intPart;

  fractPart = round(fractPart * 100) / 100.0;

  char intStr[20];
  int intIdx = 0;

  if (intPart == 0) {
    intStr[intIdx] = '0';
    intIdx += 1;
  } else {
    while (intPart > 0) {
      intStr[intIdx] = '0' + (intPart % 10);
      intIdx += 1;
      intPart /= 10;
    }
  }

  int cstrIdx = 0;
  for (int i = intIdx - 1; i >= 0; i--) {
    cstr[cstrIdx++] = intStr[i];
  }

  int afterDecimal = round(fractPart * 100);

  cstr[cstrIdx] = '.';
  cstr[cstrIdx + 1] = '0' + (afterDecimal / 10);
  cstr[cstrIdx + 2] = '0' + (afterDecimal % 10);
  cstr[cstrIdx + 3] = '\0';
}

double stuCstrToDbl(const char *num) {
  double result = 0.0;
  int i = 0;
  double decimalPlace = 0.0;
  bool hasDecimal = false;
  
  while (num[i] != '\0') {
    if (num[i] >= '0' && num[i] <= '9') {
      if (!hasDecimal) {
        result = result * 10.0 + (num[i] - '0');
      } else {
        decimalPlace *= 0.1;
        result += (num[i] - '0') * decimalPlace;
      }
    } else if (num[i] == '.') {
      hasDecimal = true;
      decimalPlace = 1.0;
    }
    i++;
  }
  
  return result;
}

ItemInfo::ItemInfo() {
  itemId = 0;
  *description = '\0';
  manCost = 0.0;
  sellPrice = 0.0;
}

void ItemInfo::setItemId(const char *num) { itemId = strToInt(num); }

void ItemInfo::setDescription(const char *cstr) {
  stuCstrCpy(description, cstr);
}

void ItemInfo::setManCost(const char *num) { manCost = stuCstrToDbl(num); }

void ItemInfo::setSellPrice(const char *num) { sellPrice = stuCstrToDbl(num); }

double ItemInfo::getSellPrice() { return sellPrice; }

void ItemInfo::toAmazonJSON(ostream &out) {}

void ItemInfo::displayItemInfo(ostream &out) {}

double ItemInfo::calcProfit() { return sellPrice - manCost; }
