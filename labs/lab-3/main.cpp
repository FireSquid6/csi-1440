#include <iostream>

using namespace std;

int profStrLen(char *str) {
  char *endOfStr = str;
  while (*endOfStr != '\0') {
    endOfStr++;
  }
  return (int)(endOfStr - str);
}

int stuStrLen(char *s) {
  int size = 0;

  while (s[size] != '\0') {
    size += 1;
  }

  return size;
}
char *profStrCpy(char *str1, char *str2) {
  char *dest = str1;
  while (*str2 != '\0') {
    *str1 = *str2;
    str1++;
    str2++;
  }
  *str1 = '\0';
  return dest;
}

char *stuStrCpy(char *dest, char *src) {
  int i = 0;

  while (src[i] != '\0') {
    dest[i] = src[i];
    i += 1;
  }

  dest[i] = '\0';
  return dest;
}

char *profStrCat(char *str1, char *str2) {
  char *dest = str1;
  while (*str1 != '\0') {
    str1++;
  }
  while (*str2 != '\0') {
    *str1 = *str2;
    str1++;
    str2++;
  }

  *str1 = '\0';
  return dest;
}
char *stuStrCat(char *dest, char *src) {
  int i = 0;
  int j = 0;
  while (dest[i] != '\0') {
    i++;
  }

  while (src[j] != '\0') {
    dest[i] = src[j];
    j++;
    i++;
  }

  dest[i] = '\0';

  return dest;
}

int stuStrCmp(char *s1, char *s2) {
  int i = 0;

  while (s1[i] != '\0' && s2[i] != '\0') {
    int diff = s1[i] - s2[i];
    if (diff != 0) {
      return diff;
    }
    i += 1;
  }

  return 0;
}

// function should be named something like str to int.
// think the name in the std library is `atoi`
int mystery(char *str) {
  char *str2 = str;
  long pos;
  int result = 0;

  // makes str2 point to the end of the string
  while (*str2 != '\0') {
    str2++;
  }

  // pos is the last index of str
  pos = str2 - str - 1;

  // iterates from the last position (ones place) to the first position
  // and converts the characters into integers
  for (int count = 1; pos >= 0; pos--, count *= 10) {
    if (str[pos] == '-') {
      result *= -1;
    } else {
      // this is a simple way to convert a string into an integer 
      result += (str[pos] - '0') * count;
    }
  }
  return result;
}

void testStrLen() {
  // test strcpy
  char s1[] = "1234";

  int len1 = stuStrLen(s1);
  int len2 = profStrLen(s1);

  if (len1 != 4) {
    cout << "Test failed with stuStrLen" << endl;
    exit(1);
  }

  if (len2 != 4) {
    cout << "Test failed with profStrLen" << endl;
    exit(1);
  }
}

void testStrCpy() {
  char src[] = "this is a string";
  char dest1[20];
  char dest2[20];


  stuStrCpy(dest1, src);
  profStrCpy(dest2, src);


  if (stuStrCmp(dest1, src) != 0) {
    cout << "Test failed with stuStrCpy" << endl;
    exit(1);
  }

  if (stuStrCmp(dest2, src) != 0) {
    cout << "Test failed with profStrCpy" << endl;
    exit(1);
  }
}

void testStrCat() {
  char src[] = " some more text";
  char dest1[40] = "this is a string with";
  char dest2[40] = "this is a string with";
  char expected[] = "this is a string with some more text";

  stuStrCat(dest1, src);
  profStrCat(dest2, src);

  if (stuStrCmp(dest1, expected) != 0) {
    cout << "Test failed with stuStrCat" << endl;
    exit(1);
  }

  if (stuStrCmp(dest2, expected) != 0) {
    cout << "Test failed with profStrCat" << endl;
    exit(1);
  }
}

void testStrCmp() {
  char s1[] = "this is a string";
  char s2[] = "this is another string";
  char s3[] = "this is a string";

  if (stuStrCmp(s1, s3) != 0) {
    cout << "Test failed with stuStrCmp" << endl;
    exit(1);
  }
  if (stuStrCmp(s1, s2) == 0) {
    cout << "Test failed with stuStrCmp" << endl;
    exit(1);
  }
}

int main() {
  testStrLen();
  testStrCmp();
  testStrCpy();
  testStrCat();

  cout << "All tests passed!" << endl; 
  return 0;
}
