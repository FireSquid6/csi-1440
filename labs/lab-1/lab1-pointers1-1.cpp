/**
-  file: lab1-pointers1-1.cpp
-  author:  Prof. Matthew Aars
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 8/25/2016
-
-  Date Modified: 1/23/2025
-    - File Created
-
-  more work on the refernce operator
*/
#include <iostream>

using namespace std;

int main() {
    int x;
    int *intPtr;

    char ch;
    char *chPtr;

    x = 10;
    intPtr = &x;

    ch = 'a';
    chPtr = &ch;

    cout << "x’s value is " << x << endl;
    cout << "intPtr’s value is " << intPtr << endl;

    cout << "x’s address is " << &x << endl;

    cout << "The size of x is " << sizeof(x) << endl;
    cout << "The size of intPtr is " << sizeof(intPtr) << endl;

    cout << "ch’s value is " << ch << endl;
    cout << "chPrt’s value is " << chPtr << endl;

    cout << "ch’s address is " << &ch << endl;

    cout << "The size of ch is " << sizeof(ch) << endl;
    cout << "The size of chPtr is " << sizeof(chPtr) << endl;

    return 0;
}
