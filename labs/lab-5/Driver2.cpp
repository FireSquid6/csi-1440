#include "Dogs2.h"

using namespace std;

int main() {
  Dog aDog("Fido");
  cout << aDog.getName() << " says ";
  aDog.Bark();

  BostonTerrier aBoston("Dixie");
  cout << aBoston.getName() << " says ";
  aBoston.Bark();

  Heinz57 aHeinz("Bones");
  cout << aHeinz.getName() << " says ";
  aHeinz.Bark();

  return 0;
}
