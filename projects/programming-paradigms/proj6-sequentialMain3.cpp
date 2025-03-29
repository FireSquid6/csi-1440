#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
    // readPerson equivalent inline code
    getline(pfile, name);
    pfile >> age;
    pfile.ignore(3, '\n');
    if (!pfile) {
      choice = "no";
    }
  }

  while (choice != "no") {
    if (!fileRead) {
      // requestInfo equivalent inline code
      cout << "Please enter your name followed by your age." << endl;
      
      // readPerson equivalent inline code
      getline(cin, name);
      cin >> age;
      cin.ignore(3, '\n');
    }

    // writePerson equivalent inline code
    opfile << name << endl;
    opfile << age << endl;

    if (!fileRead) {
      // readAgain equivalent inline code
      cout << "Do you want to read in another person (yes/no)? " << endl;
      cin >> choice;
      cin.ignore(3, '\n');
    } else {
      // readPerson equivalent inline code
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
