/**
 * file: proj7-TestMain.cpp
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: Project 7
 * due date: 04/06/2025
 *
 * date modified: 04/01/2025
 * - file created
 *
 * Test driver for the MyVector class
 *
 */
#include "proj7-MyVector.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void testConstructors() {
  cout << "Testing constructors..." << endl;

  MyVector<int> vec1;
  assert(vec1.getSize() == 0);
  assert(vec1.isEmpty());

  MyVector<int> vec2;
  vec2.pushBack(10);
  vec2.pushBack(20);
  vec2.pushBack(30);

  MyVector<int> vec3(vec2);
  assert(vec3.getSize() == 3);
  assert(vec3[0] == 10);
  assert(vec3[1] == 20);
  assert(vec3[2] == 30);

  vec2.pushBack(40);
  assert(vec2.getSize() == 4);
  assert(vec3.getSize() == 3); 

  cout << "Constructor tests passed!" << endl;
}

void testAssignmentOperator() {
  cout << "Testing assignment operator..." << endl;

  MyVector<int> vec1;
  vec1.pushBack(10);
  vec1.pushBack(20);

  MyVector<int> vec2;
  vec2.pushBack(30);
  vec2.pushBack(40);
  vec2.pushBack(50);

  vec1 = vec2;
  assert(vec1.getSize() == 3);
  assert(vec1[0] == 30);
  assert(vec1[1] == 40);
  assert(vec1[2] == 50);

  vec2.pushBack(60);
  assert(vec2.getSize() == 4);
  assert(vec1.getSize() == 3); 

  vec1 = vec1;
  assert(vec1.getSize() == 3);
  assert(vec1[0] == 30);
  assert(vec1[1] == 40);
  assert(vec1[2] == 50);

  cout << "Assignment operator tests passed!" << endl;
}

void testPushFront() {
  cout << "Testing pushFront..." << endl;

  MyVector<int> vec;

  vec.pushFront(30);
  assert(vec.getSize() == 1);
  assert(vec[0] == 30);

  vec.pushFront(20);
  assert(vec.getSize() == 2);
  assert(vec[0] == 20);
  assert(vec[1] == 30);

  vec.pushFront(10);
  assert(vec.getSize() == 3);
  assert(vec[0] == 10);
  assert(vec[1] == 20);
  assert(vec[2] == 30);

  cout << "pushFront tests passed!" << endl;
}

void testPushBack() {
  cout << "Testing pushBack..." << endl;

  MyVector<int> vec;

  vec.pushBack(10);
  assert(vec.getSize() == 1);
  assert(vec[0] == 10);

  vec.pushBack(20);
  assert(vec.getSize() == 2);
  assert(vec[0] == 10);
  assert(vec[1] == 20);

  vec.pushBack(30);
  assert(vec.getSize() == 3);
  assert(vec[0] == 10);
  assert(vec[1] == 20);
  assert(vec[2] == 30);

  cout << "pushBack tests passed!" << endl;
}

void testPopFront() {
  cout << "Testing popFront..." << endl;

  MyVector<int> vec;
  vec.pushBack(10);
  vec.pushBack(20);
  vec.pushBack(30);

  int value;

  vec.popFront(value);
  assert(value == 10);
  assert(vec.getSize() == 2);
  assert(vec[0] == 20);
  assert(vec[1] == 30);

  vec.popFront(value);
  assert(value == 20);
  assert(vec.getSize() == 1);
  assert(vec[0] == 30);

  vec.popFront(value);
  assert(value == 30);
  assert(vec.getSize() == 0);
  assert(vec.isEmpty());

  cout << "popFront tests passed!" << endl;
}

void testPopBack() {
  cout << "Testing popBack..." << endl;

  MyVector<int> vec;
  vec.pushBack(10);
  vec.pushBack(20);
  vec.pushBack(30);

  int value;

  vec.popBack(value);
  assert(value == 30);
  assert(vec.getSize() == 2);
  assert(vec[0] == 10);
  assert(vec[1] == 20);

  vec.popBack(value);
  assert(value == 20);
  assert(vec.getSize() == 1);
  assert(vec[0] == 10);

  vec.popBack(value);
  assert(value == 10);
  assert(vec.getSize() == 0);
  assert(vec.isEmpty());

  cout << "popBack tests passed!" << endl;
}

void testFrontBack() {
  cout << "Testing front and back functions..." << endl;

  MyVector<int> vec;
  vec.pushBack(10);
  assert(vec.front() == 10);
  assert(vec.back() == 10);

  vec.pushBack(20);
  assert(vec.front() == 10);
  assert(vec.back() == 20);

  vec.pushFront(5);
  assert(vec.front() == 5);
  assert(vec.back() == 20);

  cout << "Front and back function tests passed!" << endl;
}

void testBracketOperator() {
  cout << "Testing bracket operator..." << endl;

  MyVector<int> vec;
  vec.pushBack(10);
  vec.pushBack(20);
  vec.pushBack(30);

  assert(vec[0] == 10);
  assert(vec[1] == 20);
  assert(vec[2] == 30);

  vec[1] = 25;
  assert(vec[1] == 25);

  bool exceptionCaught = false;
  try {
    // you might get a warning here for an unused
    // variable
    int _ = vec[3]; 
  } catch (BADINDEX) {
    exceptionCaught = true;
  }
  assert(exceptionCaught);

  cout << "Bracket operator tests passed!" << endl;
}

void testGetSize() {
  cout << "Testing getSize..." << endl;

  MyVector<int> vec;
  assert(vec.getSize() == 0);

  vec.pushBack(10);
  assert(vec.getSize() == 1);

  vec.pushBack(20);
  vec.pushFront(5);
  assert(vec.getSize() == 3);

  int value;
  vec.popBack(value);
  assert(vec.getSize() == 2);

  cout << "getSize tests passed!" << endl;
}

void testIsEmpty() {
  cout << "Testing isEmpty..." << endl;

  MyVector<int> vec;
  assert(vec.isEmpty());

  vec.pushBack(10);
  assert(!vec.isEmpty());

  int value;
  vec.popBack(value);
  assert(vec.isEmpty());

  cout << "isEmpty tests passed!" << endl;
}

void testErase() {
  cout << "Testing erase..." << endl;

  MyVector<int> vec;
  vec.pushBack(10);
  vec.pushBack(20);
  vec.pushBack(30);

  vec.erase();
  assert(vec.isEmpty());
  assert(vec.getSize() == 0);

  cout << "erase tests passed!" << endl;
}

void testEdgeCases() {
  cout << "Testing edge cases..." << endl;

  MyVector<int> vec;

  int value;
  bool exceptionCaught = false;

  try {
    vec.popFront(value);
  } catch (BADINDEX) {
    exceptionCaught = true;
  }

  assert(exceptionCaught);

  exceptionCaught = false;
  try {
    vec.popBack(value);
  } catch (BADINDEX) {
    exceptionCaught = true;
  }
  assert(exceptionCaught);

  exceptionCaught = false;
  try {
    vec.front();
  } catch (BADINDEX) {
    exceptionCaught = true;
  }
  assert(exceptionCaught);

  exceptionCaught = false;
  try {
    vec.back();
  } catch (BADINDEX) {
    exceptionCaught = true;
  }
  assert(exceptionCaught);

  cout << "Edge case tests passed!" << endl;
}

void testGrowFunctionality() {
  cout << "Testing grow functionality..." << endl;

  MyVector<int> vec;

  for (int i = 0; i < 100; i++) {
    vec.pushBack(i);
  }

  assert(vec.getSize() == 100);
  for (int i = 0; i < 100; i++) {
    assert(vec[i] == i);
  }

  cout << "Grow functionality tests passed!" << endl;
}

int main() {
  cout << "Starting MyVector test suite..." << endl;

  testConstructors();
  testAssignmentOperator();
  testPushFront();
  testPushBack();
  testPopFront();
  testPopBack();
  testFrontBack();
  testBracketOperator();
  testGetSize();
  testIsEmpty();
  testErase();
  testEdgeCases();
  testGrowFunctionality();

  cout << "All tests passed successfully!" << endl;
  return 0;
}
