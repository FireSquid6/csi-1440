#include <iostream>
#include <cassert>
#include <string>
#include "proj5-BUAthleteList.h"

using namespace std;

void testResult(const std::string& testName, bool passed) {
    std::cout << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

void testDefaultConstructor() {
    BUAthleteList list;
    bool passed = (list.toString() == "");
    testResult("Default Constructor", passed);
}

void testAddNCAAAthlete() {
    BUAthleteList list;
    list.addNCAAAthlete(1001, "John Doe", "Yes", "Baylor University");
    list.addNCAAAthlete(1002, "Jane Smith", "No", "University of Texas");
    
    bool passed = (list.findById(1001) == 0 && list.findById(1002) == 1);
    testResult("Add NCAA Athlete", passed);
}

void testSetBUInfo() {
    BUAthleteList list;
    list.addNCAAAthlete(1001, "John Doe", "Yes", "Baylor University");
    list.setBUInfo(0, Position::CB, 85);
    
    BUAthlete& athlete = list[0];
    bool passed = (athlete.getPosition() == Position::CB && athlete.getEvaluation() == 85);
    testResult("Set BU Info", passed);
}

void testFindById() {
    BUAthleteList list;
    list.addNCAAAthlete(1001, "John Doe", "Yes", "Baylor University");
    list.addNCAAAthlete(1002, "Jane Smith", "No", "University of Texas");
    list.addNCAAAthlete(1003, "Bob Johnson", "Yes", "MIT");
    
    bool passed = (list.findById(1001) == 0 && 
                  list.findById(1002) == 1 && 
                  list.findById(1003) == 2 && 
                  list.findById(9999) == -1);
    testResult("Find By ID", passed);
}

void testSortByID() {
    BUAthleteList list;
    list.addNCAAAthlete(1003, "Bob Johnson", "Yes", "Baylor University");
    list.addNCAAAthlete(1001, "John Doe", "Yes", "University of Texas");
    list.addNCAAAthlete(1002, "Jane Smith", "No", "MIT");
    
    list.sortByID();
    
    bool passed = (list[0].getID() == 1001 && 
                  list[1].getID() == 1002 && 
                  list[2].getID() == 1003);
    testResult("Sort By ID", passed);
}

void testSortByPosition() {
    BUAthleteList list;
    list.addNCAAAthlete(1001, "John Doe", "Yes", "Baylor University");
    list.addNCAAAthlete(1002, "Jane Smith", "No", "University of Texas");
    list.addNCAAAthlete(1003, "Bob Johnson", "Yes", "MIT");
    
    list.setBUInfo(0, Position::CB, 85);
    list.setBUInfo(1, Position::QB, 78);
    list.setBUInfo(2, Position::RB, 92);
    
    list.sortByPosition();
    
    bool passed = (list[0].getPosition() == Position::OL && 
                  list[1].getPosition() == Position::QB && 
                  list[2].getPosition() == Position::RB);
    testResult("Sort By Position", passed);
}

void testCopyConstructor() {
    BUAthleteList original;
    original.addNCAAAthlete(1001, "John Doe", "Yes", "Baylor University");
    original.setBUInfo(0, Position::QB, 85);
    
    BUAthleteList copy(original);
    
    bool passed = (copy.findById(1001) == 0 && 
                  copy[0].getPosition() == Position::QB && 
                  copy[0].getEvaluation() == 85);
    testResult("Copy Constructor", passed);
}

// Test assignment operator
void testAssignmentOperator() {
    BUAthleteList list1;
    list1.addNCAAAthlete(1001, "John Doe", "Yes", "Baylor University");
    list1.setBUInfo(0, Position::QB, 85);
    
    BUAthleteList list2;
    list2 = list1;
    
    bool passed = (list2.findById(1001) == 0 && 
                  list2[0].getPosition() == Position::QB && 
                  list2[0].getEvaluation() == 85);
    testResult("Assignment Operator", passed);
}

// Test bracket operator
void testBracketOperator() {
    BUAthleteList list;
    list.addNCAAAthlete(1001, "John Doe", "Yes", "Baylor University");
    
    BUAthlete& athlete = list[0];
    athlete.setPosition(Position::CB);
    athlete.setEvaluation(90);
    
    bool passed = (list[0].getPosition() == Position::CB && 
                  list[0].getEvaluation() == 90);
    testResult("Bracket Operator", passed);
}

// Test toString method
void testToString() {
    BUAthleteList list;
    list.addNCAAAthlete(1001, "John Doe", "Yes", "Baylor University");
    list.setBUInfo(0, Position::QB, 85);
    
    std::string result = list.toString();
    bool passed = (result.find("1001") != std::string::npos && 
                  result.find("John Doe") != std::string::npos &&
                  result.find("Boston University") != std::string::npos);
    testResult("ToString", passed);
}

void testResize() {
    BUAthleteList list;
    // Assuming the initial capacity is small, adding many athletes should trigger resize
    for (int i = 0; i < 50; i++) {
        list.addNCAAAthlete(1000 + i, "Athlete " + std::to_string(i), "Yes", "School " + std::to_string(i));
    }
    
    bool passed = true;
    for (int i = 0; i < 50; i++) {
        if (list.findById(1000 + i) != i) {
            passed = false;
            break;
        }
    }
    testResult("Resize Array", passed);
}

void testInvalidIndex() {
    BUAthleteList list;
    list.addNCAAAthlete(1001, "John Doe", "Yes", "Boston University");
    
    try {
        BUAthlete& athlete = list[5]; // This should throw an exception or handle the error
        testResult("Invalid Index", false);
    } catch (const std::exception&) {
        testResult("Invalid Index", true);
    }
}

int main() {
    std::cout << "Running BUAthleteList Tests..." << std::endl;
    
    testDefaultConstructor();
    testAddNCAAAthlete();
    testSetBUInfo();
    testFindById();
    testSortByID();
    testSortByPosition();
    testCopyConstructor();
    testAssignmentOperator();
    testBracketOperator();
    testToString();
    testResize();
    testInvalidIndex();
    
    std::cout << "All tests completed." << std::endl;
    return 0;
}
