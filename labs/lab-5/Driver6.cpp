#include "Dogs6.h"

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
  BostonTerrier terrier("terrier");
  Heinz57 heinz("heinz");
  HuckleberryHound hound("hound");
  Poodle poodle("poodle");
  ScoobyDoo scooby("scooby");
  GermanSheperd shepherd("shepherd");


  WalkTheDog(dog);
  BegForFood(dog);

  WalkTheDog(terrier);
  BegForFood(terrier);


  WalkTheDog(heinz);
  BegForFood(heinz);

  WalkTheDog(hound);
  BegForFood(hound);

  WalkTheDog(poodle);
  BegForFood(poodle);

  WalkTheDog(scooby);
  BegForFood(scooby);

  WalkTheDog(shepherd);
  BegForFood(shepherd);

  return 0;
}


