#ifndef MY_LIST_H
#define MY_LIST_H

#include "proj10-ContainerIfc.h"
#include "proj10-Node.h"

template <class T> class MyList : public ContainerIfc<T> {
public:
  MyList();
  ~MyList();
  MyList(const MyList &);
  MyList<T> &operator=(const MyList &);
  MyList<T> &pushFront(T);
  MyList<T> &pushBack(T);
  MyList<T> &popFront(T &); // throws BADINDEX
  MyList<T> &popBack(T &);  // throws BADINDEX
  int getSize();
  bool isEmpty();
  T front();          // throws BADINDEX
  T back();           // throws BADINDEX
  T &operator[](int); // throws BADINDEX
  void erase();

private:
  Node<T> *head;
  Node<T> *tail;
};

#endif
