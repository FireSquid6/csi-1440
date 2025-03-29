#include <iostream>
#include <string>

using namespace std;

void readPerson( istream &in, string &name, int &age ) {
  getline( in, name );
  in >> age;
}

void requestInfo( ostream &out ) {
  out << "Please enter your name followed by your age." << endl;
}

void displayPerson( ostream &out, string name, int age ) {
  out << "Your name is: " << name << endl;
  out << "You are " << age << " years old" << endl;
}

string readAgain( ostream &out, istream &in ) {
  string choice;

  out << "Do you want to read in another person (yes/no)? " << endl;
  in >> choice;
  in.ignore(3, '\n');

  return choice;
}

int main() {
  string name;
  int age;
  string choice = "yes";

  while( choice != "no" ) {
    requestInfo( cout );
    readPerson( cin, name, age );
    displayPerson( cout, name, age );
    choice = readAgain( cout, cin );
  }

  return 0;
}
