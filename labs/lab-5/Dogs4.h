#ifndef DOGS_4_H
#define DOGS_4_H

#include <iostream>
#include <string>

using namespace std;

class Dog {
private:
  string name;  

public:
  Dog( string n ) {
    name = n;
  }

  string getName() {
    return name;
  }  

  void Bark() {
    cout << "Bow-Wow" << endl;
  }

  void Wimper() {
    cout << "Rrrrrrrrrr" << endl;
  }

  void Pant() {
    cout << "Ah-ha-ha-ha-ha" << endl;
  }
};


class BostonTerrier : public Dog {
public:
  BostonTerrier( string n ) : Dog( n ) { }

  void Bark() {
    cout << "Arf-Arf" << endl;
  }
};

class Heinz57 : public Dog {
public:
  Heinz57( string n ) : Dog( n ) { }

  void Bark() {
    cout << "Bow-Wow" << endl;
  }
};
#endif
