#include <cmath>
#include "proj4-ItemInfo.h"

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

void intToStr(char *cstr, int n) {}

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
  int n = round(num * 100);
  int divisor = 1;
  int i = 0;
  bool putDecimal = false;

  while (divisor <= n) {
    divisor *= 10;
  }
  divisor /= 10;

  while (n > 0) {
    if (divisor == 100 && putDecimal) {
      int digit = n / divisor;

      n -= digit * divisor;
      divisor /= 10;

      cstr[i] = digit + '0';
    } else {
      cstr[i] = '.';
      putDecimal = true;
    }

    i += 1;
  }
  cstr[i] = '\0';
}

double stuCstrToDbl(const char *num) {
  double n = 0.0;
  int i = 0;
  int multiplier = 1;

  while (num[i] != '\0') {
    i += 1;
  }
  i -= 1;

  while (i >= 0) {
    if (num[i] >= '0' && num[i] <= '9') {
      n += multiplier * (num[i] - '0');
      multiplier *= 10;
    } else if (num[i] == '.') {
      multiplier = 1;
      int divisor = 1;

      while (divisor <= n) {
        divisor *= 10;
      }

      n = divisor / n;
    }

    i -= 1;
  }

  return n;
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
