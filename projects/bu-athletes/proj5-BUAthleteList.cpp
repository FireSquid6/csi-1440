/**
 * file: proj5-BUAthleteList.cpp
 * author: Jonathan Deiss
 * course: CSI 1440
 * assignment: project 5
 * due date: 3/23/2025
 *
 * date modified: 3/23/2025
 * - create the file
 *
 * Contains the implementations for the BUAthleteList
 *
 */
#include "proj5-BUAthleteList.h"

int partition(BUAthlete *list, int l, int h) {
  int pivot = list[l].getID();

  int i = l;

  for (int j = l + 1; j <= h; j++) {
    if (list[j].getID() < pivot) {
      i++;
      swap(list[i], list[j]);
    }
  }

  swap(list[l], list[i]);

  return i;
}

void quicksort(BUAthlete *list, int l, int h) {
  if (l < h) {
    int p = partition(list, l, h);

    quicksort(list, l, p - 1);
    quicksort(list, p + 1, h);
  }
}

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

BUAthleteList::~BUAthleteList() { 
  delete[] list; 
}

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
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    int currentId = list[mid].getID();

    if (currentId == id) {
      return mid;
    }

    if (currentId < id) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1; // Athlete with the given ID not found
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
  quicksort(list, 0, size - 1); 
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

void BUAthleteList::sortByEvaluation() {
  if (size <= 1) {
    return;
  }

  for (int i = 0; i < size - 1; i++) {
    bool swapped = false;

    for (int j = 0; j < size - i - 1; j++) {
      if (list[j].getEvaluation() < list[j + 1].getEvaluation()) {
        swap(list[j], list[j + 1]);
        swapped = true;
      }
    }

    if (!swapped) {
      return;
    }
  }
}

int BUAthleteList::getSize() { 
  return size; 
}
