/**
 * file: proj9-TestMain.cpp
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: Project 9
 * due date: 04/16/2025
 *
 * date modified: 04/16/2025
 * - file created
 *
 * This file contains tests for the MyList template class
 */

#include <iostream>
#include <cassert>
#include "proj9-MyList.h"

using namespace std;

/**
 * testConstructor
 *
 * Tests the default constructor for MyList
 */
void testConstructor() {
  MyList<int> list;
  assert(list.isEmpty());
  assert(list.getSize() == 0);
  
  cout << "Default constructor test passed" << endl;
}

/**
 * testPushFront
 *
 * Tests the pushFront method for MyList
 */
void testPushFront() {
  MyList<int> list;
  
  list.pushFront(10);
  assert(list.getSize() == 1);
  assert(list.front() == 10);
  assert(list.back() == 10);
  
  list.pushFront(20);
  assert(list.getSize() == 2);
  assert(list.front() == 20);
  assert(list.back() == 10);
  
  list.pushFront(30);
  assert(list.getSize() == 3);
  assert(list.front() == 30);
  assert(list.back() == 10);
  
  cout << "pushFront test passed" << endl;
}

/**
 * testPushBack
 *
 * Tests the pushBack method for MyList
 */
void testPushBack() {
  MyList<int> list;
  
  list.pushBack(10);
  assert(list.getSize() == 1);
  assert(list.front() == 10);
  assert(list.back() == 10);
  
  list.pushBack(20);
  assert(list.getSize() == 2);
  assert(list.front() == 10);
  assert(list.back() == 20);
  
  list.pushBack(30);
  assert(list.getSize() == 3);
  assert(list.front() == 10);
  assert(list.back() == 30);
  
  cout << "pushBack test passed" << endl;
}

/**
 * testPopFront
 *
 * Tests the popFront method for MyList
 */
void testPopFront() {
  MyList<int> list;
  int value;
  
  // Test with multiple elements
  list.pushBack(10);
  list.pushBack(20);
  list.pushBack(30);
  
  list.popFront(value);
  assert(value == 10);
  assert(list.getSize() == 2);
  assert(list.front() == 20);
  
  list.popFront(value);
  assert(value == 20);
  assert(list.getSize() == 1);
  assert(list.front() == 30);
  
  list.popFront(value);
  assert(value == 30);
  assert(list.getSize() == 0);
  assert(list.isEmpty());
  
  // Test exception on empty list
  bool exceptionThrown = false;
  try {
    list.popFront(value);
  } catch (BADINDEX) {
    exceptionThrown = true;
  }
  assert(exceptionThrown);
  
  cout << "popFront test passed" << endl;
}

/**
 * testPopBack
 *
 * Tests the popBack method for MyList
 */
void testPopBack() {
  MyList<int> list;
  int value;
  
  // Test with multiple elements
  list.pushBack(10);
  list.pushBack(20);
  list.pushBack(30);
  
  list.popBack(value);
  assert(value == 30);
  assert(list.getSize() == 2);
  assert(list.back() == 20);
  
  list.popBack(value);
  assert(value == 20);
  assert(list.getSize() == 1);
  assert(list.back() == 10);
  
  list.popBack(value);
  assert(value == 10);
  assert(list.getSize() == 0);
  assert(list.isEmpty());
  
  // Test exception on empty list
  bool exceptionThrown = false;
  try {
    list.popBack(value);
  } catch (BADINDEX) {
    exceptionThrown = true;
  }
  assert(exceptionThrown);
  
  cout << "popBack test passed" << endl;
}

/**
 * testFrontBack
 *
 * Tests the front and back methods for MyList
 */
void testFrontBack() {
  MyList<int> list;
  
  // Test exceptions on empty list
  bool frontExceptionThrown = false;
  bool backExceptionThrown = false;
  
  try {
    list.front();
  } catch (BADINDEX) {
    frontExceptionThrown = true;
  }
  assert(frontExceptionThrown);
  
  try {
    list.back();
  } catch (BADINDEX) {
    backExceptionThrown = true;
  }
  assert(backExceptionThrown);
  
  // Test with one element
  list.pushBack(10);
  assert(list.front() == 10);
  assert(list.back() == 10);
  
  // Test with multiple elements
  list.pushBack(20);
  list.pushBack(30);
  assert(list.front() == 10);
  assert(list.back() == 30);
  
  cout << "front and back test passed" << endl;
}

/**
 * testBracketOperator
 *
 * Tests the [] operator for MyList
 */
void testBracketOperator() {
  MyList<int> list;
  
  // Test exception on empty list
  bool exceptionThrown = false;
  try {
    list[0];
  } catch (BADINDEX) {
    exceptionThrown = true;
  }
  assert(exceptionThrown);
  
  // Test with multiple elements
  list.pushBack(10);
  list.pushBack(20);
  list.pushBack(30);
  
  assert(list[0] == 10);
  assert(list[1] == 20);
  assert(list[2] == 30);
  
  // Test modification via reference
  list[1] = 25;
  assert(list[1] == 25);
  
  // Test exception on negative index
  exceptionThrown = false;
  try {
    list[-1];
  } catch (BADINDEX) {
    exceptionThrown = true;
  }
  assert(exceptionThrown);
  
  // Test exception on out-of-bounds index
  exceptionThrown = false;
  try {
    list[3];
  } catch (BADINDEX) {
    exceptionThrown = true;
  }
  assert(exceptionThrown);
  
  cout << "bracket operator test passed" << endl;
}

/**
 * testErase
 *
 * Tests the erase method for MyList
 */
void testErase() {
  MyList<int> list;
  
  // Test on empty list
  list.erase();
  assert(list.isEmpty());
  
  // Test with multiple elements
  list.pushBack(10);
  list.pushBack(20);
  list.pushBack(30);
  
  list.erase();
  assert(list.isEmpty());
  assert(list.getSize() == 0);
  
  // Make sure we can still add elements after erasing
  list.pushBack(40);
  assert(list.getSize() == 1);
  assert(list.front() == 40);
  
  cout << "erase test passed" << endl;
}

/**
 * testCopyConstructor
 *
 * Tests the copy constructor for MyList
 */
void testCopyConstructor() {
  MyList<int> original;
  
  // Test with empty list
  MyList<int> emptyCopy(original);
  assert(emptyCopy.isEmpty());
  
  // Test with populated list
  original.pushBack(10);
  original.pushBack(20);
  original.pushBack(30);
  
  MyList<int> copy(original);
  assert(copy.getSize() == 3);
  assert(copy[0] == 10);
  assert(copy[1] == 20);
  assert(copy[2] == 30);
  
  // Test independence of copies
  copy[1] = 25;
  assert(copy[1] == 25);
  assert(original[1] == 20);
  
  cout << "copy constructor test passed" << endl;
}

/**
 * testAssignmentOperator
 *
 * Tests the assignment operator for MyList
 */
void testAssignmentOperator() {
  MyList<int> list1;
  MyList<int> list2;
  
  // Test assigning from empty list
  list2 = list1;
  assert(list2.isEmpty());
  
  // Test assigning from populated list
  list1.pushBack(10);
  list1.pushBack(20);
  list1.pushBack(30);
  
  list2 = list1;
  assert(list2.getSize() == 3);
  assert(list2[0] == 10);
  assert(list2[1] == 20);
  assert(list2[2] == 30);
  
  // Test independence of lists after assignment
  list2[1] = 25;
  assert(list2[1] == 25);
  assert(list1[1] == 20);
  
  // Test self-assignment
  list1 = list1;
  assert(list1.getSize() == 3);
  assert(list1[0] == 10);
  assert(list1[1] == 20);
  assert(list1[2] == 30);
  
  cout << "assignment operator test passed" << endl;
}

/**
 * testChaining
 *
 * Tests method chaining for MyList
 */
void testChaining() {
  MyList<int> list;
  
  // Test chaining pushFront
  list.pushFront(10).pushFront(20).pushFront(30);
  assert(list.getSize() == 3);
  assert(list[0] == 30);
  assert(list[1] == 20);
  assert(list[2] == 10);
  
  list.erase();
  
  // Test chaining pushBack
  list.pushBack(10).pushBack(20).pushBack(30);
  assert(list.getSize() == 3);
  assert(list[0] == 10);
  assert(list[1] == 20);
  assert(list[2] == 30);
  
  // Test chaining popFront
  int val1, val2;
  list.popFront(val1).popFront(val2);
  assert(val1 == 10);
  assert(val2 == 20);
  assert(list.getSize() == 1);
  
  cout << "method chaining test passed" << endl;
}

/**
 * testDestructor
 *
 * Tests the destructor for MyList
 * (This is more of a memory leak check that would be
 * verified with tools like valgrind)
 */
void testDestructor() {
  // Create and destroy many lists
  for (int i = 0; i < 100; i++) {
    MyList<int> list;
    for (int j = 0; j < 100; j++) {
      list.pushBack(j);
    }
    // list destructor will be called at end of loop
  }
  
  cout << "destructor test passed (check for memory leaks separately)" << endl;
}

int main() {
  cout << "Starting MyList tests..." << endl;
  
  testConstructor();
  testPushFront();
  testPushBack();
  testPopFront();
  testPopBack();
  testFrontBack(
