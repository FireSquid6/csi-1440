#include "proj3-MyString.h"
#include <cassert>
#include <sstream>

using namespace std;

void testPlus() {
  MyString str1 = MyString("abcdefg");
  MyString str2 = str1;

  str2[1] = '2';

  assert(str1 + str2 == "abcdefga2cdefg");
  cout << "testPlus PASSED" << endl;
}

void testPlusEquals() {
  MyString str1 = MyString("abcdefg");
  MyString str2 = MyString(str1);

  assert(str1 == str2);
  assert(str1.length() == 7);
  assert(str2.length() == 7);
  str2 += "123";

  assert(!(str1 == str2));

  assert(str1.length() == 7);
  assert(str2.length() == 10);

  cout << "testPlusEquals PASSED" << endl;
}

void testGetline() {
  MyString str = MyString();
  stringstream ss;
  ss << "This is a string!\nThis is some more!";

  str.getline(ss);

  assert(str == "This is a string!");

  MyString str2 = MyString();
  // stringstream ss2;
  // ss2 << "This is a longer thing that goes past the chunk size so that it does a better test\nit shouldn't have this";
  //
  // str2.getline(ss2);
  //
  // cout << "string 2: " << str2 << endl;
  // assert(str2 == "This is a longer thing that goes past the chunk size so that it does a better test");

  cout << "testGetline PASSED" << endl;
}

void testAccessor() {
  MyString str = "0123456";
  assert(str[0] == '0');
  assert(str[6] == '6');

  cout << "testAccessor PASSED" << endl;
}

int main() {
  testPlusEquals();
  testGetline();
  testAccessor();
  testPlus();
}
