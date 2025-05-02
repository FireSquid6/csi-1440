#ifndef QUEUE_3_H
#define QUEUE_3_H

#include "proj10-MyList.h"

template <class T> class Queue3 : public MyList<T> {
public:
  void enqueue(T);
  void dequeue(T &); // throws BADINDEX
};

// we just used pushBack and pushFront
// this works since I implemented MyList as a circular
// linked list, so both pushBack and popFront are O(1)
//
// popBack is the "slow" function. We could not use this
// as a dequeue
template <class T> void Queue3<T>::enqueue(T val) {
  this->pushBack(val);
}

template <class T> void Queue3<T>::dequeue(T& val) {
  this->popFront(val);
}

#endif
