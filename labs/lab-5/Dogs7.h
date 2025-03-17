#ifndef DOGS_7_H
#define DOGS_7_H

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

  virtual void Bark() {
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

class HuckleberryHound : public Dog {
public:
  HuckleberryHound( string n ) : Dog( n ) { }

  void Bark() {
    cout << "Oh, my darlin" << endl;
  }
};

class Poodle : public Dog {
public:
  Poodle( string n ) : Dog( n ) {}

  void Bark() {
    cout << "Oui-Oui" << endl;
  }
};

class ScoobyDoo : public Dog {
public:
  ScoobyDoo( string n ) : Dog( n ) {}

  void Bark() {
    cout << "Ruh-Roh" << endl;
  }
};

class GermanSheperd : public Dog {
public:
  GermanSheperd( string n ) : Dog( n ) {}

  void Bark() {
    cout << "I see nothing!" << endl;
  }
};

#endif
