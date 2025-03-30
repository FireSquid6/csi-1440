#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int PLIST_SIZE = 10;

// everything I know about modular programming and what online is
// telling me says that structs are part of it (At a prior job I
// did "modular programming" in go and we were allowed to use structs)
//
// If this isn't what you wanted just pretend I did the same thing
// but with parallel arrays or something. I did it this way because
// it's more readable
struct Person {
  string name;
  int age;
};

struct Customer {
  string name;
  int age;
  double shippingRate;
};

void readPerson(istream &in, Person &person) {
  getline(in, person.name);
  in >> person.age;
  in.ignore(3, '\n');
}

void writePerson(ostream &out, const Person &person) {
  out << person.name << endl;
  out << person.age << endl;
}

void readCustomer(istream &in, Customer &customer) {
  getline(in, customer.name);
  in >> customer.age;
  in.ignore(3, '\n');
  in >> customer.shippingRate;
  in.ignore(3, '\n');
}

void writeCustomer(ostream &out, const Customer &customer) {
  out << customer.name << endl;
  out << customer.age << endl;
  out << customer.shippingRate << endl;
}

void requestInfo(ostream &out, string msg) { out << msg << endl; }

string readAgain(ostream &out, istream &in) {
  string choice;

  out << "Do you want to read in another person (yes/no)? " << endl;
  in >> choice;
  in.ignore(3, '\n');

  return choice;
}

int findPerson(const Person pList[], int count, string name) {
  int pos = -1;

  for (int i = 0; i < count; i++) {
    if (pList[i].name == name) {
      pos = i;
      break;
    }
  }

  return pos;
}

int findCustomer(const Customer cList[], int count, string name) {
  int pos = -1;

  for (int i = 0; i < count; i++) {
    if (cList[i].name == name) {
      pos = i;
      break;
    }
  }

  return pos;
}

int main() {
  Person pList[PLIST_SIZE];
  Customer cList[PLIST_SIZE];
  string choice, pTypeChoice;
  int index = 0;
  bool fileRead = false;
  ifstream pfile;
  ofstream opfile;

  cout << "Would you like to read the data from a file (yes/no)? " << endl;
  cin >> choice;
  cin.ignore(3, '\n');

  if (choice == "yes") {
    fileRead = true;
    pfile.open("iperson.txt");
    if (!pfile) {
      cerr << "Can't open person.txt for read." << endl;
      return 1;
    }

    pfile >> pTypeChoice;
    pfile.ignore(3, '\n');
  } else {
    cout << "What type of Person? (person/customer)" << endl;
    cin >> pTypeChoice;
    cin.ignore(3, '\n');
  }

  if (pTypeChoice == "person") {
    opfile.open("operson.txt");
    choice = "yes";

    if (fileRead) {
      readPerson(pfile, pList[index]);
      if (!pfile) {
        choice = "no";
      }
    }

    while (choice != "no" && index < PLIST_SIZE) {
      if (!fileRead) {
        requestInfo(cout, "Please enter your name followed by your age.");
        readPerson(cin, pList[index]);
      }

      writePerson(opfile, pList[index]);

      index++;
      if (!fileRead) {
        choice = readAgain(cout, cin);
      } else {
        if (index < PLIST_SIZE) {
          readPerson(pfile, pList[index]);
          if (!pfile) {
            choice = "no";
          }
        }
      }
    }

    if (fileRead) {
      pfile.close();
    }
    opfile.close();

    cout << "Which person are you looking for? " << endl;
    getline(cin, choice);

    int foundIndex = findPerson(pList, index, choice);
    if (foundIndex != -1) {
      cout << "Found your person: " << endl;
      writePerson(cout, pList[foundIndex]);
    } else {
      cout << "Couldn't find your person: " << choice << endl;
    }
  } else {
    // Initialize default shipping rate for customers
    for (int i = 0; i < PLIST_SIZE; i++) {
      cList[i].shippingRate = 5.0;
    }

    opfile.open("ocustomer.txt");
    choice = "yes";

    if (fileRead) {
      readCustomer(pfile, cList[index]);
      if (!pfile) {
        choice = "no";
      }
    }

    while (choice != "no" && index < PLIST_SIZE) {
      if (!fileRead) {
        requestInfo(
            cout,
            "Please enter your name followed by your age then shipping rate");
        readCustomer(cin, cList[index]);
      }

      writeCustomer(opfile, cList[index]);

      index++;
      if (!fileRead) {
        choice = readAgain(cout, cin);
      } else {
        if (index < PLIST_SIZE) {
          readCustomer(pfile, cList[index]);
          if (!pfile) {
            choice = "no";
          }
        }
      }
    }

    if (fileRead) {
      pfile.close();
    }
    opfile.close();

    cout << "Which person are you looking for? " << endl;
    getline(cin, choice);

    int foundIndex = findCustomer(cList, index, choice);
    if (foundIndex != -1) {
      cout << "Found your person: " << endl;
      writeCustomer(cout, cList[foundIndex]);
    } else {
      cout << "Couldn't find your person: " << choice << endl;
    }
  }

  return 0;
}
