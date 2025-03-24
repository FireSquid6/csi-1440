/**
* file: proj5-testmain.cpp
* author: Jonathan Deiss
* course: CSI 1440
* assignment: project 5
* due date: 3/23/2025
*
* date modified: 3/23/2025
* - create the file
* 
* Contains tests for the BUAthlete and BUAthleteList classes
*
*/
#include "proj5-BUAthleteList.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void testResult(const string &testName, bool passed) {
  // the extra stuff in the FAILED message makes it show red in a terminal
  // this is a cool trick I learned and I'm proud of
  cout << testName << ": " << (passed ? "PASSED" : "\e[31mFAILED\e[0m") << endl;
}

void testDefaultConstructor() {
  BUAthleteList list;
  bool passed = (list.toString() == "");
  testResult("Default Constructor", passed);
}

void testAddNCAAAthlete() {
  BUAthleteList list;
  list.addNCAAAthlete(1001, "John Doe", "yes", "Baylor University");
  list.addNCAAAthlete(1002, "Jane Smith", "no", "University of Texas");

  bool passed = (list.findById(1001) == 0 && list.findById(1002) == 1);
  testResult("Add NCAA Athlete", passed);
}

void testSetBUInfo() {
  BUAthleteList list;
  list.addNCAAAthlete(1001, "John Doe", "yes", "Baylor University");
  list.setBUInfo(0, QB, 85);

  BUAthlete &athlete = list[0];
  bool passed = (athlete.getPosition() == QB && athlete.getEvaluation() == 85);
  testResult("Set BU Info", passed);
}

void testFindById() {
  BUAthleteList list;
  list.addNCAAAthlete(1001, "John Doe", "yes", "Baylor University");
  list.addNCAAAthlete(1002, "Jane Smith", "no", "University of Texas");
  list.addNCAAAthlete(1003, "Bob Johnson", "yes", "TCU");

  bool passed = (list.findById(1001) == 0 && list.findById(1002) == 1 &&
                 list.findById(1003) == 2 && list.findById(9999) == -1);
  testResult("Find By ID", passed);
}

void testSortByID() {
  BUAthleteList list;
  list.addNCAAAthlete(1003, "Bob Johnson", "yes", "TCU");
  list.addNCAAAthlete(1001, "John Doe", "yes", "Baylor University");
  list.addNCAAAthlete(1002, "Jane Smith", "no", "University of Texas");

  list.sortByID();

  bool passed = (list[0].getID() == 1001 && list[1].getID() == 1002 &&
                 list[2].getID() == 1003);
  testResult("Sort By ID", passed);
}

void testSortByPosition() {
  BUAthleteList list;
  list.addNCAAAthlete(1001, "John Doe", "yes", "Baylor University");
  list.addNCAAAthlete(1002, "Jane Smith", "no", "University of Texas");
  list.addNCAAAthlete(1003, "Bob Johnson", "yes", "TCU");

  list.setBUInfo(0, WR, 85);
  list.setBUInfo(1, QB, 78);
  list.setBUInfo(2, RB, 92);

  list.sortByPosition();

  // Assuming positions are sorted in ascending order (QB < RB < WR)
  bool passed = (list[0].getPosition() == QB && list[1].getPosition() == RB &&
                 list[2].getPosition() == WR);
  testResult("Sort By Position", passed);
}

void testCopyConstructor() {
  BUAthleteList original;
  original.addNCAAAthlete(1001, "John Doe", "yes", "Baylor University");
  original.setBUInfo(0, WR, 85);

  BUAthleteList copy(original);

  bool passed = (copy.findById(1001) == 0 && copy[0].getPosition() == WR &&
                 copy[0].getEvaluation() == 85);
  testResult("Copy Constructor", passed);
}

void testAssignmentOperator() {
  BUAthleteList list1;
  list1.addNCAAAthlete(1001, "John Doe", "yes", "Baylor University");
  list1.setBUInfo(0, WR, 85);

  BUAthleteList list2;
  list2 = list1;

  bool passed = (list2.findById(1001) == 0 && list2[0].getPosition() == WR &&
                 list2[0].getEvaluation() == 85);
  testResult("Assignment Operator", passed);
}

void testBracketOperator() {
  BUAthleteList list;
  list.addNCAAAthlete(1001, "John Doe", "yes", "Baylor University");

  BUAthlete &athlete = list[0];
  athlete.setPosition(TE);
  athlete.setEvaluation(90);

  bool passed = (list[0].getPosition() == TE && list[0].getEvaluation() == 90);
  testResult("Bracket Operator", passed);
}

// Test toString method
void testToString() {
  BUAthleteList list;
  list.addNCAAAthlete(1001, "John Doe", "yes", "Baylor University");
  list.setBUInfo(0, WR, 85);

  list.addNCAAAthlete(1002, "Jane Smith", "no", "University of Texas");
  list.setBUInfo(1, QB, 90);

  string result = list.toString();
  stringstream ss;

  ss << "[ 0 ]\n"
        "ID: 1001\n"
        "Name: John Doe\n"
        "School: Baylor University\n"
        "Evaluation: 85\n"
        "Position: WR\n";
  ss << endl;

  ss << "[ 1 ]\n"
        "ID: 1002\n"
        "Name: Jane Smith\n"
        "School: Available\n" // LOI is "No", so "Available" should be shown
        "Evaluation: 90\n"
        "Position: QB\n";
  ss << endl;

  string expected = ss.str();

  testResult("ToString", expected == result);
}

void testResize() {
  BUAthleteList list;
  // Assuming the initial capacity is small, adding many athletes should trigger
  // resize
  for (int i = 0; i < 50; i++) {
    list.addNCAAAthlete(1000 + i, "Athlete " + to_string(i), "yes",
                        "Baylor University");
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

void testMultiplePositions() {
  BUAthleteList list;
  list.addNCAAAthlete(1001, "John Doe", "yes", "Baylor University");
  list.addNCAAAthlete(1002, "Jane Smith", "no", "University of Texas");
  list.addNCAAAthlete(1003, "Bob Johnson", "yes", "TCU");
  list.addNCAAAthlete(1004, "Mike Wilson", "no", "Baylor University");
  list.addNCAAAthlete(1005, "Sarah Brown", "yes", "University of Texas");

  list.setBUInfo(0, QB, 92); // Quarterback
  list.setBUInfo(1, RB, 88); // Running Back
  list.setBUInfo(2, WR, 85); // Wide Receiver
  list.setBUInfo(3, TE, 78); // Tight End
  list.setBUInfo(4, OL, 90); // Offensive Line

  bool passed = (list[0].getPosition() == QB && list[1].getPosition() == RB &&
                 list[2].getPosition() == WR && list[3].getPosition() == TE &&
                 list[4].getPosition() == OL);
  testResult("Multiple Positions", passed);
}

void testDefensivePositions() {
  BUAthleteList list;
  list.addNCAAAthlete(1001, "John Doe", "yes", "Baylor University");
  list.addNCAAAthlete(1002, "Jane Smith", "no", "University of Texas");
  list.addNCAAAthlete(1003, "Bob Johnson", "yes", "TCU");
  list.addNCAAAthlete(1004, "Mike Wilson", "no", "Baylor University");

  list.setBUInfo(0, DL, 90); // Defensive Line
  list.setBUInfo(1, DE, 85); // Defensive End
  list.setBUInfo(2, LB, 87); // Linebacker
  list.setBUInfo(3, CB, 82); // Cornerback

  bool passed = (list[0].getPosition() == DL && list[1].getPosition() == DE &&
                 list[2].getPosition() == LB && list[3].getPosition() == CB);
  testResult("Defensive Positions", passed);
}

void testBUAthleteDefaultConstructor() {
  BUAthlete athlete;
  bool passed =
      (athlete.getEvaluation() == 0 &&
       athlete.getPosition() == OL); // Assuming OL is the default position
  testResult("BUAthlete Default Constructor", passed);
}

// Test BUAthlete setters and getters
void testBUAthleteSettersGetters() {
  BUAthlete athlete;

  athlete.setEvaluation(95);
  athlete.setPosition(QB);

  bool passed = (athlete.getEvaluation() == 95 && athlete.getPosition() == QB);
  testResult("BUAthlete Setters/Getters", passed);
}

// Test BUAthlete inheritance from NCAAAthlete
void testBUAthleteInheritance() {
  BUAthlete athlete;

  athlete.setID(2001);
  athlete.setName("John Doe");
  athlete.setSchool("Baylor University");
  athlete.setLOI("yes");
  athlete.setPosition(QB);
  athlete.setEvaluation(99);

  bool passed =
      (athlete.getID() == 2001 && athlete.getName() == "John Doe" &&
       athlete.getSchool() == "Baylor University" && athlete.getLOI() == true &&
       athlete.getPosition() == QB && athlete.getEvaluation() == 99);
  testResult("BUAthlete Inheritance", passed);
}

void testBUAthleteToString() {
  BUAthlete athlete;

  athlete.setID(2001);
  athlete.setName("Sawyer Robertson");
  athlete.setSchool("Baylor University");
  athlete.setLOI("yes");
  athlete.setPosition(QB);
  athlete.setEvaluation(99);

  string result = athlete.toString();

  // Expected format for the athlete without the [n] part
  string expected = "ID: 2001\n"
                    "Name: Sawyer Robertson\n"
                    "School: Baylor University\n"
                    "Evaluation: 99\n"
                    "Position: QB\n";

  bool passed = (result == expected);
  testResult("BUAthlete ToString", passed);
}

void testBUAthleteEvaluation() {
  BUAthlete athlete;

  athlete.setEvaluation(100); // Assuming 100 is maximum
  bool passed = (athlete.getEvaluation() == 100);
  testResult("BUAthlete Evaluation", passed);
}

void testBUAthleteAllPositions() {
  BUAthlete athlete;

  Position positions[] = {OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K};
  bool allPassed = true;

  for (Position pos : positions) {
    athlete.setPosition(pos);
    if (athlete.getPosition() != pos) {
      allPassed = false;
      break;
    }
  }

  testResult("BUAthlete All Positions", allPassed);
}

int main() {
  cout << "Running BUAthleteList Tests..." << endl;

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
  testMultiplePositions();
  testDefensivePositions();

  cout << "\nRunning BUAthlete Tests..." << endl;
  testBUAthleteDefaultConstructor();
  testBUAthleteSettersGetters();
  testBUAthleteInheritance();
  testBUAthleteToString();
  testBUAthleteEvaluation();
  testBUAthleteAllPositions();

  cout << "All tests completed." << endl;
  return 0;
}
