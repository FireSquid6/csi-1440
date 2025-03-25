/**
* file: MyArray.h
* author: Jonathan Deiss
* course: CSI 1440
* assignment: lab 6
* due date: 3/24/2025
*
* date modified: 3/24/2025
* - create the file
* 
* Contains the implementation of a dynamically resizing array with a template type
*
*/
#include "ContainerIfc.h"
#include <sstream>
#include <iostream>

template <typename T> class MyArray : public ContainerIfc<T> {
private:
  T *data;
  int capacity, size;
public:
  /**
   * MyArray
   *
   * Default constructor that initializes an empty array with default capacity.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  MyArray();
  
  /**
   * MyArray
   *
   * Copy constructor that creates a deep copy of another MyArray object.
   *
   * Parameters:
   *      other: reference to the MyArray<T> object to copy
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  MyArray(MyArray<T> &other);
  
  /**
   * ~MyArray
   *
   * Destructor that frees dynamically allocated memory used by the array.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  ~MyArray();
  
  /**
   * operator=
   *
   * Assignment operator that creates a deep copy of another MyArray object.
   *
   * Parameters:
   *      other: reference to the MyArray<T> object to copy
   *
   * Output:
   *      return: reference to this object after assignment
   *      reference parameters: none
   *      stream: none
   */
  MyArray<T> &operator=(MyArray<T> &other);
  
  /**
   * pushBack
   *
   * This function adds an element to the end of the array.
   *
   * Parameters:
   *      T: element to be added to the array
   *
   * Output:
   *      return: reference to the container interface
   *      reference parameters: none
   *      stream: none
   */
  ContainerIfc<T> &pushBack(T) override;
  
  /**
   * popBack
   *
   * This function removes the last element from the array and stores it in the reference parameter.
   * Throws BADINDEX exception if the array is empty.
   *
   * Parameters:
   *      T &: reference to store the removed element
   *
   * Output:
   *      return: reference to the container interface
   *      reference parameters: T &: contains the removed element
   *      stream: none
   */
  ContainerIfc<T> &popBack(T &) override; // throws BADINDEX
  
  /**
   * getSize
   *
   * This function returns the current number of elements in the array.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: integer representing the current size of the array
   *      reference parameters: none
   *      stream: none
   */
  int getSize() override;
  
  /**
   * isEmpty
   *
   * This function checks if the array is empty.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: boolean value, true if array is empty, false otherwise
   *      reference parameters: none
   *      stream: none
   */
  bool isEmpty() override;
  
  /**
   * operator[]
   *
   * This function provides array-like access to elements.
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
  T &operator[](int) override; // throws BADINDEX
  
  /**
   * toString
   *
   * This function creates a string representation of the entire array.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: string containing formatted information about all elements
   *      reference parameters: none
   *      stream: none
   */
  string toString() override;
};

template <typename T>
MyArray<T>::MyArray() {
  capacity = 5;
  size = 0;
  data = new T[capacity];
}

template <typename T>
MyArray<T>::MyArray(MyArray<T> &other) {
  capacity = other.capacity;
  size = other.capacity;
  data = new T[capacity];


  for (int i = 0; i < size; i++) {
    data[i] = T(other.data[i]);
  }
}

template <typename T>
MyArray<T>::~MyArray() {
  delete[] data;
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(MyArray<T> &other) {
  // self assignment is bad!
  if (this == &other) {
    return *this;
  }

  if (data != nullptr) {
    delete[] data;
  }


  capacity = other.capacity;
  size = other.size;
  data = new T[capacity];


  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }

  return *this;
}

template <typename T>
ContainerIfc<T>& MyArray<T>::pushBack(T val) {
  if (size >= capacity) {
    capacity += 5;
    T* newData = new T[capacity];

    for (int i = 0; i < size; i++) {
      newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
  }

  data[size] = val;
  size += 1;

  return *this;
}

template <typename T>
ContainerIfc<T>& MyArray<T>::popBack(T& var) {
  if (size == 0) {
    throw BADINDEX();
  }

  var = data[size - 1];
  size -= 1;

  if (size < capacity / 4 && capacity > 5) {
    capacity -= 5;

    T* newData = new T[capacity];

    for (int i = 0; i < size; i++) {
      newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
  }

  return *this;
} 

template <typename T>
int MyArray<T>::getSize() {
  return size;
}

template <typename T>
bool MyArray<T>::isEmpty() {
  return size == 0;
}

template <typename T>
T& MyArray<T>::operator[](int i) {
  if (i < 0 || i >= size) {
    throw BADINDEX();
  }

  return data[i];
}

template <typename T>
string MyArray<T>::toString() {
  stringstream ss;

  ss << size << endl;
  ss << capacity << endl;
  
  for (int i = 0; i < size; i++) {
    ss << data[i] << '\t';
  }

  ss << endl;

  return ss.str();
}
