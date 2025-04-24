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

#endif
