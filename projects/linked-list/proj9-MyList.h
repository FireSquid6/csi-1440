#ifndef MY_LIST_H
#define MY_LIST_H

#include "proj9-ContainerIfc.h"
#include "proj9-Node.h"

template <class T> class MyList : public ContainerIfc<T> {
public:
  MyList();
  ~MyList();
  MyList(const MyList &);
  MyList<T> &operator=(const MyList &);
  MyList<T> &pushFront(T);
  MyList<T> &pushBack(T);
  MyList<T> &popFront(T &);
  MyList<T> &popBack(T &);
  int getSize();
  bool isEmpty();
  T front();
  T back();
  T &operator[](int);
  void erase();

protected:
  Node<T> *head;
  
private:
  // I can't remember if you said whether you wanted
  // this as a private method or not. If I was supposed
  // to do it as just a normal function please pretend
  // I did that beccause it's effectively the same thing
  void eraseHelper(Node<T> *);
};

template <typename T> MyList<T>::MyList() { 
  head = NULL; 
}

template <typename T> MyList<T>::~MyList() {
  Node<T> *current = head;
  Node<T> *next;
  
  while (current != NULL) {
    next = current->next;
    delete current;
    current = next;
  }
  
  head = NULL;
}

template <typename T> MyList<T>::MyList(const MyList<T> &other) {
  head = NULL;
  
  if (other.head == NULL) {
    return;
  }
  
  Node<T> *otherCurrent = other.head;
  Node<T> *newNode = new Node<T>;
  newNode->data = otherCurrent->data;
  newNode->next = NULL;
  head = newNode;
  
  Node<T> *current = head;
  otherCurrent = otherCurrent->next;
  
  while (otherCurrent != NULL) {
    newNode = new Node<T>;
    newNode->data = otherCurrent->data;
    newNode->next = NULL;
    current->next = newNode;
    
    current = current->next;
    otherCurrent = otherCurrent->next;
  }
}

template <typename T> MyList<T> &MyList<T>::operator=(const MyList &other) {
  if (this == &other) {
    return *this;
  }
  
  erase();
  
  if (other.head == NULL) {
    return *this;
  }
  
  Node<T> *otherCurrent = other.head;
  Node<T> *newNode = new Node<T>;
  newNode->data = otherCurrent->data;
  newNode->next = NULL;
  head = newNode;
  
  Node<T> *current = head;
  otherCurrent = otherCurrent->next;
  
  while (otherCurrent != NULL) {
    newNode = new Node<T>;
    newNode->data = otherCurrent->data;
    newNode->next = NULL;
    current->next = newNode;
    
    current = current->next;
    otherCurrent = otherCurrent->next;
  }
  
  return *this;
}

template <typename T> MyList<T> &MyList<T>::pushFront(T value) {
  Node<T> *newNode = new Node<T>;
  newNode->data = value;
  newNode->next = head;
  head = newNode;
  
  return *this;
}

template <typename T> MyList<T> &MyList<T>::pushBack(T value) {
  Node<T> *newNode = new Node<T>;
  newNode->data = value;
  newNode->next = NULL;
  
  if (head == NULL) {
    head = newNode;
    return *this;
  }
  
  Node<T> *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  
  current->next = newNode;
  return *this;
}

template <typename T> MyList<T> &MyList<T>::popFront(T &value) {
  if (head == NULL) {
    throw BADINDEX();
  }
  
  value = head->data;
  Node<T> *temp = head;
  head = head->next;
  delete temp;
  
  return *this;
}

template <typename T> MyList<T> &MyList<T>::popBack(T &value) {
  if (head == NULL) {
    throw BADINDEX();
  }
  
  if (head->next == NULL) {
    value = head->data;
    delete head;
    head = NULL;
    return *this;
  }
  
  Node<T> *current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  
  value = current->next->data;
  delete current->next;
  current->next = NULL;
  
  return *this;
}

template <typename T> int MyList<T>::getSize() {
  int count = 0;
  Node<T> *current = head;
  
  while (current != NULL) {
    count++;
    current = current->next;
  }
  
  return count;
}

template <typename T> bool MyList<T>::isEmpty() {
  return head == NULL;
}

template <typename T> T MyList<T>::front() {
  if (head == NULL) {
    throw BADINDEX();
  }
  
  return head->data;
}

template <typename T> T MyList<T>::back() {
  if (head == NULL) {
    throw BADINDEX();
  }
  
  Node<T> *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  
  return current->data;
}

template <typename T> T &MyList<T>::operator[](int index) {
  if (head == NULL || index < 0) {
    throw BADINDEX();
  }
  
  Node<T> *current = head;
  int count = 0;
  
  while (current != NULL && count < index) {
    current = current->next;
    count++;
  }
  
  if (current == NULL) {
    throw BADINDEX();
  }
  
  return current->data;
}

template <typename T> void MyList<T>::eraseHelper(Node<T> *node) {
  if (node == NULL) {
    return;
  }
  
  eraseHelper(node->next);
  delete node;
}

template <typename T> void MyList<T>::erase() {
  eraseHelper(head);
  head = NULL;
}

#endif
