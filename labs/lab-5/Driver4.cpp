#include "Dogs4.h"

using namespace std;

void WalkTheDog(Dog &dog) {
  dog.Pant();
  dog.Bark();
  dog.Pant();
}

void BegForFood(Dog &dog) {
  dog.Wimper();
  dog.Bark();
}


int main() {
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
}


