#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include "proj10-ContainerIfc.h"

template <class T> class MyVector : public ContainerIfc<T> {
public:
  MyVector();
  ~MyVector();
  MyVector(const MyVector &);
  MyVector<T> &operator=(const MyVector &);
  MyVector<T> &pushFront(T);
  MyVector<T> &pushBack(T);
  MyVector<T> &popFront(T &); // throws BADINDEX
  MyVector<T> &popBack(T &);  // throws BADINDEX
  T front();                  // throws BADINDEX
  T back();                   // throws BADINDEX
  T &operator[](int);         // throws BADINDEX
  int getSize();
  bool isEmpty();
  void erase();

protected:
  T *data;
  int size;
  int capacity;
  void grow();
  void shiftRight();
  void shiftLeft();
};

template <typename T> MyVector<T>::MyVector() {
  capacity = 5;
  size = 0;
  data = new T[capacity];
}

template <typename T> MyVector<T>::~MyVector() { delete[] data; }

template <typename T> T MyVector<T>::front() {
  if (size == 0) {
    throw BADINDEX();
  }

  return data[0];
}

template <typename T> T MyVector<T>::back() {
  if (size == 0) {
    throw BADINDEX();
  }

  return data[size - 1];
}
template <typename T> T &MyVector<T>::operator[](int i) {
  if (i < 0 || i >= size) {
    throw BADINDEX();
  }

  return data[i];
}

template <typename T> int MyVector<T>::getSize() { return size; }

template <typename T> bool MyVector<T>::isEmpty() { return size == 0; }

template <typename T> void MyVector<T>::erase() {
  // believe this is what you want us to do and not to actually free memory
  size = 0;

  // if you wanted us to do the other thing it would probably be something like
  // this: size = 0; capacity = 5; delete[] data; data = new T[capacity];
}

template <typename T> MyVector<T>::MyVector(const MyVector &other) {
  size = other.size;
  capacity = other.capacity;
  data = new T[capacity];

  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &other) {
  if (this == &other) {
    return *this;
  }

  delete[] data;

  size = other.size;
  capacity = other.capacity;
  data = new T[capacity];

  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }

  return *this;
}

template <typename T> MyVector<T> &MyVector<T>::pushFront(T val) {
  if (size == capacity) {
    grow();
  }

  shiftRight();
  data[0] = val;
  size++;

  return *this;
}

template <typename T> MyVector<T> &MyVector<T>::pushBack(T val) {
  if (size == capacity) {
    grow();
  }

  data[size] = val;
  size++;

  return *this;
}

template <typename T> MyVector<T> &MyVector<T>::popFront(T &val) {
  if (size == 0) {
    throw BADINDEX();
  }

  val = data[0];
  shiftLeft();
  size--;

  return *this;
}

template <typename T> MyVector<T> &MyVector<T>::popBack(T &val) {
  if (size == 0) {
    throw BADINDEX();
  }

  val = data[size - 1];
  size--;

  return *this;
}

template <typename T> void MyVector<T>::grow() {
  capacity *= 2;
  T *newData = new T[capacity];

  for (int i = 0; i < size; i++) {
    newData[i] = data[i];
  }

  delete[] data;
  data = newData; // Fixed: This should be data = newData, not newData = data
}

template <typename T> void MyVector<T>::shiftRight() {
  for (int i = size; i > 0; i--) {
    data[i] = data[i - 1];
  }
}

template <typename T> void MyVector<T>::shiftLeft() {
  for (int i = 0; i < size - 1; i++) {
    data[i] = data[i + 1];
  }
}

#endif
