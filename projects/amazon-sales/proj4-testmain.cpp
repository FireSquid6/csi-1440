#include "proj4-ItemInfo.h"
#include <cassert>
#include <iostream>

// we use the cstring library in this test file to ensure that my
// implementations of the cstring library work properly
//
// not sure if this is allowed or not but I feel like its within
// the spirit of showing that I know how to implement the cstring
// functions
#include <cstring>

void testStrLen() {
  const char* emptyStr = "";
  assert(stuCstrLen(emptyStr) == 0);
  
  const char* simpleStr = "hello";
  assert(stuCstrLen(simpleStr) == 5);
  
  const char* specialStr = "Special@#$%^&*()_+";
  assert(stuCstrLen(specialStr) == 18);
  
  const char* numStr = "12345";
  assert(stuCstrLen(numStr) == 5);
  
  cout << "testStrLen PASSED" << endl;
}

void testStrCpy() {
  const char* emptyStr = "";
  char emptyDest[1];
  stuCstrCpy(emptyDest, emptyStr);
  assert(emptyDest[0] == '\0');
  
  const char* simpleStr = "hello";
  char simpleDest[6]; // Need space for the null terminator
  stuCstrCpy(simpleDest, simpleStr);
  
  for (int i = 0; i < 5; i++) {
    assert(simpleDest[i] == simpleStr[i]);
  }
  assert(simpleDest[5] == '\0');
  
  const char* longStr = "Testing longer string";
  char longDest[23];
  stuCstrCpy(longDest, longStr);
  assert(strcmp(longDest, longStr) == 0);
  
  const char* specialStr = "Special@#$%^&*()_+";
  char specialDest[19]; 
  stuCstrCpy(specialDest, specialStr);
  assert(strcmp(specialDest, specialStr) == 0);
  
  cout << "testStrCpy PASSED" << endl;
}

int main() {
  testStrCpy();
  testStrLen();

  return 0;
}




