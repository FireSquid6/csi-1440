#include <iostream>

using namespace std;

char* giveMemory() {
  char myArray[] = "Hello World!";
  return myArray;
}

int main() {
  char myArray[] = "Hello World!";
  char *myPtr = giveMemory();

  cout << "This is from the array: " << myArray << endl;
  cout << "This is from the pointer: " << myPtr << endl;

  cout << endl << "Let's try to change the array..." << endl;
  myArray[1] = 'o';
  myArray[2] = 'w';
  myArray[3] = 'd';
  myArray[4] = 'y';

  cout << "This is from the array: " << myArray << endl;

  cout << endl << "Let's try to change the pointer..." << endl;
  myPtr[1] = 'o';
  myPtr[2] = 'w';
  myPtr[3] = 'd';
  myPtr[4] = 'y';


  *(myPtr + 1) = 'o';
  *(myPtr + 2) = 'w';
  *(myPtr + 3) = 'd';
  *(myPtr + 4) = 'y';

  cout << "This is from the pointer: " << myPtr << endl;

  return 0;
}
