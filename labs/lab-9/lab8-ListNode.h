#ifndef LISTNODE_H
#define LISTNODE_H

#include <cstddef>

template <class T>
class ListNode {
public:
  T data;
  ListNode<T> *next;

  ListNode( T d, ListNode<T> *np = NULL ) {
    data = d;
    next = np;
  }
};

#endif
