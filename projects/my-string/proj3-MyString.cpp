/**
 * file: proj3-MyString.cpp
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: Project 3
 * due date: 02/15/2025
 *
 * date modified: 02/14/2025
 * - file created
 *
*/

#include "proj3-MyString.h"

// not allowed to use cstring functions so I just made them myself
int strlen(const char *str) {
  int size = 0;

  while (str[size] != '\0') {
    size += 1;
  }

  return size;
}

char *strcpy(char *dest, const char *src) {
  int i = 0;

  while (src[i] != '\0') {
    dest[i] = src[i];
    i += 1;
  }

  dest[i] = '\0';
  return dest;
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

void MyString::ensureCanHold(int max) {
  if (max <= capacity) {
    return;
  }

  int newCapacity = capacity;
  while (newCapacity <= max) {
    newCapacity *= 2;
  }

  char *newData = new char[newCapacity];
  int i = 0;
  int originalSize = strlen(data);
  for (i = 0; i < originalSize; i++) {
    newData[i] = data[i];
  }
  newData[i] = '\0';

  delete[] data;
  data = newData;

  capacity = newCapacity;
}

MyString::MyString() {
  size = 0;
  capacity = 10;
  data = new char[capacity];
  data[0] = '\0';
}

MyString::MyString(const char *str) {
  size = 0;
  capacity = 10;
  data = new char[capacity];

  size = strlen(str);
  ensureCanHold(size + 1);
  int i;
  for (i = 0; i < size; i++) {
    data[i] = str[i];
  }
  data[i] = '\0';
}

MyString::~MyString() { delete[] data; }

MyString::MyString(const MyString &other) {
  capacity = 10;
  data = new char[capacity];
  size = other.size;
  ensureCanHold(size);

  strcpy(data, other.data);
}

MyString &MyString::operator=(const MyString &other) {
  size = other.size;
  ensureCanHold(size);
  strcpy(data, other.data);

  return *this;
}

bool MyString::operator==(const MyString &other) const {
  if (size != other.size)
    return false;
  return strcmp(data, other.data) == 0;
}

char &MyString::operator[](int index) { return data[index]; }

void MyString::operator+=(const MyString &other) {
  int newSize = size + other.size;
  ensureCanHold(newSize);
  strcat(data, other.data);
  size = newSize;
}

MyString MyString::operator+(const MyString &other) const {
  MyString result(*this);
  result += other;
  return result;
}

const int CHUNK_SIZE = 32;

void MyString::getline(istream &is, char delimit) {
  delete[] data;
  capacity = 10;
  size = 0;
  data = new char[capacity];
  char c;

  while (is.get(c) && c != delimit) {
    ensureCanHold(size + 1);
    data[size] = c;
    size++;
  }
  ensureCanHold(size + 1);
}

int MyString::length() const { return size; }

ostream &operator<<(ostream &os, MyString &str) {
  os << str.data;
  return os;
}
