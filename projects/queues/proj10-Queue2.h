#ifndef QUEUE_2_H
#define QUEUE_2_H

#include "proj10-MyVector.h"

// not really sure why this extends from MyVector. The functions
// pushFront, pushBack, popFront, and popBack will break this and
// shouldn't be used with the queue
template <class T> class Queue2 : public MyVector<T> {
private:
  int front, rear;

public:
  Queue2();
  T &operator[](int) override;
  void enqueue(T);
  void dequeue(T &); // throws BADINDEX
};

template <typename T> Queue2<T>::Queue2() {
  front = 0;
  rear = 0;
}

template <typename T> void Queue2<T>::enqueue(T val) {
  if (this->isEmpty()) {
    throw BADINDEX();
  }

  val = this->data[front];
  front = (front + 1) % this->capacity;
  this->size -= 1;
}

template <typename T> void Queue2<T>::dequeue(T &) {
  if (this->size == 0) {
    throw BADINDEX();
  }

}

template <typename T> T& Queue2<T>::operator[](int index) {
  if (index >= this->size) {
    throw BADINDEX();
  }

  int i = front + index;

  return this->data[i];
}

// overload:
// front
// back

#endif
