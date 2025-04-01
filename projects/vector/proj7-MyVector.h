#include "proj7-ContainerIfc.h"

template <class T> class MyVector : public ContainerIfc<T> {
public:
  MyVector();
  ~MyVector();
  MyVector(const MyVector &);
  MyVector<T> &operator=(const MyVector &);
  MyVector<T> &pushFront(T);
  MyVector<T> &pushBack(T);
  MyVector<T> &popFront(T &);
  MyVector<T> &popBack(T &);
  T front();
  T back();
  T &operator[](int);
  int getSize();
  bool isEmpty();
  void erase();

private:
  T *data;
  int size;
  int capacity;
  void grow();
  void shiftRight();
  void shiftLeft();
};

template <typename T> void MyVector<T>::grow() {
  capacity *= 2;
  T *newData = new T[capacity];
  
  for (int i = 0; i < size; i++) {
    newData[i] = data[i];
  }

  delete[] data;
  data = newData;
}

template <typename T> void MyVector<T>::shiftRight() {
  if (size + 1 >= capacity) {
    grow();
  }

  size += 1;
  for (int i = size - 1; i > 0; i++) {
    data[i] = data[i - 1];
  }
}

template <typename T> void MyVector<T>::shiftLeft() {
  for (int i = 0; i < size - 1; i++) {
    data[i] = data[i + 1];
  }

  size -= 1;
}

template <typename T> MyVector<T>::MyVector() {
  capacity = 10;
  size = 0;

  data = new T[capacity];
}
template <typename T> MyVector<T>::~MyVector() { delete[] data; }

template <typename T> MyVector<T>::MyVector(const MyVector &other) {
  capacity = other.capacity;
  size = other.size;
  data = new T[capacity];

  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &other) {
  if (this == &other) {
    return;
  }

  delete[] data;

  capacity = other.capacity;
  size = other.size;
  data = new T[capacity];

  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
}

template <typename T> MyVector<T> &MyVector<T>::pushFront(T val) {
  shiftRight();
  data[0] = val;

  return *this;
}

template <typename T> MyVector<T> &MyVector<T>::pushBack(T val) {
  size += 1;
  if (size >= capacity) {
    grow();
  }

  data[size - 1] = val;
  return *this;
}

template <typename T> MyVector<T> &MyVector<T>::popFront(T &val) {
  val = data[0];
  shiftLeft();

  return *this;
}

template <typename T> MyVector<T> &MyVector<T>::popBack(T &val) {
  val = data[size - 1];
  size -= 1;

  return *this;
}

template <typename T> T MyVector<T>::front() {
  if (size <= 0) {
    throw BADINDEX();
  }

  return data[0];
}

template <typename T> T MyVector<T>::back() {
  if (size <= 0) {
    throw BADINDEX();
  }

  return data[size - 1];
}

template <typename T> T &MyVector<T>::operator[](int i) {
  if (i >= size || i < 0) {
    throw BADINDEX();
  }

  return data[i];
}

template <typename T> int MyVector<T>::getSize() { return size; }

template <typename T> bool MyVector<T>::isEmpty() { return size == 0; }

template <typename T> void MyVector<T>::erase() {
  delete[] data;

  capacity = 10;
  size = 0;
  data = new T[capacity];
}
