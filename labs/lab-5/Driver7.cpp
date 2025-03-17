#include "Dogs7.h"

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
  Dog *doggies[] = {new Dog("Fido"),
                    new BostonTerrier("Dixie"),
                    new Heinz57("Bones"),
                    new HuckleberryHound("Huck"),
                    new Poodle("Frenchy"),
                    new ScoobyDoo("Scooby"),
                    new GermanSheperd("SgtShultz")};

  for (int i = 0; i < 7; i++) {
    cout << "Walking " << doggies[i]->getName() << "..." << endl;
    WalkTheDog(*doggies[i]);

    cout << endl << doggies[i]->getName() << " is begging again..." << endl;

    BegForFood(*doggies[i]);
    cout << endl;
  }

  return 0;
}
