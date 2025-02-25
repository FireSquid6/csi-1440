#include "proj4-ItemInfo.h"
#include <cassert>
#include <iostream>
#include <cmath>

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

void testStrToInt() {
  const char* singleDigit = "5";
  assert(strToInt(singleDigit) == 5);
  
  const char* multiDigit = "123";
  assert(strToInt(multiDigit) == 123);
  
  const char* zero = "0";
  assert(strToInt(zero) == 0);
  
  const char* largeNum = "9876";
  assert(strToInt(largeNum) == 9876);
  
  const char* veryLargeNum = "123456789";
  assert(strToInt(veryLargeNum) == 123456789);
  
  const char* leadingZeros = "00123";
  assert(strToInt(leadingZeros) == 123);
  
  const char* allZeros = "000";
  assert(strToInt(allZeros) == 0);
  
  cout << "testStrToInt PASSED" << endl;
}

void testDblToCstr() {
  char result[20];
  
  stuDblToCstr(result, 123.45);
  assert(strcmp(result, "123.45") == 0);
  
  stuDblToCstr(result, 0.99);
  assert(strcmp(result, "0.99") == 0);
  
  stuDblToCstr(result, 1.0);
  assert(strcmp(result, "1.00") == 0);
  
  stuDblToCstr(result, 999.99);
  assert(strcmp(result, "999.99") == 0);
  
  stuDblToCstr(result, 0.01);
  assert(strcmp(result, "0.01") == 0);
  
  stuDblToCstr(result, 100.00);
  assert(strcmp(result, "100.00") == 0);
  
  cout << "testDblToCstr PASSED" << endl;
}

void testCstrToDbl() {
  assert(fabs(stuCstrToDbl("123.45") - 123.45) < 0.0001);
  
  assert(fabs(stuCstrToDbl("0.99") - 0.99) < 0.0001);
  
  assert(fabs(stuCstrToDbl("1.00") - 1.0) < 0.0001);
  
  assert(fabs(stuCstrToDbl("999.99") - 999.99) < 0.0001);
  
  assert(fabs(stuCstrToDbl("0.01") - 0.01) < 0.0001);
  
  assert(fabs(stuCstrToDbl("100.00") - 100.0) < 0.0001);
  
  assert(fabs(stuCstrToDbl("0.00") - 0.0) < 0.0001);
  
  assert(fabs(stuCstrToDbl("1234.56") - 1234.56) < 0.0001);
  
  cout << "testCstrToDbl PASSED" << endl;
}

int main() {
  testStrCpy();
  testStrLen();
  testStrToInt();
  testDblToCstr();
  testCstrToDbl();

  return 0;
}




