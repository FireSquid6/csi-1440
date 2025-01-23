#include "person.h"

// reads a single Person from the stream
istream &getAPersonFromStream(istream &stream, Person *person) {
    string name;
    int age;

    getline(stream, name, ',');
    stream >> age;

    // TODO: fix me
    // segfault happening here
    person->name = name;
    person->age = age;

    return stream;
}

// implements selection sort ascending order
void sortPersonArrayByAge(Person **persons, int size) {
    bool swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = false;

        for (int j = 0; j < size - i - 1; j++) {
            if (persons[j]->age > persons[j+1]->age) {
                swap(persons[j], persons[j+1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

}
// implements bubble sort ascending order
void sortPersonArrayByName(Person **persons, int size) {
    bool swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = false;

        for (int j = 0; j < size - i - 1; j++) {
            if (persons[j]->name > persons[j+1]->name) {
                swap(persons[j], persons[j+1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

}

// implements linear search
Person* findAPerson(Person **persons, int size, string name) {
    for (int i = 0; i < size; i ++) {
        if (persons[i]->name == name) {
            return persons[i];
        }
    }

    return nullptr;
}

// writes a single Person to the stream
void displayAPerson(ostream &stream, const Person *person)  {
    stream 
        << person->name
        << ", "
        << person->age;
}
