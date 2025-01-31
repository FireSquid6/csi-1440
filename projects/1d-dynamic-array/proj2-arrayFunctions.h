/**
 * file: proj2-arrayFunctions.h
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: project 2
 * due date: 2/2/2025
 *
 * date modified: 1/30/2025
 * - create the file
 *
 * header file for the array functions
 *
 */
#ifndef PROJ2_ARRAYFUNCTIONS_H
#define PROJ2_ARRAYFUNCTIONS_H

/**
 * bubbleSort
 *
 * sorts the array by the bubble sort (O(n^2)) method
 *
 * Parameters:
 * array - the array to sort
 * size - the size of the array
 *
 * Output:
 * return: void
 */
void bubbleSort(int *array, int size); 

/**
 * largestValue
 *
 * gets the maximum in an array 
 *
 * Parameters:
 * array - the array to find the max of
 * size - the size of the array
 *
 * Output:
 * return: int maximum
 */
int largestValue(int *array, int size); 

/**
 * smallestValue
 *
 * finds the minimum of an array
 *
 * Parameters:
 * array - the array to find the min of
 * size - the size of the array
 *
 * Output:
 * return: int minimum
 */
int smallestValue(int *array, int size); 

/**
 * averageValue
 *
 * finds the mean of an array
 *
 * Parameters:
 * array - the array to find the average of
 * size - the size of the array
 *
 * Output:
 * return: the average value
 */
double averageValue(int *array, int size);

/**
 * medianValue
 *
 * returns the median value of an ALREADY SORTED array
 *
 * Parameters:
 * array - the array to find the median of
 * size - the size of the array
 *
 * Output:
 * return: median of the array
 */
int medianValue(int *array, int size); 

#endif
