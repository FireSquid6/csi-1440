#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include "lab4-LabArray.h"
#include <iostream>

using namespace std;

class IntArray : public LabArray {
private:
  void resizeTo(int);
public:
  IntArray();
  ~IntArray();
  IntArray(const IntArray &);

  IntArray &operator=(const IntArray &);

  int getVal(int); // notice loss of virtual and = 0
  int getCapacity();
  int getSize();
  void insertVal(int);
  int removeVal();

  // these functions are useful during testing and debugging
  // not part of the original spec
  void setVal(int val, int i);
  void output(ostream& o);
};

#endif
