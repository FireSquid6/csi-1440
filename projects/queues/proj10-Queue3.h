#ifndef QUEUE_3_H
#define QUEUE_3_H

#include "proj10-MyList.h"

template <class T> class Queue3 : public MyList<T> {
public:
  void enqueue(T);
  void dequeue(T &); // throws BADINDEX
};

// we just used pushBack and pushFront
template <class T> void Queue3<T>::enqueue(T val) {
  pushBack(val);
}

template <class T> void Queue3<T>::dequeue(T& val) {
  popFront(val);
}

#endif
