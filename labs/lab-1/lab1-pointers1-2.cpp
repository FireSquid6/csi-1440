/**
-  file: lab1-pointers1-2.cpp
-  author:  Prof. Matthew Aars
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 8/25/2016
-
-  Date Modified: 1/23/2025
-    - File Created
-
-  pointer as a variable
*/
#include <iostream>

using namespace std;

int main() {
    double dbl;
    // I assume you meant this and not double**
    double* dblPtr;

    dbl = 2.5;
    dblPtr = &dbl;

    cout << dbl << endl;
    cout << dblPtr << endl;
    cout << &dbl << endl;
    cout << &dblPtr << endl;
    cout << sizeof(dbl) << endl;
    cout << sizeof(&dblPtr) << endl;
}
