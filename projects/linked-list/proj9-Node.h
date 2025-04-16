#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T>
class Node {
  public:
	 T data;
	 Node<T> *next;

	 Node(T e) {
		 data = e;
		 next = NULL;
	}
};

#endif
