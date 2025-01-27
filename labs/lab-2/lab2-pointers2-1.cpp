#include <iostream>

using namespace std;

int main() {
  char myArray[] = "Hello World!";
  char *myPtr = "Hello World!";

  cout << "This is from the array: " << myArray << endl;
  cout << "This is from the pointer: " << myPtr << endl;

  cout << "Trying to move the pointer..." << endl;
  myPtr += 6;
  cout << "This is from the pointer: " << myPtr << endl;

  // this shows an error in my language server and gives an error
  // when compiling
  //
  // cout << "Trying to move the array ..." << endl;
  // myArray += 6;
  // cout << "This is from the array: " << myArray << endl;

  return 0;
}
