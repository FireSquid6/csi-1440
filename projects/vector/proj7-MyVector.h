/**
 * file: proj7-MyVector.h
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: Project 7
 * due date: 04/06/2025
 *
 * date modified: 04/01/2025
 * - file created
 *
 * Implementation and declaration file for the vector
 *
 */
#include "proj7-ContainerIfc.h"

template <class T> class MyVector : public ContainerIfc<T> {
public:
  /**
   * MyVector
   *
   * Default constructor that initializes an empty vector with default capacity.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  MyVector();

  /**
   * ~MyVector
   *
   * Destructor that frees dynamically allocated memory used by the vector.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  ~MyVector();

  /**
   * MyVector
   *
   * Copy constructor that creates a deep copy of another MyVector object.
   *
   * Parameters:
   *      other: reference to the MyVector object to copy
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  MyVector(const MyVector &);

  /**
   * operator=
   *
   * Assignment operator that creates a deep copy of another MyVector object.
   *
   * Parameters:
   *      other: reference to the MyVector object to copy
   *
   * Output:
   *      return: reference to this object after assignment
   *      reference parameters: none
   *      stream: none
   */
  MyVector<T> &operator=(const MyVector &);

  /**
   * pushFront
   *
   * This function adds an element to the front of the vector.
   *
   * Parameters:
   *      T: element to be added to the front of the vector
   *
   * Output:
   *      return: reference to the container interface
   *      reference parameters: none
   *      stream: none
   */
  MyVector<T> &pushFront(T);

  /**
   * pushBack
   *
   * This function adds an element to the end of the vector.
   *
   * Parameters:
   *      T: element to be added to the end of the vector
   *
   * Output:
   *      return: reference to the container interface
   *      reference parameters: none
   *      stream: none
   */
  MyVector<T> &pushBack(T);

  /**
   * popFront
   *
   * This function removes the first element from the vector and stores it
   * in the reference parameter. Throws BADINDEX exception if the vector is
   * empty.
   *
   * Parameters:
   *      T &: reference to store the removed element
   *
   * Output:
   *      return: reference to the container interface
   *      reference parameters: T &: contains the removed element
   *      stream: none
   */
  MyVector<T> &popFront(T &);

  /**
   * popBack
   *
   * This function removes the last element from the vector and stores it
   * in the reference parameter. Throws BADINDEX exception if the vector is
   * empty.
   *
   * Parameters:
   *      T &: reference to store the removed element
   *
   * Output:
   *      return: reference to the container interface
   *      reference parameters: T &: contains the removed element
   *      stream: none
   */
  MyVector<T> &popBack(T &);

  /**
   * front
   *
   * This function returns the first element in the vector.
   * Throws BADINDEX exception if the vector is empty.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: the first element in the vector
   *      reference parameters: none
   *      stream: none
   */
  T front();

  /**
   * back
   *
   * This function returns the last element in the vector.
   * Throws BADINDEX exception if the vector is empty.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: the last element in the vector
   *      reference parameters: none
   *      stream: none
   */
  T back();

  /**
   * operator[]
   *
   * This function provides array-like access to elements in the vector.
   * Throws BADINDEX exception if the index is out of bounds.
   *
   * Parameters:
   *      int: index of the element to access
   *
   * Output:
   *      return: reference to the element at the specified index
   *      reference parameters: none
   *      stream: none
   */
  T &operator[](int);

  /**
   * getSize
   *
   * This function returns the current number of elements in the vector.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: integer representing the current size of the vector
   *      reference parameters: none
   *      stream: none
   */
  int getSize();

  /**
   * isEmpty
   *
   * This function checks if the vector is empty.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: boolean value, true if vector is empty, false otherwise
   *      reference parameters: none
   *      stream: none
   */
  bool isEmpty();

  /**
   * erase
   *
   * This function removes all elements from the vector.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void erase();

private:
  T *data;
  int size;
  int capacity;

  /**
   * grow
   *
   * This function increases the capacity of the internal array when it becomes
   * full. Doubles capacity each time
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void grow();

  /**
   * shiftRight
   *
   * This function shifts all elements one position to the right,
   * making space for a new element at the front. Will increase the size
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void shiftRight();

  /**
   * shiftLeft
   *
   * This function shifts all elements one position to the left,
   * after removing an element from the front.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void shiftLeft();
};

template <typename T> void MyVector<T>::grow() {
  capacity *= 2;
  T *newData = new T[capacity];

  for (int i = 0; i < size; i++) {
    newData[i] = data[i];
  }

  delete[] data;
  data = newData;
}

template <typename T> void MyVector<T>::shiftRight() {
  if (size >= capacity) {
    grow();
  }

  for (int i = size; i > 0; i--) {
    data[i] = data[i - 1];
  }

  size += 1;
}

template <typename T> void MyVector<T>::shiftLeft() {
  for (int i = 0; i < size - 1; i++) {
    data[i] = data[i + 1];
  }

  size -= 1;
}

template <typename T> MyVector<T>::MyVector() {
  capacity = 10;
  size = 0;

  data = new T[capacity];
}
template <typename T> MyVector<T>::~MyVector() { delete[] data; }

template <typename T> MyVector<T>::MyVector(const MyVector &other) {
  capacity = other.capacity;
  size = other.size;
  data = new T[capacity];

  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
}

template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector &other) {
  if (this == &other) {
    return *this;
  }

  delete[] data;

  capacity = other.capacity;
  size = other.size;
  data = new T[capacity];

  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }

  return *this;
}

template <typename T> MyVector<T> &MyVector<T>::pushFront(T val) {
  shiftRight();
  data[0] = val;

  return *this;
}

template <typename T> MyVector<T> &MyVector<T>::pushBack(T val) {
  size += 1;
  if (size >= capacity) {
    grow();
  }

  data[size - 1] = val;
  return *this;
}

template <typename T> MyVector<T> &MyVector<T>::popFront(T &val) {
  if (size <= 0) {
    throw BADINDEX();
  }

  val = data[0];
  shiftLeft();

  return *this;
}

template <typename T> MyVector<T> &MyVector<T>::popBack(T &val) {
  if (size <= 0) {
    throw BADINDEX();
  }
  val = data[size - 1];
  size -= 1;

  return *this;
}

template <typename T> T MyVector<T>::front() {
  if (size <= 0) {
    throw BADINDEX();
  }

  return data[0];
}

template <typename T> T MyVector<T>::back() {
  if (size <= 0) {
    throw BADINDEX();
  }

  return data[size - 1];
}

template <typename T> T &MyVector<T>::operator[](int i) {
  if (i >= size || i < 0) {
    throw BADINDEX();
  }

  return data[i];
}

template <typename T> int MyVector<T>::getSize() { return size; }

template <typename T> bool MyVector<T>::isEmpty() { return size == 0; }

template <typename T> void MyVector<T>::erase() { size = 0; }
