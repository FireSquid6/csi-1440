#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const string inFile = "iperson.txt";
const string outFile = "operson.txt";

int main() {
  string name;
  int age;

  string choice = "yes";
  bool usingFile = false;
  ifstream pfile;
  ofstream opfile;

  cout << "Would you like to read data from a file? " << endl;
  cin >> choice;
  cin.ignore(3, '\n');

  usingFile = choice == "yes";

  if (usingFile) {
    pfile.open("iperson.txt");
    if (!pfile) {
      cerr << "Can't open person.txt for read." << endl;
      return 1;
    }
  }

  opfile.open("operson.txt");

  choice = "yes";

  while( choice != "no" ) {
    if (!usingFile) {
      cout << "Do you want to read in another person (yes/no)? " << endl;
      cin >> choice;
      cin.ignore(3, '\n');
    } else {
      getline(pfile, name);
      pfile >> age;
      pfile.ignore(3, '\n');

      if (!pfile) {
        choice = "no";
      }
    }
  }

  if (usingFile) {
    pfile.close();
  }

  opfile.close();

  return 0;
}
