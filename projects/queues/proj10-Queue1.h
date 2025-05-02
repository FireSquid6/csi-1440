#ifndef QUEUE_1_H
#define QUEUE_1_H

#include "proj10-MyVector.h"

template <class T> class Queue1 : public MyVector<T> {
public:
  void enqueue(T);
  void dequeue(T &); // throws BADINDEX
};

template <class T> void Queue1<T>::enqueue(T val) {
  this->pushFront(val);
}

template <class T> void Queue1<T>::dequeue(T& val) {
  this->popBack(val);
}

#endif
