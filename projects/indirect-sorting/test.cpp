#include "person.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

// we split it into multiple functions for readability
void testGetAPersonFromStream();
void testSortPersonArrayByAge();
void testSortPersonArrayByName();
void testFindAPerson();
void testDisplayAPerson();

int main() {
    testGetAPersonFromStream();
    testSortPersonArrayByAge();
    testSortPersonArrayByName();
    testFindAPerson();
    testDisplayAPerson();

    return 0;
}

void testGetAPersonFromStream() {
    istringstream input1("John, 25");
    Person person1;
    getAPersonFromStream(input1, &person1);
    assert(person1.name == "John");
    assert(person1.age == 25);

    istringstream input2("John Doe, 30");
    Person person2;
    getAPersonFromStream(input2, &person2);
    assert(person2.name == "John Doe");
    assert(person2.age == 30);

    cout << "getAPersonFromStream() tests passed!" << endl;
}

void testSortPersonArrayByAge() {
    Person *people[5];
    people[0] = new Person{"Alice", 30};
    people[1] = new Person{"Bob", 20};
    people[2] = new Person{"Charlie", 25};
    people[3] = new Person{"David", 35};
    people[4] = new Person{"Eve", 22};

    sortPersonArrayByAge(people, 5);

    // debug prints I needed
    // cout << people[0]->age << endl;
    // cout << people[1]->age << endl;
    // cout << people[2]->age << endl;
    // cout << people[3]->age << endl;
    // cout << people[4]->age << endl;

    assert(people[0]->age == 20);
    assert(people[1]->age == 22);
    assert(people[2]->age == 25);
    assert(people[3]->age == 30);
    assert(people[4]->age == 35);

    for (int i = 0; i < 5; i++) {
        delete people[i];
    }

    cout << "sortPersonArrayByAge() tests passed!" << endl;
}

void testSortPersonArrayByName() {
    Person *people[5];
    people[0] = new Person{"David", 35};
    people[1] = new Person{"Alice", 30};
    people[2] = new Person{"Eve", 22};
    people[3] = new Person{"Bob", 20};
    people[4] = new Person{"Charlie", 25};

    sortPersonArrayByName(people, 5);

    assert(people[0]->name == "Alice");
    assert(people[1]->name == "Bob");
    assert(people[2]->name == "Charlie");
    assert(people[3]->name == "David");
    assert(people[4]->name == "Eve");

    for (int i = 0; i < 5; i++) {
        delete people[i];
    }

    cout << "sortPersonArrayByName() tests passed!" << endl;
}

void testFindAPerson() {
    Person *people[5];
    people[0] = new Person{"Alice", 30};
    people[1] = new Person{"Bob", 20};
    people[2] = new Person{"Charlie", 25};
    people[3] = new Person{"David", 35};
    people[4] = new Person{"Eve", 22};

    Person *found = findAPerson(people, 5, "Charlie");
    assert(found != nullptr);
    assert(found->name == "Charlie");
    assert(found->age == 25);

    // person not in the list should be a nullptr
    found = findAPerson(people, 5, "Frank");
    assert(found == nullptr);

    for (int i = 0; i < 5; i++) {
        delete people[i];
    }

    cout << "findAPerson() tests passed!" << endl;
}

void testDisplayAPerson() {
    Person person{"Brodie Lawrence", 25};
    ostringstream output;
    displayAPerson(output, &person);
    assert(output.str() == "Brodie Lawrence, 25");

    cout << "displayAPerson() tests passed!" << endl;
}
