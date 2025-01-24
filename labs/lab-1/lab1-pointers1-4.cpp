#include <iostream>

using namespace std;

int main() {
  int x, *intPtr;
  char ch, *charPtr;

  x = 10;
  intPtr = &x;

  ch = 'a';
  charPtr = &ch;  

  cout << "The value of x is " << x << endl;
  cout << "The value of x using intPtr is " << *intPtr << endl;  

  cout << "The value of ch is " << ch << endl;
  cout << "The value of ch using charPtr is " << *charPtr << endl;
  
  return 0;
}