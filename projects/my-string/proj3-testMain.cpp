#include "proj3-MyString.h"
#include <cassert>
#include <sstream>

using namespace std;

void testPlus() {
  MyString str1 = MyString("abcdefg");
  MyString str2 = str1;

  str2[1] = '2';

  assert((str1 + str2).length() == 14);
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
  assert(str2 == "abcdefg123");

  cout << "testPlusEquals PASSED" << endl;
}

void testGetline() {
  MyString str = MyString();
  stringstream ss;
  ss << "This is a string!\nThis is some more!";

  str.getline(ss);

  assert(str == "This is a string!");

  MyString str2 = MyString();
  stringstream ss2;
  ss2 << "This is a longer thing that goes past the chunk size so that it does a better test\nit shouldn't have this";

  str2.getline(ss2);

  assert(str2 == "This is a longer thing that goes past the chunk size so that it does a better test");

  cout << "testGetline PASSED" << endl;
}

void testConstructors() {
  MyString str1;

  assert(str1.length() == 0);

  MyString str2 = MyString("hello world!");

  assert(str2.length() == 12);

  MyString str3 = str2;

  assert(str3.length() == 12);
  assert(str3 == str2);

  MyString str4 = MyString(str3);

  assert(str4 == str2);

  cout << "testConstructors PASSED" << endl;
}

void testEquivalence() {
  MyString str1 = MyString("12345");
  MyString str2 = MyString("12345");
  MyString str3 = MyString("123456");
  MyString str4 = MyString("12342");

  assert(str1 == str2);
  assert(!(str1 == str3));
  assert(!(str1 == str4));

  cout << "testEquivalence PASSED" << endl;
}

void testInsertion() {
  MyString str = MyString("abcdefghijklmnop");
  stringstream ss;
  ss << str;
  string ssString = ss.str();
  assert(ssString == "abcdefghijklmnop");

  cout << "testInsertion PASSED" << endl;
}

void testAccessor() {
  MyString str = "0123456";
  assert(str[0] == '0');
  assert(str[6] == '6');

  cout << "testAccessor PASSED" << endl;
}

int main() {
  testConstructors();
  testEquivalence();
  testInsertion();
  testPlusEquals();
  testGetline();
  testAccessor();
  testPlus();
}
