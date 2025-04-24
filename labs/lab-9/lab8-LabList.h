#ifndef LAB_LIST_H
#define LAB_LIST_H

#include "lab8-ListNode.h"
#include <iostream>

using namespace std;

class BADINDEX {};

// helper function for deleting a circular list recursively
// iterates to the tail and then moves back to the head
template <typename T>
void deleteCircularList(ListNode<T> *node, ListNode<T> *head) {
  if (node == NULL || head == NULL) {
    return;
  }

  if (node->next != head && node->next != NULL) {
    deleteCircularList(node->next, head);
  }

  delete[] node;
}

template <class T> class LabList {
private:
  ListNode<T> *head, *tail;

public:
  LabList();
  LabList(const LabList<T> &);
  ~LabList();
  LabList<T> &operator=(const LabList<T> &);

  LabList<T> &insertHead(T);
  LabList<T> &insertTail(T);

  LabList<T> &removeHead(T &); // throws a BADINDEX
  LabList<T> &removeTail(T &); // throws a BADINDEX

  ostream &printList(ostream &);
};

template <typename T> LabList<T>::LabList() {
  head = NULL;
  tail = NULL;
}

template <typename T> LabList<T>::LabList(const LabList<T> &other) {
  head = NULL;
  tail = NULL;

  if (other.head == NULL) {
    return;
  }

  ListNode<T> *node = other.head;
  do {
    insertTail(node->data);
    node = node->next;
  } while (node != other.head);
}

template <typename T> LabList<T>::~LabList() { deleteCircularList(head, head); }

template <typename T>
LabList<T> &LabList<T>::operator=(const LabList<T> &other) {
  // edge case for self assign
  if (this == &other) {
    return *this;
  }

  // remove all self nodes
  deleteCircularList(head, head);
  head = NULL;
  tail = NULL;

  // edge case for assignment to empty list
  if (other.head == NULL) {
    return *this;
  }

  ListNode<T> *node = other.head;
  do {
    insertTail(node->data);
    node = node->next;
  } while (node != other.head);

  return *this;
}

template <typename T> LabList<T> &LabList<T>::insertHead(T val) {
  ListNode<T> *newHead = new ListNode<T>(val, head);
  if (head == NULL) {
    tail = newHead;
    head = newHead;
    newHead->next = head;
  } else {
    newHead->next = head;
    head = newHead;
    tail->next = head;
  }
  return *this;
}

template <typename T> LabList<T> &LabList<T>::insertTail(T val) {
  ListNode<T> *newTail = new ListNode<T>(val, head);
  if (head == NULL) {
    tail = newTail;
    head = newTail;
    newTail->next = head;
  } else {
    tail->next = newTail;
    tail = newTail;
    tail->next = head;
  }

  return *this;
}

template <typename T> LabList<T> &LabList<T>::removeHead(T &val) {
  if (head == NULL) {
    throw BADINDEX();
  }

  val = head->data;

  if (head == tail) {
    delete[] head;
    head = NULL;
    tail = NULL;
  } else {
    ListNode<T> *oldHead = head;

    head = head->next;
    tail->next = head;

    delete[] oldHead;
  }
  return *this;
}

template <typename T> LabList<T> &LabList<T>::removeTail(T &val) {
  if (tail == NULL) {
    throw BADINDEX();
  }
  val = tail->data;

  if (head == tail) {
    delete[] head;
    head = NULL;
    tail = NULL;
  } else {
    ListNode<T> *beforeTail = head;
    while (beforeTail->next != tail) {
      beforeTail = beforeTail->next;
    }

    delete[] tail;
    tail = beforeTail;
    tail->next = head;
  }

  return *this;
}

// no description given for how specifically this should be formatted
template <typename T> ostream &LabList<T>::printList(ostream &s) {
  if (head == NULL) {
    s << "Empty List" << endl;
    return s;
  }
  ListNode<T> *node = head;

  do {
    s << node->data;
    node = node->next;
    if (node != head) {
      s << '\t';
    }
  } while (node != head);
  s << endl;

  return s;
}

#endif
