#include <iostream>
#include <string>

using namespace std;

int main() {
  string *str = new string("Hello World!");

  // using the indirection operator to access the public interface of string
  cout << (*str).length() << endl;

  // using the structure pointer operator to access the public interface of string
  cout << str->length() << endl;

  cout << str->c_str() << endl;
  cout << (*str).c_str() << endl;

  delete str;

  return 0;
}
