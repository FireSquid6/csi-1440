#include <iostream>
#include <fstream>
#include "person.h"

const int MAX_PERSON_RECORDS = 25;
const string FILENAME = "people.dat";

int main() {
  Person* persons[MAX_PERSON_RECORDS];
  int size = 0;
  ifstream inFile;
  string line;

  inFile.open(FILENAME);

  if (!inFile.is_open()) {
    cout << "Error: failed to open " << FILENAME << endl;
    return 1;
  }

  while (getline(inFile, line)) {
    Person person;

    getAPersonFromStream(inFile, &person);

    persons[size] = &person;
    size += 1;
  } 


  for (int i = 0; i < size; i++) {
    displayAPerson(cout, persons[i]);
  }

  // free all memeory

}
