/**
* file: proj6-sequentalMain3.cpp
* author: Jonathan Deiss
* course: CSI 1440
* assignment: project 6
* due date: 3/30/2025
*
* date modified: 3/30/2025
* - create the file
* 
* Contains the first program using sequential programming
*
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// this only ever reads the first person from the file
// I think that is intentional? The modular solution was
// doing that as well on my machine
int main() {
  string name, choice;
  int age;
  bool fileRead = false;
  ifstream pfile;
  ofstream opfile;

  cout << "Would you like to read the data from a file? " << endl;
  cin >> choice;
  cin.ignore(3, '\n');

  if (choice == "yes") {
    fileRead = true;
    pfile.open("iperson.txt");
    if (!pfile) {
      cerr << "Can't open person.txt for read." << endl;
      return 1;
    }
  }

  opfile.open("operson.txt");

  choice = "yes";
  if (fileRead) {
    // readPerson pfile, name, age
    getline(pfile, name);
    pfile >> age;
    pfile.ignore(3, '\n');
    if (!pfile) {
      choice = "no";
    }
  }

  while (choice != "no") {
    if (!fileRead) {
      // requestInfo 
      cout << "Please enter your name followed by your age." << endl;
      
      // readPerson cin, name, age
      getline(cin, name);
      cin >> age;
      cin.ignore(3, '\n');
    }

    // writePerson name, age
    opfile << name << endl;
    opfile << age << endl;

    if (!fileRead) {
      // readAgain cin, choice
      cout << "Do you want to read in another person (yes/no)? " << endl;
      cin >> choice;
      cin.ignore(3, '\n');
    } else {
      // readPerson pfile, name, age
      getline(pfile, name);
      pfile >> age;
      pfile.ignore(3, '\n');

      if (!pfile) {
        choice = "no";
      }
    }
  }

  if (fileRead) {
    pfile.close();
  }
  opfile.close();

  return 0;
}
