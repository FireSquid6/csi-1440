/**
 * file: proj9-testMain.cpp
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: Project 9
 * due date: 04/21/2025
 *
 * date modified: 04/21/2025
 * - file created
 *
 * This file contains tests for the MyList template class
 */

#include "proj9-MyList.h"
#include <cassert>
#include <iostream>
#include <cstddef>

using namespace std;

void testConstructor() {
  MyList<int> list;
  assert(list.isEmpty());
  assert(list.getSize() == 0);

  cout << "Default constructor test passed" << endl;
}

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

void testDestructor() {
  for (int i = 0; i < 100; i++) {
    MyList<int> list;
    for (int j = 0; j < 100; j++) {
      list.pushBack(j);
    }
    // list destructor will be called at end of loop
  }

  cout << "destructor test passed" << endl;
}

int main() {
  cout << "Starting MyList tests..." << endl;

  testConstructor();
  testPushFront();
  testPushBack();
  testPopFront();
  testPopBack();
  testFrontBack();
  testBracketOperator();
  testErase();
  testCopyConstructor();
  testAssignmentOperator();
  testDestructor();

  cout << "All tests passed!" << endl;

  return 0;
}
