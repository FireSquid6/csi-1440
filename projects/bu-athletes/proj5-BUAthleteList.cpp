#include "proj5-BUAthleteList.h"


void BUAthleteList::resizeArray() {
  capacity += 2;
  BUAthlete* newList = new BUAthlete[capacity];


  for (int i = 0; i < size; i++)  {
    newList[i] = list[i];
  }

  delete[] list;
  list = newList;
}

BUAthleteList::BUAthleteList() {
  capacity = 2;
  size = 0;
  list = new BUAthlete[capacity];
}

BUAthleteList::~BUAthleteList() {
  delete[] list;
}

void BUAthleteList::addNCAAAthlete(int ID, string name, string LOI, string school) {
  if (size >= capacity) {
    resizeArray();
  }
  
  list[size] = BUAthlete();
  list[size].setID(ID);
  list[size].setName(name);
  list[size].setLOI("yes");
  list[size].setSchool(school);

  size += 1;
}

void BUAthleteList::setBUInfo(int index, Position pos, int eval) {
  list[index].setPosition(pos);
  list[index].setEvaluation(eval);
}

int BUAthleteList::findById(int id) {
  for (int i = 0; i < size; i++) {
    if (list[i].getID() == id) {
      return i;
    }
  }

  return -1;
}

void BUAthleteList::sortByID() {
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size - 1; j++) {

    }
  }

}
void BUAthleteList::sortByPosition() {
  // TODO - quicksort

}

BUAthlete& BUAthleteList::operator[](int i) {
  return list[i];
}

string BUAthleteList::toString() {
  stringstream ss;

  for (int i = 0; i < size; i++) {
    ss << "[ " << i << " ]" << endl;
    ss << list[i].toString();
    ss << endl;
  }

  return ss.str();
}
