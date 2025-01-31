/**
 * file: test.cpp
 * author: Prof. Aars
 * course: CSI 1440
 * assignment: project 1
 * due date: 1/24/2025
 *
 * date modified: 1/23/2025
 * - create the file
 *
 * Person.h contains functions for operating on lists of people
 *
 */
#ifndef PROJ1_PERSON_HPP
#define PROJ1_PERSON_HPP

#include <iostream>
#include <string>

using namespace std;

struct Person {
  string name;
  int age;
};

/**
 * getApersonFromStream
 *
 * reads a person from an input stream
 * <Name>, <age>
 *
 * Parameters:
 * istream: the stream to read from
 * Person - the person to read into
 *
 * Output:
 * return: the inputted istream
 */
istream &getAPersonFromStream(istream &, Person *);

/**
 * sortPersonArrayByAge
 *
 * sorts an array of people by age
 *
 * Parameters:
 * Person** - the array of people
 * int - size of array
 *
 * Output:
 * return: void
 */
void sortPersonArrayByAge(Person **, int);

/**
 * factorial
 *
 * This function computes the factorial of the given input. The factorial
 * is defined as factorial(n) = n! = n * (n-1) * (n-2) * ... * 2 * 1
 *
 * Parameters:
 * Person** - the array of people
 * int - size of array
 *
 * Output:
 * return: none
 */
void sortPersonArrayByName(Person **, int);

/**
 * factorial
 *
 * This function computes the factorial of the given input. The factorial
 * is defined as factorial(n) = n! = n * (n-1) * (n-2) * ... * 2 * 1
 *
 * Parameters:
 * Person** - the array of people
 * int - size of array
 * string - the name of the person to find
 *
 * Output:
 * return: pointer to the person that was found
 */
Person *findAPerson(Person **, int, string);

/**
 * factorial
 *
 * This function computes the factorial of the given input. The factorial
 * is defined as factorial(n) = n! = n * (n-1) * (n-2) * ... * 2 * 1
 *
 * Parameters:
 * ostream - the stream to display to
 * Person - pointer to a person to display
 *
 * Output:
 * return: none
 */
void displayAPerson(ostream &, const Person *);

#endif
