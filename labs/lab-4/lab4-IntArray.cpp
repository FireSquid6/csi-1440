#include "lab4-IntArray.h"

void IntArray::resizeTo(int newCapacity) {
  int *newData = new int[newCapacity];

  for (int i = 0; i < size; i++) {
    newData[i] = data[i];
  }

  capacity = newCapacity;
  delete[] data;

  data = newData;
}

IntArray::IntArray() {
  capacity = 5;
  size = 0;
  data = new int[capacity];
}

IntArray::~IntArray() { delete[] data; }

IntArray::IntArray(const IntArray &other) {
  capacity = other.capacity;
  size = other.size;
  data = new int[capacity];

  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
}

IntArray &IntArray::operator=(const IntArray &rhs) {
  IntArray *array = new IntArray(rhs);
  return *array;
}

int IntArray::getVal(int i) { return data[i]; }

int IntArray::getCapacity() { return capacity; }

int IntArray::getSize() { return size; }

void IntArray::insertVal(int val) {
  if (size >= capacity) {
    resizeTo(capacity * 2);
  }

  data[size] = val;
  size += 1;
}

// not in original spec but I added it for testing purposes
void IntArray::setVal(int val, int i) { data[i] = val; }

// this will break and create awful bugs if size == 0!
int IntArray::removeVal() {
  int val = data[size - 1];
  size--;

  // never resize below 5
  if (size * 4 < capacity && capacity > 5) {
    resizeTo(capacity / 2);
  }

  return val;
}

void IntArray::output(ostream &o) {
  for (int i = 0; i < size; i++) {
    o << data[i] << " ";
  }
  o << endl;
}
