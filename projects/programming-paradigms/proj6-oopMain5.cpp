#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int PLIST_SIZE = 10;

// Enum to represent the different kinds of entities
//
// this is kinda like a typescript discrminated union
// but sad because C++ doesn't have structured typing
enum PersonKind { PERSON, CUSTOMER, MEGA_CUSTOMER };

class Universal {
private:
  string name;
  int age;
  double shippingRate;
  PersonKind kind;

public:
  Universal(PersonKind k = PERSON) {
    kind = k;
    switch (kind) {
    case CUSTOMER:
      shippingRate = 5.0;
      break;
    case MEGA_CUSTOMER:
      shippingRate = 0.0;
      break;
    // person doesn't actually have a shipping rate
    case PERSON:
      shippingRate = -1.0;
      break;
    }
  }

  string getName() { return name; }
  double getShippingRate() { return shippingRate; }
  PersonKind getKind() { return kind; }

  void readPerson(istream &in) {
    getline(in, name);
    in >> age;
    in.ignore(3, '\n');

    // Only read shipping rate for CUSTOMER type
    if (kind == CUSTOMER) {
      in >> shippingRate;
      in.ignore(3, '\n');
    }
  }

  void writePerson(ostream &out) {
    out << name << endl;
    out << age << endl;

    // Only output shipping rate for CUSTOMER and MEGA_CUSTOMER
    if (kind == CUSTOMER || kind == MEGA_CUSTOMER) {
      out << shippingRate << endl;
    }
  }
};

void requestInfo(ostream &out, string msg) { out << msg << endl; }

string readAgain(ostream &out, istream &in) {
  string choice;
  out << "Do you want to read in another person (yes/no)? " << endl;
  in >> choice;
  in.ignore(3, '\n');
  return choice;
}

int findPerson(Universal pList[], int count, string name) {
  int pos = -1;
  int index = 0;

  while (pos == -1 && index < count) {
    if (pList[index].getName() == name) {
      pos = index;
    }
    index++;
  }

  return pos;
}

int main() {
  Universal pList[PLIST_SIZE];
  string choice, pTypeChoice, msg;
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
    cout << "What type of Person? (person/customer/mega)" << endl;
    cin >> pTypeChoice;
    cin.ignore(3, '\n');
  }

  // Set the kind for all elements in the array
  PersonKind kind = PERSON;
  if (pTypeChoice == "customer") {
    kind = CUSTOMER;
    msg = "Please enter your name followed by your age then shipping rate.";
  } else if (pTypeChoice == "mega") {
    kind = MEGA_CUSTOMER;
    msg = "Please enter your name followed by your age.";
  } else {
    msg = "Please enter your name followed by your age.";
  }

  for (int i = 0; i < PLIST_SIZE; i++) {
    pList[i] = Universal(kind);
  }

  opfile.open("operson.txt");
  choice = "yes";

  if (fileRead) {
    pList[index].readPerson(pfile);
    if (!pfile) {
      choice = "no";
    }
  }

  while (choice != "no" && index < PLIST_SIZE) {
    if (!fileRead) {
      requestInfo(cout, msg);
      pList[index].readPerson(cin);
    }

    pList[index].writePerson(opfile);

    index++;
    if (!fileRead) {
      choice = readAgain(cout, cin);
    } else {
      if (index < PLIST_SIZE) {
        pList[index].readPerson(pfile);
        if (!pfile) {
          choice = "no";
        }
      } else {
        choice = "no";
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
    pList[foundIndex].writePerson(cout);
  } else {
    cout << "Couldn't find your person: " << choice << endl;
  }

  return 0;
}
