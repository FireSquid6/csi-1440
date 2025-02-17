#include "lab4-IntArray.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const string DATAFILE_NAME = "datafile.txt";

void makeDatafile() {
  ofstream file;
  file.open(DATAFILE_NAME);

  for (int i = 0; i < 10; i++) {
    file << i * i << " ";
  }
  file << endl;
  file.close();
}

void readDatafileIntoArray(IntArray *array) {
  ifstream file;
  file.open(DATAFILE_NAME);

  if (!file.is_open()) {
    return;
  }

  int n;

  while (file >> n) {
    array->insertVal(n);
  }

  file.close();
}

void testConstructors() {
  IntArray list1;

  readDatafileIntoArray(&list1);
  IntArray list2 = IntArray(list1);
  IntArray list3 = list1;

  // all of them should be equal right now

  assert(list1.getSize() == list2.getSize());
  assert(list1.getSize() == list3.getSize());

  for (int i = 0; i < list1.getSize(); i++) {
    assert(list1.getVal(i) == list2.getVal(i));
    assert(list1.getVal(i) == list3.getVal(i));
  }


  cout << "testConstructors PASSED" << endl;
}


// we test these together since it allows us to also
// test the resizing up and down features
void testInsertAndRemove() {
  IntArray list;
  list.insertVal(5);

  assert(list.getSize() == 1);
  assert(list.getVal(0) == 5);

  list.insertVal(4);

  int removed = list.removeVal();

  assert(removed == 4);
  assert(list.getSize() == 1);


  // add and remove a bunch
  for (int i = 0; i < 20; i++) {
    list.insertVal(i);
  }

  assert(list.getSize() == 21);

  // remove all but 1
  for (int i = 0; i < 20; i++) {
    list.removeVal();
  }

  assert(list.getSize() == 1);
  assert(list.getCapacity() == 5);

  cout << "testInsertAndRemove PASSED" << endl;
}

void modifyAPassedByValue(IntArray list) {
  list.insertVal(5);

  assert(list.getSize() == 5);
}

void testPassByValue() {
  IntArray list;
  list.insertVal(1);
  list.insertVal(2);
  list.insertVal(3);
  list.insertVal(4);
  assert(list.getSize() == 4);
  
  modifyAPassedByValue(list);

  assert(list.getSize() == 4);

  cout << "testPassByValue PASSED" << endl;
}


int main() {
  // uncomment this to create a non-empty datafile
  // it will still work with no file, just will copy an
  // empty array
  // makeDatafile();

  testConstructors();
  testInsertAndRemove();
  testPassByValue();
}
