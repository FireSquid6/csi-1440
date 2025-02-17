#ifndef LAB_ARRAY_H
#define LAB_ARRAY_H

class LabArray {
protected:
  int *data;
  int size, capacity;

public:
  virtual int getVal(int) = 0;
  virtual int getCapacity() = 0;
  virtual int getSize() = 0;
  virtual void insertVal(int) = 0;
  virtual int removeVal() = 0;


};

#endif
