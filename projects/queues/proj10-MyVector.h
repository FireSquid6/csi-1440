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

template <typename T> MyVector<T> &MyVector<T>::operator=(const MyVector &other) {
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
  T* newData = new T[capacity]; 
  
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
