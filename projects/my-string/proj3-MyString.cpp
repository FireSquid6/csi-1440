#include "proj3-MyString.h"
#include <cstring>

void MyString::ensureCanHold(int max) {
  if (max <= capacity)
    return;

  int newCapacity = capacity;
  while (newCapacity <= max) {
    newCapacity *= 2;
  }

  char *newData = new char[newCapacity];
  strcpy(data, newData);
  delete[] data;
  data = newData;

  capacity = newCapacity;
}

MyString::MyString() {
  size = 0;
  capacity = 10;
  data = new char[capacity];
  data = nullptr;
}

MyString::MyString(const char *str) {
  size = 0;
  capacity = 10;
  data = new char[capacity];

  size = strlen(str);
  ensureCanHold(size);
  strcpy(data, str);
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

char &MyString::operator[](int index) {
  return data[index];
}

void MyString::operator+=(const MyString &other) {
  if (other.data == nullptr) {
    return;
  }

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

void MyString::getline(istream &is, char delimit = '\n') {
  const int CHUNK_SIZE = 32;
  char chunk[CHUNK_SIZE];
  size = 0;

  while (is.getline(chunk, CHUNK_SIZE, delimit)) {
    int length = strlen(chunk);
    size += length;
    ensureCanHold(size);
    strcat(data, chunk);
  }
}

int MyString::length() const { return size; }

ostream &operator<<(ostream &os, MyString &str) {
  if (str.data != nullptr) {
    os << str.data;
  }
  return os;
}
