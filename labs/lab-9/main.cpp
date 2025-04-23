#include <iostream>
#include "lab8-LabList.h"

using namespace std;

int main() {
    LabList<int> a;

    cout << "Testing insertHead..." << endl;
    for( int i = 0; i < 5; i++ ) {
        a.insertHead(i);
    }

    cout << "Testing printList..." << endl;
    a.printList(cout);

    cout << "Testing insertTail..." << endl;
    for( int i = 0; i < 5; i++ ) {
        a.insertTail(i);
    }

    a.printList(cout);

    cout << "Testing removeHead..." << endl;
    int val;
    for( int i = 0; i < 2; i++ ) {
        a.removeHead(val);
        cout << "Got: " << val << endl;
        a.printList(cout);
    }

    cout << "Testing removeTail..." << endl;
     for( int i = 0; i < 2; i++ ) {
        a.removeTail(val);
        cout << "Got: " << val << endl;
        a.printList(cout);
    }

    cout << "Testing copy constructor..." << endl;
    LabList<int> b = a;
    b.printList(cout);
    for( int i = 0; i < 6; i++ ) {
        a.removeTail(val);
        cout << "Got: " << val << endl;
        a.printList(cout);
    }

    cout << "Testing removeTail again..." << endl;
    a.insertTail(5);
    a.printList(cout);

    cout << "Testing assingment operator..." << endl;
    a = b;
    a.printList(cout);
    a = a;

    for( int i = 0; i < 6; i++ ) {
        a.removeHead(val);
        cout << "Got: " << val << endl;
        a.printList(cout);
    }

    cout << "Testing removeHead again..." << endl;
    a.insertHead(6);
    a.printList(cout);
    return 0;
}
