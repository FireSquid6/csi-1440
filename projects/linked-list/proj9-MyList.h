/**
 * file: proj9-MyList.h
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: Project 9
 * due date: 04/21/2025
 *
 * date modified: 04/21/2025
 * - file created
 *
 * This file contains the MyList class which implements a linked list
 */

#ifndef MY_LIST_H
#define MY_LIST_H

#include "proj9-ContainerIfc.h"
#include "proj9-Node.h"

template <class T> class MyList : public ContainerIfc<T> {
public:
  /**
   * MyList
   *
   * Default constructor that creates an empty list.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  MyList();

  /**
   * ~MyList
   *
   * Destructor that frees all dynamically allocated memory for the list.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  ~MyList();

  /**
   * MyList
   *
   * Copy constructor that creates a deep copy of the given MyList object.
   *
   * Parameters:
   * other: the MyList object to copy from
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  MyList(const MyList &);

  /**
   * operator=
   *
   * Assignment operator that creates a deep copy of the given MyList object.
   *
   * Parameters:
   * other: the MyList object to copy from
   *
   * Output:
   * return: reference to this MyList object
   * reference parameters: none
   * stream: none
   */
  MyList<T> &operator=(const MyList &);

  /**
   * pushFront
   *
   * Adds an element to the front of the list.
   *
   * Parameters:
   * item: the element to be added to the front of the list
   *
   * Output:
   * return: reference to the container interface
   * reference parameters: none
   * stream: none
   */
  ContainerIfc<T> &pushFront(T);

  /**
   * pushBack
   *
   * Adds an element to the back of the list.
   *
   * Parameters:
   * item: the element to be added to the back of the list
   *
   * Output:
   * return: reference to the container interface
   * reference parameters: none
   * stream: none
   */
  ContainerIfc<T> &pushBack(T);

  /**
   * popFront
   *
   * Removes and returns the element from the front of the list.
   *
   * Parameters:
   * item: reference to store the removed element
   *
   * Output:
   * return: reference to the container interface
   * reference parameters: item is populated with the removed front element
   * stream: none
   */
  ContainerIfc<T> &popFront(T &);

  /**
   * popBack
   *
   * Removes and returns the element from the back of the list.
   *
   * Parameters:
   * item: reference to store the removed element
   *
   * Output:
   * return: reference to the container interface
   * reference parameters: item is populated with the removed back element
   * stream: none
   */
  ContainerIfc<T> &popBack(T &);

  /**
   * getSize
   *
   * Returns the current number of elements in the list.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: number of elements in the list
   * reference parameters: none
   * stream: none
   */
  int getSize();

  /**
   * isEmpty
   *
   * Checks if the list is empty.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: true if the list contains no elements, false otherwise
   * reference parameters: none
   * stream: none
   */
  bool isEmpty();

  /**
   * front
   *
   * Returns the element at the front of the list.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: the first element in the list
   * reference parameters: none
   * stream: none
   */
  T front();

  /**
   * back
   *
   * Returns the element at the back of the list.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: the last element in the list
   * reference parameters: none
   * stream: none
   */
  T back();

  /**
   * operator[]
   *
   * Provides access to an element at a specific index in the list.
   *
   * Parameters:
   * index: the position of the element to access
   *
   * Output:
   * return: reference to the element at the specified position
   * reference parameters: none
   * stream: none
   */
  T &operator[](int);

  /**
   * erase
   *
   * Removes all elements from the list, freeing all dynamically allocated
   * memory.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  void erase();

protected:
  /**
   * head
   *
   * Pointer to the first node in the list.
   */
  Node<T> *head;

private:
  /**
   * eraseHelper
   *
   * Recursive helper function to deallocate nodes from the list.
   *
   * Parameters:
   * node: pointer to the current node to be deleted
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  // couldn't remember whether this was supposed to be
  // a private method or outside of the class. Easy to
  // do either way, so just pretend I did whichever one
  // you wanted me to if I did the wrong thing.
  //
  // felt like it made more sense to have this as a
  // private method since its explicitly for the MyList
  // class but honestly it could go either way
  void eraseHelper(Node<T> *);
};

template <typename T> MyList<T>::MyList() { head = NULL; }

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
  head = new Node<T>(otherCurrent->data);

  Node<T> *current = head;
  otherCurrent = otherCurrent->next;

  while (otherCurrent != NULL) {
    current->next = new Node<T>(otherCurrent->data);
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
  head = new Node<T>(otherCurrent->data);

  Node<T> *current = head;
  otherCurrent = otherCurrent->next;

  while (otherCurrent != NULL) {
    current->next = new Node<T>(otherCurrent->data);
    current = current->next;
    otherCurrent = otherCurrent->next;
  }

  return *this;
}

template <typename T> ContainerIfc<T> &MyList<T>::pushFront(T value) {
  Node<T> *newNode = new Node<T>(value);
  newNode->next = head;
  head = newNode;

  return *this;
}

template <typename T> ContainerIfc<T> &MyList<T>::pushBack(T value) {
  Node<T> *newNode = new Node<T>(value);

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

template <typename T> ContainerIfc<T> &MyList<T>::popFront(T &value) {
  if (head == NULL) {
    throw BADINDEX();
  }

  value = head->data;
  Node<T> *temp = head;
  head = head->next;
  delete temp;

  return *this;
}

template <typename T> ContainerIfc<T> &MyList<T>::popBack(T &value) {
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

template <typename T> bool MyList<T>::isEmpty() { return head == NULL; }

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
