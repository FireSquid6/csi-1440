/*
* Jonathan Deiss
* CSI 1440 Section 01
* Lab 2
*
* 1. What would be printed if we just incremented the pointer?
* A: "ello World!"
*
* 2. How does "myArray += 6" differ from what we talked about in
* class - "*(myArray + 6)" - which we said was ok?
* A: `myArray += 6` *mutates* the array, which is not allowed.
*
* 3. Replace the array notation statements with pointer notation statements for the assignemnt of 'o', 'w', 'd', and 'y'
* A:
* *(myArray + 1) = 'o';
* *(myArray + 2) = 'w';
* *(myArray + 3) = 'd';
* *(myArray + 4) = 'y';
*
* 4. Could this code be fixed by using pointer notation instead of array notation? Why/Why not?
* A: Not without changing the definition of myPtr. myPtr is a pointer to a string literal, which
* is constant. This is why the compiler warns us about `char *myPtr = "Hello World!"` because it
* is probably never what you want to do
*
* 5. Why did we not give the memory back to the computer, using the delete operator, within the
* function?
* If we had done that, the memory would have been deleted before we could use it outside of the
* function
*
* 6. Why do we not need to use the indirection operator when printing the contents of myArray and
* myPtr? Could we print the contents of a differently typed (int, double, etc...) array?
* A. Under the hood, the << operator of ostream assumes you wanted to print text when printing
* a list of characters. Arrays of doubles or ints would just show the address. On my machine, this code:
*
* ```cpp
* #include <iostream>
* 
* using namespace std;
* 
* 
* int main() {
*   double myList[4] = {1.0, 2.0, 3.0, 4.0};
*   char otherList[5] = {'h', 'e', 'l', 'l', 'o'};
* 
* 
*   cout << myList << endl;
*   cout << otherList << endl;
* }
* ```
*
* outputs:
* ```txt
* <some-address>
* hello
* ```
*
* 7, Write two additional lines of cope to print out the contents of str as c-string representation using c_str() with both the indirection operator and the structure pointer operator.
* A:
* ```cpp
* cout << str->c_str() << endl;
* cout << (*str).c_str() << endl;
* ```
*/
