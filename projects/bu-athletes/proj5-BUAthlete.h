/**
* file: proj5-BUAthlete.h
* author: Jonathan Deiss
* course: CSI 1440
* assignment: project 5
* due date: 3/23/2025
*
* date modified: 3/23/2025
* - create the file
* 
* Contains the declaration for a data file containing info on athletes
*
*/
#ifndef BU_ATHLETE_H
#define BU_ATHLETE_H
#include "proj5-NCAAAthlete.h"
#include <string>
#include <sstream>

enum Position {OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K}; 
using namespace std;

/**
 * positionToString
 *
 * This function converts a Position enum value to its corresponding string representation.
 *
 * Parameters:
 *      p: Position enum value to be converted
 *
 * Output:
 *      return: string representation of the position
 *      reference parameters: none
 *      stream: none
 */
string positionToString(Position p);

/**
 * stringToPosition
 *
 * This function converts a string representation of a position to its corresponding Position enum value.
 *
 * Parameters:
 *      s: string representation of the position
 *
 * Output:
 *      return: Position enum value corresponding to the string
 *      reference parameters: none
 *      stream: none
 */
Position stringToPosition(string s);

class BUAthlete: public NCAAAthlete {
private:
  int evaluation;
  Position position;
public:
  /**
   * BUAthlete
   *
   * Default constructor that initializes a BUAthlete object with default values.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  BUAthlete();
  
  /**
   * setEvaluation
   *
   * This function sets the evaluation score for the athlete.
   *
   * Parameters:
   *      int: evaluation score to be assigned
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void setEvaluation(int);
  
  /**
   * setPosition
   *
   * This function sets the playing position for the athlete.
   *
   * Parameters:
   *      Position: enum value representing the athlete's position
   *
   * Output:
   *      return: none
   *      reference parameters: none
   *      stream: none
   */
  void setPosition(Position);
  
  /**
   * getEvaluation
   *
   * This function retrieves the evaluation score of the athlete.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: integer representing the athlete's evaluation score
   *      reference parameters: none
   *      stream: none
   */
  int getEvaluation();
  
  /**
   * getPosition
   *
   * This function retrieves the playing position of the athlete.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: Position enum value representing the athlete's position
   *      reference parameters: none
   *      stream: none
   */
  Position getPosition();
  
  /**
   * toString
   *
   * This function creates a string representation of the BUAthlete object,
   * including all relevant information about the athlete.
   *
   * Parameters:
   *      none
   *
   * Output:
   *      return: string containing formatted information about the athlete
   *      reference parameters: none
   *      stream: none
   */
  string toString();
};
#endif
