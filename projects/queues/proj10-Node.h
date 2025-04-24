#ifndef proj10_Node_h
#define proj10_Node_h

#include <cstddef>

template <class T>
class Node {
public:
  T data;
  Node <T>*next;

  Node( T d ) {
    data = d;
    next = NULL;
  }
  
  ~Node( ) {
    delete next;
  }
};

#endif
