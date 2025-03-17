#include "Dogs5.h"

using namespace std;

void WalkTheDog(Dog &dog) {
  cout << "Walking " << dog.getName() << ": " << endl;
  dog.Pant();
  dog.Bark();
  dog.Pant();
  cout << endl;
}

void BegForFood(Dog &dog) {
  cout << dog.getName() << " is begging for food: " << endl;
  dog.Wimper();
  dog.Bark();
  cout << endl;
}


int main() {
  Dog dog("dog");
  Dog aDog("Fido");
  cout << aDog.getName() << " says ";
  aDog.Bark();
  WalkTheDog(aDog);
  BegForFood(aDog);
  cout << endl;

  BostonTerrier aBoston("Dixie");
  cout << aBoston.getName() << " says ";
  aBoston.Bark();
  WalkTheDog(aBoston);
  BegForFood(aBoston);
  cout << endl;

  Heinz57 aHeinz("Bones");
  cout << aHeinz.getName() << " says ";
  aHeinz.Bark();
  WalkTheDog(aHeinz);
  BegForFood(aHeinz);
  cout << endl;

  return 0;
  return 0;
}


