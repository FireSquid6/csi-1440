/**
-  file: lab1-pointers1-3.cpp
-  author:  Prof. Matthew Aars
-  course: CSI 1440
-  assignment: Lab 1
-  due date: 8/25/2016
-
-  Date Modified: 1/23/2025
-    - File Created
-
-  Pointer arithmatic
*/
#include <iostream>

using namespace std;

int main() {
    // creates variables of different types and pointers to those vars
    int x, *intPtr = &x;
    char ch, *chPtr = &ch;
    double dbl, *dblPtr = &dbl;

    // outputs the addresses of the pointers
    cout << intPtr << " is the initial value of intPtr" << endl;
    cout << (int*)chPtr << " is the initial value of chPtr" << endl;
    cout << dblPtr << " is the initial value of dblPtr" << endl;

    // increases the address of the pointers
    // this does NOT change the value of x, ch, or dbl
    //
    // this smells like an amazing way to shoot yourself in the foot since
    // you have no idea what is at the next memory location
    intPtr++;
    chPtr++;
    dblPtr++;

    // outputs the addresses of the pointers again
    //
    // on my machine (NixOS, gcc 14.2.1), this will always output showing that:
    // intPtr -> dbl
    // chPtr -> x
    // dblPtr -> somewhere else entirely
    //
    // not sure if this would
    //
    // also all of those variables are still undefined which smells bad too
    //
    cout << intPtr << " is the new value of intPtr" << endl;
    cout << (int*)chPtr << " is the new value of chPtr" << endl;
    cout << dblPtr << " is the new value of dblPtr" << endl;


    // I would have expected these lines to create an error, but on my machine it outputs:
    // 0
    // �
    // -3.34546e-68
    cout << *intPtr << endl;
    cout << *chPtr << endl;
    cout << *dblPtr << endl;
    
    // made me think of this

    return 0;
}
