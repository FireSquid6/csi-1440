#include <cassert>
#include "proj3-MyString.h"

using namespace std;

void testEqual() {
  MyString str1 = MyString("12345");
  MyString str2 = MyString("12345");
  MyString str3 = MyString("12245");

  assert(str1 == str2);
  assert(!(str1 == str3));

  cout << "STRING EQUALITY TESTS PASSED";
}


int main() {
  testEqual();
}
