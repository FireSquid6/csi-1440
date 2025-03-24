#include "ContainerIfc.h"
#include <sstream>

template <typename T> class MyArray : public ContainerIfc<T> {
private:
  T *data;
  int capacity, size;

public:
  MyArray();
  MyArray(MyArray<T> &other);
  ~MyArray();

  MyArray<T> &operator=(MyArray<T> &other);

  ContainerIfc<T> &pushBack(T) override;
  ContainerIfc<T> &popBack(T &) override; // throws BADINDEX
  int getSize() override;
  bool isEmpty() override;
  T &operator[](int) override; // throws BADINDEX
  string toString() override;
};

template <typename T>
MyArray<T>::MyArray() {
  capacity = 5;
  size = 0;
  data = new T[capacity];
}

template <typename T>
MyArray<T>::MyArray(MyArray<T> &other) {
  capacity = other.capacity;
  size = other.capacity;
  data = new T[capacity];


  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
}

template <typename T>
MyArray<T>::~MyArray() {
  delete[] data;
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(MyArray<T> &other) {
  delete[] data;

  capacity = other.capacity;
  size = other.capacity;
  data = new T[capacity];


  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }

  return *this;
}

template <typename T>
ContainerIfc<T>& MyArray<T>::pushBack(T val) {
  if (size >= capacity) {
    capacity += 5;
    T* newData = new T[capacity];

    for (int i = 0; i < size; i++) {
      newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
  }

  data[size] = val;
  size += 1;

  return *this;
}

template <typename T>
ContainerIfc<T>& MyArray<T>::popBack(T& var) {
  if (size == 0) {
    throw BADINDEX();
  }

  var = data[size - 1];
  size -= 1;

  if (size < capacity / 4 && capacity > 5) {
    capacity -= 5;

    T* newData = new T[capacity];

    for (int i = 0; i < size; i++) {
      newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
  }

  return *this;
} 

template <typename T>
int MyArray<T>::getSize() {
  return size;
}

template <typename T>
bool MyArray<T>::isEmpty() {
  return size == 0;
}

template <typename T>
T& MyArray<T>::operator[](int i) {
  if (i < 0 || i >= size) {
    throw BADINDEX();
  }

  return data[i];
}

template <typename T>
string MyArray<T>::toString() {
  stringstream ss;

  ss << size << endl;
  ss << capacity << endl;
  
  for (int i = 0; i < size; i++) {
    ss << data[i] << '\t';
  }

  ss << endl;

  return ss.str();
}
