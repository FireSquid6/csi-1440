#include "proj5-BUAthleteList.h"

BUAthleteList::BUAthleteList(BUAthleteList &other) {
  capacity = other.capacity;
  size = other.size;
  list = new BUAthlete[capacity];

  for (int i = 0; i < other.size; i++) {
    list[i] = other.list[i];
  }
}

BUAthleteList &BUAthleteList::operator=(BUAthleteList &other) {
  delete[] list;

  capacity = other.capacity;
  size = other.size;
  list = new BUAthlete[capacity];

  for (int i = 0; i < other.size; i++) {
    list[i] = other.list[i];
  }

  return *this;
}

void BUAthleteList::resizeArray() {
  capacity += 2;
  BUAthlete *newList = new BUAthlete[capacity];

  for (int i = 0; i < size; i++) {
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

BUAthleteList::~BUAthleteList() { delete[] list; }

void BUAthleteList::addNCAAAthlete(int ID, string name, string loi,
                                   string school) {
  if (size >= capacity) {
    resizeArray();
  }

  list[size] = BUAthlete();
  list[size].setID(ID);
  list[size].setName(name);
  list[size].setLOI(loi);
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

BUAthlete &BUAthleteList::operator[](int i) { return list[i]; }

string BUAthleteList::toString() {
  stringstream ss;

  for (int i = 0; i < size; i++) {
    ss << "[ " << i << " ]" << endl;
    ss << list[i].toString();
    ss << endl;
  }

  return ss.str();
}

void BUAthleteList::sortByID() {
  if (size <= 1) {
    return;
  }

  for (int i = 0; i < size - 1; i++) {
    bool swapped = false;

    for (int j = 0; j < size - i - 1; j++) {
      if (list[j].getID() > list[j + 1].getID()) {
        swap(list[j], list[j + 1]);
        swapped = true;
      }
    }

    if (!swapped) {
      return;
    }
  }
}

void BUAthleteList::sortByPosition() {
  if (size <= 1) {
    return;
  }

  for (int i = 0; i < size - 1; i++) {
    bool swapped = false;

    for (int j = 0; j < size - i - 1; j++) {
      if (list[j].getPosition() > list[j + 1].getPosition()) {
        swap(list[j], list[j + 1]);
        swapped = true;
      }
    }

    if (!swapped) {
      return;
    }
  }
}
