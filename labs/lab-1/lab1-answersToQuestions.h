/*
 * Name: Jonathan Deiss
 * CSI 1440 Section 1
 * Lab 1
 *
 * "what are the differences between the original value and the incremented value?"
 * The incremented value is one "size" of whatever it was pointing at away from wherever it originally pointed. The pointer
 * is at a new address
 *
 * "is this what you expected?"
 * I expected intPtr to point to ch, chPtr to point to dbl, and dblPtr to cause a segfault if dereferenced.
 *
 * "Provide an explanation of the results"
 * 
 * pointers now point to:
 * intPtr -> dbl
 * chPtr -> x
 * dblPtr -> somewhere else entirely
 *
 * what surprised me more was that when dereferenced, dblPtr did not cause a segfault. I would have thought that it was touching memory
 * that it wasn't supposed to, which is bad.
 * 
 * "Explain the difference between *, &, and just the variables name" 
 *  *x - x is a variable that stores a memory address. *x "dereferences" x and returns the data at it's address
 *  &x - returns the address of memory where x's data is stored
 *  x - gets the value stored inside of x
 * 
 */
