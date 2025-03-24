/**
* file: proj5-BUAthleteList.h
* author: Jonathan Deiss
* course: CSI 1440
* assignment: project 5
* due date: 3/23/2025
*
* date modified: 3/23/2025
* - create the file
* 
* Contains the declaration for a list class of a BUAthletes
*
*/
#ifndef BU_ATHLETE_LIST_H
#define BU_ATHLETE_LIST_H
#include "proj5-BUAthlete.h"
#include <sstream>
using namespace std;

class BUAthleteList {
private:
  BUAthlete* list;
  int capacity;
  int size;
  
  /**
   * resizeArray
   *
   * This function increases the capacity of the internal array when it becomes full.
   * Typically doubles the current capacity and copies existing elements to the new array.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void resizeArray();

public:
  /**
   * BUAthleteList
   *
   * Default constructor that initializes an empty list of athletes with default capacity.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  BUAthleteList();
  
  /**
   * BUAthleteList
   *
   * Copy constructor that creates a deep copy of another BUAthleteList object.
   *
   * Parameters:
   *      BUAthleteList&: reference to the BUAthleteList object to copy
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  BUAthleteList(BUAthleteList&);
  
  /**
   * ~BUAthleteList
   *
   * Destructor that frees dynamically allocated memory used by the list.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  ~BUAthleteList();
  
  /**
   * operator=
   *
   * Assignment operator that creates a deep copy of another BUAthleteList object.
   *
   * Parameters:
   *      BUAthleteList&: reference to the BUAthleteList object to copy
   *
   * Output:
   *      return: reference to this object after assignment
   *      reference parameters: none
   *      stream: none
   */
  BUAthleteList& operator=(BUAthleteList&);
  
  /**
   * addNCAAAthlete
   *
   * This function adds a new NCAA athlete to the list with the specified details.
   *
   * Parameters:
   *      ID: integer representing the athlete's unique identifier
   *      name: string representing the athlete's name
   *      LOI: string representing the athlete's Letter of Intent status
   *      school: string representing the athlete's school
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void addNCAAAthlete(int ID, string name, string LOI, string school);
  
  /**
   * setBUInfo
   *
   * This function sets BU-specific information for an athlete at the specified index.
   *
   * Parameters:
   *      index: integer representing the index of the athlete in the list
   *      pos: Position enum value representing the athlete's position
   *      eval: integer representing the athlete's evaluation score
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void setBUInfo(int index, Position pos, int eval);
  
  /**
   * findById
   *
   * This function searches for an athlete with the specified ID and returns their index.
   *
   * Parameters:
   *      id: integer representing the athlete's ID to search for
   *
   * Output:
   *      return: integer index of the athlete if found, or an error code if not found
   *      reference parameters: none
   *      stream: none
   */
  int findById(int id);
  
  /**
   * sortByID
   *
   * This function sorts the list of athletes by their ID in ascending order.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void sortByID();
  
  /**
   * sortByPosition
   *
   * This function sorts the list of athletes by their position.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void sortByPosition();
  
  /**
   * sortByEvaluation
   *
   * This function sorts the list of athletes by their evaluation scores.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void sortByEvaluation();
  
  /**
   * operator[]
   *
   * This function provides array-like access to athletes in the list.
   *
   * Parameters:
   *      int: index of the athlete to access
   *
   * Output:
   *      return: reference to the BUAthlete at the specified index
   *      reference parameters: none
   *      stream: none
   */
  BUAthlete& operator[](int);
  
  /**
   * toString
   *
   * This function creates a string representation of the entire athlete list.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: string containing formatted information about all athletes
   *      reference parameters: none
   *      stream: none
   */
  string toString();
  
  /**
   * getSize
   *
   * This function returns the current number of athletes in the list.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: integer representing the current size of the list
   *      reference parameters: none
   *      stream: none
   */
  int getSize();
};

#endif
