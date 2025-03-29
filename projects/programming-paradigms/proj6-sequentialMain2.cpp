#include <string>
#include <iostream>

using namespace std;


int main() {
  string name;
  int age;

  string choice = "yes";

  while( choice != "no" ) {
    cout << "What is your name? " << endl;
    getline( cin, name );

    cout << "How old are you? " << endl;
    cin >> age;  

    cout << "Your name is: " << name << endl;
    cout << "You are " << age << " years old" << endl;

    cout << "Do you want to read in another person (yes/no)? " << endl;
    cin >> choice;
    cin.ignore(3, '\n');
  }

  return 0;
}
