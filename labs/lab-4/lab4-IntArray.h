#ifndef INT_ARRAY_H
#define INT_ARRAY_H
#include "lab4-LabArray.h"
#include <iostream>
using namespace std;

class IntArray : public LabArray {
private:
  /**
   * resizeTo
   *
   * Resizes the internal array to the specified capacity. This function
   * handles the dynamic memory allocation and copying of existing elements.
   *
   * Parameters:
   * newCapacity: the new size to resize the array to
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  void resizeTo(int);

public:
  /**
   * IntArray
   *
   * Default constructor that initializes an empty integer array.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  IntArray();

  /**
   * ~IntArray
   *
   * Destructor that cleans up any dynamically allocated memory.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  ~IntArray();

  /**
   * IntArray
   *
   * Copy constructor that creates a deep copy of another IntArray object.
   *
   * Parameters:
   * other: the IntArray object to copy from
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  IntArray(const IntArray &);

  /**
   * operator=
   *
   * Assignment operator that creates a deep copy of another IntArray object.
   *
   * Parameters:
   * other: the IntArray object to copy from
   *
   * Output:
   * return: reference to this object
   * reference parameters: none
   * stream: none
   */
  IntArray &operator=(const IntArray &);

  /**
   * getVal
   *
   * Retrieves the value at the specified index in the array.
   *
   * Parameters:
   * index: the position from which to retrieve the value
   *
   * Output:
   * return: the integer value at the specified index
   * reference parameters: none
   * stream: none
   */
  int getVal(int);

  /**
   * getCapacity
   *
   * Returns the current capacity of the array.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: the total capacity of the array
   * reference parameters: none
   * stream: none
   */
  int getCapacity();

  /**
   * getSize
   *
   * Returns the current number of elements in the array.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: the number of elements currently stored in the array
   * reference parameters: none
   * stream: none
   */
  int getSize();

  /**
   * insertVal
   *
   * Inserts a new value at the end of the array, resizing if necessary.
   *
   * Parameters:
   * value: the integer value to insert
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  void insertVal(int);

  /**
   * removeVal
   *
   * Removes and returns the last value in the array.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: the last value in the array before removal
   * reference parameters: none
   * stream: none
   */
  int removeVal();

  /**
   * setVal
   *
   * Sets the value at a specified index in the array.
   * This is a testing/debugging function not in the original spec.
   *
   * Parameters:
   * val: the value to set
   * i: the index at which to set the value
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  void setVal(int val, int i);

  /**
   * output
   *
   * Outputs the contents of the array to the specified output stream.
   * This is a testing/debugging function not in the original spec.
   *
   * Parameters:
   * o: the output stream to write to
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: writes array contents to output stream
   */
  void output(ostream &o);
};
#endif
