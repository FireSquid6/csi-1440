#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>

using namespace std;

class MyString {
private:
  int size;
  int capacity;
  char *data;

  void ensureCanHold(int);
public:
  MyString();
  MyString(const char *);
  MyString(const MyString&);

  ~MyString();
  MyString &operator=(const MyString &);
  bool operator==(const MyString &) const;
  void operator+=(const MyString &);
  MyString &operator+(const MyString &) const;
  char &operator[](int) const;
  int length() const;
  friend ostream &operator<<(ostream &, MyString &);
  void getline(istream&, char delimit);
};

#endif
