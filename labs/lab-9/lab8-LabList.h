#include <iostream>
#include "lab8-ListNode.h"

using namespace std;

class BADINDEX {};

template <class T>
class LabList {
private:
  ListNode<T> *head, *tail;

public:
  LabList();
  LabList(const LabList<T>&);
  ~LabList();
  LabList <T>& operator = (const LabList<T>&);

  LabList <T>& insertHead(T);
  LabList <T>& insertTail(T);

  LabList <T>& removeHead(T&); // throws a BADINDEX
  LabList <T>& removeTail(T&); // throws a BADINDEX

  ostream & printList( ostream & );
};
