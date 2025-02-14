/**
* file: proj3-MyString.h
* author: Jonathan Deiss
* course: CSI 1440
* assignment: Project 3
* due date: 02/15/2025
*
* date modified: 02/14/2025
* - file created
*
*/
#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>

using namespace std;

class MyString {
private:
  int size;
  int capacity;
  char *data;

  /**
   * ensureCanHold
   *
   * This function ensures the internal array has enough capacity to hold
   * the specified size. If needed, it will reallocate the array with
   * increased capacity.
   *
   * Parameters:
   * size: the minimum capacity needed
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  void ensureCanHold(int);

public:
  /**
   * MyString
   *
   * Default constructor that creates an empty string.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  MyString();

  /**
   * MyString
   *
   * Constructor that creates a string from a C-style character array.
   *
   * Parameters:
   * str: null-terminated character array to initialize the string with
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  MyString(const char *);

  /**
   * ~MyString
   *
   * Destructor that frees all dynamically allocated memory.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  ~MyString();

  /**
   * MyString
   *
   * Copy constructor that creates a deep copy of the given MyString object.
   *
   * Parameters:
   * other: the MyString object to copy from
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  MyString(const MyString &);

  /**
   * operator=
   *
   * Assignment operator that creates a deep copy of the given MyString object.
   *
   * Parameters:
   * other: the MyString object to copy from
   *
   * Output:
   * return: reference to this object
   * reference parameters: none
   * stream: none
   */
  MyString &operator=(const MyString &);

  /**
   * operator==
   *
   * Compares this string with another for equality.
   *
   * Parameters:
   * other: the MyString object to compare with
   *
   * Output:
   * return: true if strings are equal, false otherwise
   * reference parameters: none
   * stream: none
   */
  bool operator==(const MyString &) const;

  /**
   * operator[]
   *
   * Provides access to individual characters in the string.
   *
   * Parameters:
   * index: the position of the character to access
   *
   * Output:
   * return: reference to the character at the specified position
   * reference parameters: none
   * stream: none
   */
  char &operator[](int);

  /**
   * operator+=
   *
   * Concatenates the given string to the end of this string.
   *
   * Parameters:
   * other: the MyString object to append
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: none
   */
  void operator+=(const MyString &);

  /**
   * operator+
   *
   * Creates a new string that is the concatenation of this string and another.
   *
   * Parameters:
   * other: the MyString object to concatenate with
   *
   * Output:
   * return: new MyString containing the concatenated result
   * reference parameters: none
   * stream: none
   */
  MyString operator+(const MyString &) const;

  /**
   * getline
   *
   * Reads characters from an input stream until the specified delimiter is encountered.
   *
   * Parameters:
   * in: the input stream to read from
   * delimit: the character that marks the end of input (default: newline)
   *
   * Output:
   * return: none
   * reference parameters: none
   * stream: reads from input stream until delimiter
   */
  void getline(istream &, char delimit = '\n');

  /**
   * length
   *
   * Returns the current length of the string.
   *
   * Parameters:
   * none
   *
   * Output:
   * return: number of characters in the string
   * reference parameters: none
   * stream: none
   */
  int length() const;

  /**
   * operator<<
   *
   * Outputs the string to an output stream.
   *
   * Parameters:
   * out: the output stream to write to
   * str: the MyString object to output
   *
   * Output:
   * return: reference to the output stream
   * reference parameters: none
   * stream: writes string contents to output stream
   */
  friend ostream &operator<<(ostream &, MyString &);
};

#endif
