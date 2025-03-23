#include "proj5-BUAthlete.h"
#include <iostream>

string positionToString(Position p) {
  string positions[] = {"OL", "QB", "RB", "WR", "TE", "DL", "DE", "LB", "CB", "S", "K"};

  return positions[p];
}

BUAthlete::BUAthlete() {
  athleteID = -1;
  athleteName = "";
  athleteLOI = false;
  evaluation = 0;
  position = OL;
}

void BUAthlete::setEvaluation(int e) {
  evaluation = e;
}

void BUAthlete::setPosition(Position p) {
  position = p;
}

Position BUAthlete::getPosition() {
  return position;
}

int BUAthlete::getEvaluation() {
  return evaluation;
}

string BUAthlete::toString() {
  stringstream ss;

  ss << "ID: " << athleteID << endl;
  ss << "Name: " << athleteName << endl;
  ss << "School: ";
  if (athleteLOI) {
    ss << schoolChoice << endl;
  } else {
    ss << "Available" << endl;
  }
  ss << "Evaluation: " << evaluation << endl;
  ss << "Position: " << positionToString(position) << endl;

  return ss.str();
}
