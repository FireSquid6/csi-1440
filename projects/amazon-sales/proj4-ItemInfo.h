/**
 * file: proj4-ItemInfo.hpp
 * author: Prof. Aars
 * course: CSI 1440
 * assignment: project 4
 * due date: 2/7/2018
 *
 * date modified:  1/28/2018
 *    - file created
 *
 * This class provides a container for products contained in a produce service
 * dump.
 */

#ifndef ITEMINFO_H
#define ITEMINFO_H

#include <iomanip>
#include <iostream>

using namespace std;

class ItemInfo {
private:
  int itemId;
  char description[40];
  double manCost;
  double sellPrice;

public:
  ItemInfo();

  void setItemId(const char *num);

  void setDescription(const char *cstr);

  void setManCost(const char *num);

  void setSellPrice(const char *num);

  int getItemId();

  const char *getDescription();

  double getManCost();

  double getSellPrice();

  void toAmazonJSON(ostream &out);

  void displayItemInfo(ostream &out);

  double calcProfit();
};

class ItemInfoArray {
private:
  void resizeTo(int);
  int size;
  int capacity;
  ItemInfo* data;

public:
  ItemInfoArray();
  ItemInfoArray(const ItemInfoArray &);
  ~ItemInfoArray();
  ItemInfoArray &operator=(const ItemInfoArray &);

  ItemInfo& at(int i);
  int getSize();
  void push(ItemInfo item);
  ItemInfo pop();
};

double strToDouble(const char *num);

void dblToStr(char *cstr, double num);

void strcpy(char *dest, const char *src);

int strlen(const char *src);

ostream &printStr(ostream &out, const char *src);

#endif
