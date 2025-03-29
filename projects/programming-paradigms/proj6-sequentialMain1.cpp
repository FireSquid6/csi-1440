#include <iostream>

using namespace std;

int main() {
  string name;
  int age;

  cout << "What is your name? " << endl;
  getline( cin, name );

  cout << "How old are you? " << endl;
  cin >> age;

  cout << "Your name is: " << name << endl;
  cout << "You are " << age << " years old" << endl;

  return 0;
}

