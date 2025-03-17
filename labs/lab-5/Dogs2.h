#ifndef DOGS_1_H
#define DOGS_1_H

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
};


class BostonTerrier : public Dog {
public:
  BostonTerrier( string n ) : Dog( n ) { }
};

class Heinz57 : public Dog {
public:
  Heinz57( string n ) : Dog( n ) { }
};
#endif
