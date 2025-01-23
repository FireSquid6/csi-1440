/**
* file: main.cpp
* author: Prof. Aars
* course: CSI 1440
* assignment: project 1
* due date: 1/24/2025
*
* date modified: 1/23/2025
* - create the file
* 
* This file contains the entrypoint into the program and sorts a file of people
*
*/
#include "proj1-person.h"
#include <fstream>
#include <iostream>
#include <sstream>

const int MAX_PERSON_RECORDS = 25;
const string FILENAME = "people.dat";

int main() {
    Person *persons[MAX_PERSON_RECORDS];
    int size = 0;
    ifstream inFile;
    string line;

    inFile.open(FILENAME);

    if (!inFile.is_open()) {
        cout << "Error: failed to open " << FILENAME << endl;
        return 1;
    }

    while (getline(inFile, line)) {
        Person *person = new Person;
        stringstream ss;
        ss << line;

        getAPersonFromStream(ss, person);

        persons[size] = person;
        size += 1;
    }

    sortPersonArrayByAge(persons, size);

    cout << endl << "Sorted by age: " << endl;
    for (int i = 0; i < size || i < 5; i++) {
        displayAPerson(cout, persons[i]);
        cout << endl;
    }

    sortPersonArrayByName(persons, size);

    cout << endl << "Sorted by name: " << endl;
    for (int i = 0; i < size || i < 5; i++) {
        displayAPerson(cout, persons[i]);
        cout << endl;
    }

    string userInput = "";
    cout << endl;
    while (true) {
        cout << "Enter a name to find (or \"no more\" to quit): ";
        getline(cin, userInput);

        if (userInput == "no more") {
            cout << "Quitting" << endl;
            break;
        }

        Person *person = findAPerson(persons, size, userInput);
        if (person == nullptr) {
            cout << "not found" << endl;
        } else {
            cout << "found: ";
            displayAPerson(cout, person);
            cout << endl;
        }

        cout << endl;
    }

    // don't make a memory leak!
    for (int i = 0; i < size; i++) {
        delete persons[i];
    }
    inFile.close();

    return 0;
}
