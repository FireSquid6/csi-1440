#include "proj3-MyString.h"
#include <cstring>

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
  const int CHUNK_SIZE = 32;
  char chunk[CHUNK_SIZE];
  size = 0;
  bool keepReading = true;

  while (keepReading && is.getline(chunk, CHUNK_SIZE, delimit)) {
    int chunkLen = strlen(chunk);
    ensureCanHold(size + chunkLen);
    strcpy(data + size, chunk);
    size += chunkLen;

    keepReading = !is.eof() && (is.fail() ? (is.clear(), true) : false);
  }
}

int MyString::length() const { return size; }

ostream &operator<<(ostream &os, MyString &str) {
  os << str.data << endl;
  return os;
}
