#ifndef BU_ATHLETE_H
#define BU_ATHLETE_H

#include "proj5-NCAAAthlete.h"
#include <string>
#include <sstream>

enum Position {OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K}; 

using namespace std;

string positionToString(Position p);
Position stringToPosition(string s);

class BUAthlete: public NCAAAthlete {
private:
  int evaluation;
  Position position;

public:
  BUAthlete();

  void setEvaluation(int);
  void setPosition(Position);
  int getEvaluation();
  Position getPosition();
  string toString();
};

#endif
