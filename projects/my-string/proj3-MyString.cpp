#include "proj3-MyString.h"
#include <cstring>

void MyString::ensureCanHold(int max) {
  if (max <= capacity)
    return;

  int newCapacity = capacity;
  if (newCapacity == 0) {
    newCapacity = 10;
  }
  while (newCapacity <= max) {
    newCapacity *= 2;
  }

  char *newData = new char[newCapacity];
  if (data != nullptr) {
    strcpy(newData, data);
    delete[] data;
  }

  data = newData;
  capacity = newCapacity;
}

MyString::MyString() {
  size = 0;
  capacity = 0;
  data = nullptr;
}

MyString::MyString(const char *str) {
  size = 0;
  capacity = 0;
  data = nullptr;

  size = strlen(str);
  ensureCanHold(size);
  strcpy(data, str);
}

MyString::~MyString() { delete[] data; }

MyString::MyString(const MyString &other) {
  capacity = 0;
  data = nullptr;

  size = other.size;
  ensureCanHold(size);
  if (other.data != nullptr) {
    strcpy(data, other.data);
  }
}

MyString &MyString::operator=(const MyString &other) {
  size = other.size;
  ensureCanHold(size);
  if (other.data != nullptr) {
    strcpy(data, other.data);
  }

  return *this;
}

bool MyString::operator==(const MyString &other) const {
  if (size != other.size)
    return false;
  if (data == nullptr && other.data == nullptr)
    return true;
  if (data == nullptr || other.data == nullptr)
    return false;
  return strcmp(data, other.data) == 0;
}

char &MyString::operator[](int index) {
  if (index < 0 || index >= size) {
    throw std::out_of_range("Index out of bounds");
  }
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
    int chunkLen = strlen(chunk);
    ensureCanHold(size + chunkLen);
    strcpy(data + size, chunk);
    size += chunkLen;

    if (is.eof())
      break;
    if (is.fail()) {
      is.clear(); // Clear fail bit
      continue;   // Continue reading
    }
    break; // Delimiter found
  }
}

int MyString::length() const { return size; }

ostream &operator<<(ostream &os, MyString &str) {
  if (str.data != nullptr) {
    os << str.data;
  }
  return os;
}
