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

class BostonTerrier {
private:
  string name;

public:
  BostonTerrier( string n ) {
    name = n;
  }

  string getName() {
    return name;
  }   

  void Bark() {
    cout << "Arf-Arf" << endl;
  }
};

class Heinz57 {
private:
  string name;

public:
  Heinz57( string n ) {
    name = n;
  }

  string getName() {
    return name;
  }

  void Bark() {
    cout << "Bow-Wow" << endl;
  }
};

#endif
