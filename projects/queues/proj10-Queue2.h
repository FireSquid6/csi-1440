#ifndef QUEUE_2_H
#define QUEUE_2_H

#include "proj10-MyVector.h"

// not sure why this extends from MyVector. Feel like it would make
// more sense to use composition here
template <class T> class Queue2 : public MyVector<T> {
private:
  int f, r;

public:
  Queue2();
  T &operator[](int) override;
  T front() override;
  T back() override;
  void enqueue(T);
  void dequeue(T &); // throws BADINDEX
};


template <typename T> Queue2<T>::Queue2() {
  f = 0;
  r = -1;
  this->capacity = 5;
  this->size = 0;
  this->data = new T[this->capacity];
}

template <typename T> void Queue2<T>::enqueue(T val) {
  if (this->size - 1 >= this->capacity) {
    this->grow();
  }

  r = (r + 1) % this->capacity;
  this->data[r] = val;
  this->size++;
}

template <typename T> void Queue2<T>::dequeue(T &val) {
  if (this->size == 0) {
    throw BADINDEX();
  }
  
  val = this->data[f];
  f = (f + 1) % this->capacity;
  this->size--;
}

template <typename T> T& Queue2<T>::operator[](int index) {
  if (index >= this->size) {
    throw BADINDEX();
  }

  int i = f + index;

  return this->data[i];
}

template <typename T> T Queue2<T>::front() {
  if (this->size == 0) {
    throw BADINDEX();
  }

  return this->data[f];
}

template <typename T> T Queue2<T>::back() {
  if (this->size == 0 || r == -1) {
    throw BADINDEX();
  }

  return this->data[r];
}

#endif
