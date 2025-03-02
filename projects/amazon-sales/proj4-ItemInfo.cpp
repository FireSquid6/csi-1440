/**
 * file: proj4-ItemInfo.cpp
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: project 4
 * due date: 03/02/2025
 *
 * date modified:  03/02/2025
 *    - file created
 *
 * Provide4s the implementation for ItemInfo
 */
#include "proj4-ItemInfo.h"
#include <cmath>

// this is needed since the format function expects the id to be printed
// without decimal places. I would like for the double printing function
// to always include .00 since it makes it clear that it's a double
//
// this will fail to handle negative numbers
void intToStr(char *cstr, int n) {
  // edge case
  if (n == 0) {
    cstr[0] = '0';
    cstr[1] = '\0';
    return;
  }


  int temp = n;
  int length = 0;
  int i = 0;
  while (temp > 0) {
    length++;
    temp /= 10;
  }

  int end = i + length;

  cstr[end] = '\0';

  while (n > 0) {
    cstr[--end] = '0' + (n % 10);
    n /= 10;
  }
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

void ItemInfo::setItemId(const char *num) { 
  itemId = stuCstrToDbl(num); 
}

void ItemInfo::setDescription(const char *cstr) {
  stuCstrCpy(description, cstr);
}

void ItemInfo::setManCost(const char *num) { 
  manCost = stuCstrToDbl(num); 
}

void ItemInfo::setSellPrice(const char *num) { 
  sellPrice = stuCstrToDbl(num); 
}

double ItemInfo::getSellPrice() { 
  return sellPrice; 
}

int ItemInfo::getItemId() {
  return itemId;
}

double ItemInfo::getManCost() {
  return manCost;
}

const char* ItemInfo::getDescription() {
  return description;
}

// only does the inner object. Outer object and {} has
// to be handled by something else because the
// amazon """JSON""" spec isn't actually JSON and
// arrays require "firstItem", "secondItem", etc.
void ItemInfo::toAmazonJSON(ostream &out) {
  char itemIdString[20];
  char manCostStr[20];
  char sellPriceStr[20];

  intToStr(itemIdString, itemId);
  stuDblToCstr(manCostStr, manCost);
  stuDblToCstr(sellPriceStr, sellPrice);

  printCString(out, "\t\t\"itemId:\" ");
  printCString(out, itemIdString);
  printCString(out, ",\n");

  printCString(out, "\t\t\"description:\" \"");
  printCString(out, description);
  printCString(out, "\",\n");

  // it's manPrice in the JSON spec despite being 
  // manCost everywhere else. I don't make the rules.
  printCString(out, "\t\t\"manPrice:\" ");
  printCString(out, manCostStr);
  printCString(out, ",\n");

  printCString(out, "\t\t\"sellPrice:\" ");
  printCString(out, sellPriceStr);
  printCString(out, "\n");
}

void ItemInfo::displayItemInfo(ostream &out) {
  // numbers will never be longer than this
  char itemIdString[20];
  char manCostStr[20];
  char sellPriceStr[20];
  char profitStr[20];

  intToStr(itemIdString, itemId);
  stuDblToCstr(manCostStr, manCost);
  stuDblToCstr(sellPriceStr, sellPrice);
  stuDblToCstr(profitStr, calcProfit());

  printCString(out, "itemId: ");
  printCString(out, itemIdString);
  out.put('\n');

  printCString(out, "description: ");
  printCString(out, description);
  out.put('\n');

  printCString(out, "manCost: ");
  printCString(out, manCostStr);
  out.put('\n');

  printCString(out, "sellPrice: ");
  printCString(out, sellPriceStr);
  out.put('\n');

  printCString(out, "calculatedProfit: ");
  printCString(out, profitStr);
  out.put('\n');
}

double ItemInfo::calcProfit() { 
  return sellPrice - manCost; 
}
