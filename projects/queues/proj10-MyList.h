#ifndef MY_LIST_H
#define MY_LIST_H

#include "proj10-ContainerIfc.h"
#include "proj10-Node.h"
#include <cstddef>

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

template <typename T>
void deleteCircularList(Node<T> *node, Node<T> *head) {
  if (node == NULL || head == NULL) {
    return;
  }

  if (node->next != head && node->next != NULL) {
    deleteCircularList(node->next, head);
  }

  delete[] node;
}

template <class T>
MyList<T>::MyList() {
  head = NULL;
  tail = NULL;
}

template <class T> MyList<T>::MyList(const MyList &other) {
  head = NULL;
  tail = NULL;

  if (other.head == NULL) {
    return;
  }

  Node<T>* node = other.head;
  do {
    pushBack(node->data);
    node = node->next;
  } while (node != other.head);
}

template <class T> MyList<T>::~MyList() {
  
}

template <class T> MyList<T> &MyList<T>::operator=(const MyList &other) {
  if (this == &other) {
    return *this;
  }

  deleteCircularList(head, head);
  head = NULL;
  tail = NULL;

  if (other.head == NULL) {
    return *this;
  }

  Node<T> *node = other.head;

  do {
    insertTail(node->data);
    node = node->next;
  } while (node != other.head);

  return *this;
}

template <class T> MyList<T> &MyList<T>::pushFront(T val) {
  Node<T> *newHead = new Node<T>(val);
  newHead->next = head;

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

template <class T> MyList<T> &MyList<T>::pushBack(T val) {
  Node<T> *newTail = new Node<T>(val);
  newTail->next = head;

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

template <class T> MyList<T> &MyList<T>::popFront(T &val) {
  if (head == NULL) {
    throw BADINDEX();
  }

  val = head->data;

  if (head == tail) {
    delete[] head;
    head = NULL;
    tail = NULL;
  } else {
    Node<T> *oldHead = head;

    head = head->next;
    tail->next = head;

    delete[] oldHead;
  }
  return *this;
}

template <class T> MyList<T> &MyList<T>::popBack(T &val) {
  if (tail == NULL) {
    throw BADINDEX();
  }
  val = tail->data;

  if (head == tail) {
    delete[] head;
    head = NULL;
    tail = NULL;
  } else {
    Node<T> *beforeTail = head;
    while (beforeTail->next != tail) {
      beforeTail = beforeTail->next;
    }

    delete[] tail;
    tail = beforeTail;
    tail->next = head;
  }

  return *this;
}

template <class T> int MyList<T>::getSize() {
  if (head == NULL) {
    return 0;
  }

  int size = 0;
  Node<T> node = head;

  while (node != tail) {
    node = node->next;
    size++;
  }

  return size;
}

template <class T> bool MyList<T>::isEmpty() {
  return head == NULL;
}

template <class T> T MyList<T>::front() {
  if (head == NULL) {
    throw BADINDEX();
  }

  return head->data;
}

template <class T> T MyList<T>::back() {
  if (tail == NULL) {
    throw BADINDEX();
  }

  return tail->data;
}

template <class T> T &MyList<T>::operator[](int i) {
  if (head == NULL) {
    throw BADINDEX();
  }

  Node<T> node = head;

  while (i > 0) {
    if (node == tail) {
      throw BADINDEX();
    }
    node = node->next;

    i--;
  }

  return node->data;
}

template <class T> void MyList<T>::erase() {
  deleteCircularList(head, head);
}

#endif
