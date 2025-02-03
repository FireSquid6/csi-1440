#include "proj3-MyString.h"
#include <cmath>
#include <cstring>

// TODO - size is not being updated when it changes
MyString::MyString() {
  capacity = 10;
  size = 0;
  data = new char[capacity];
}

MyString::MyString(const MyString& other) {
  capacity = 0;
  size = 0;
  data = new char[0];
  
  ensureCanHold(other.size);
  size = other.size;
  strcpy(data, other.data);
}

MyString::~MyString() { delete[] data; }

// iterate until \0
MyString::MyString(const char *chars) {
  capacity = 0;
  data = new char[capacity];
  size = strlen(chars);

  ensureCanHold(size);
  strcpy(data, chars);
}

MyString &MyString::operator=(const MyString &other) {
  // TODO - is this correct?
  MyString *newStr = new MyString;
  newStr->ensureCanHold(other.size);
  strcpy(newStr->data, other.data);

  return *newStr;
}

bool MyString::operator==(const MyString &other) const {
  // shortcut since they can't be equal with different sizes
  if (size != other.size) {
    return false;
  }
  
  for (int i = 0; i < size; i++) {
    if (data[i] != other.data[i]) {
      return false;
    }
  }

  return true;
}
void MyString::operator+=(const MyString &other) {
  ensureCanHold(length() + other.length());
  strcat(data, other.data);
}

MyString &MyString::operator+(const MyString & other) const {
  int newLength = length() + other.length();

  MyString *newStr;
  newStr->ensureCanHold(newLength);
  strcat(newStr->data, data);
  strcat(newStr->data, other.data);
  
  return *newStr;
}

char &MyString::operator[](int i) const {
  if (i > length()) {
    throw "Tried to access a string past its length";
  }

  return data[i];
}

int MyString::length() const { return size; }
ostream &operator<<(ostream &os, MyString &str) {}

void MyString::ensureCanHold(int newSize) {
  if (capacity >= newSize) {
    return;
  }

  int newCapacity = capacity;

  // I'm pretty sure this is faster than
  // doing the math with logs
  //
  // honestly it doesn't really matter that
  // much since in the grand scheme of things
  // we are copying stuff in memory and that's
  // going to be the bottleneck every time
  while (newCapacity < newSize) {
    newCapacity *= 2;
  }

  char *newData = new char[newCapacity];
  strcpy(data, newData);
  delete[] data;
  data = newData;

  capacity = newCapacity;
}
void MyString::getline(istream&, char delimit = '\n') {

}
