#ifndef BU_ATHLETE_LIST_H
#define BU_ATHLETE_LIST_H

#include "proj5-BUAthlete.h"
#include <sstream>

using namespace std;
// TODO - do those pointless comments

class BUAthleteList {
private:
  BUAthlete* list;
  int capacity;
  int size;

  void resizeArray();
public:
  BUAthleteList();
  BUAthleteList(BUAthleteList&);
  ~BUAthleteList();
  BUAthleteList& operator=(BUAthleteList&);

  void addNCAAAthlete(int ID, string name, string LOI, string school);
  void setBUInfo(int index, Position pos, int eval);
  int findById(int id);
  void sortByID();
  void sortByPosition();
  BUAthlete& operator[](int);
  string toString();
};


#endif
