#include "proj5-BUAthlete.h"
#include "proj5-BUAthleteList.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  BUAthleteList list;
  string line;
  ifstream ncaaFile("proj5-NCAAAthlete.csv");
  if (!ncaaFile.is_open()) {
    cout << "NCAA file not found!" << endl;
    return 1;
  }

  while (getline(ncaaFile, line)) {
    stringstream ss;
    ss << line;
    string idString;
    string name;
    string school;
    string loi;

    getline(ss, idString, ',');
    getline(ss, name, ',');
    getline(ss, school, ',');
    getline(ss, loi, ',');

    int id = stoi(idString);

    list.addNCAAAthlete(id, name, school, loi);
  }

  ncaaFile.close();
  list.sortByID();

  ifstream arandaFile("proj5-BUAthlete.csv");
  if (!arandaFile.is_open()) {
    cout << "aranda file not found!" << endl;
    return 1;
  }

  while (getline(arandaFile, line)) {
    stringstream ss;
    ss << line;

    string idString;
    string positionString;
    string evalString;

    getline(ss, idString, ',');
    getline(ss, positionString, ',');
    getline(ss, evalString, ',');

    int id = stoi(idString);
    Position pos = stringToPosition(positionString);
    int eval = stoi(evalString);

    int index = list.findById(id);

    list.setBUInfo(index, pos, eval);
  }

  arandaFile.close();

  list.sortByEvaluation();
  list.sortByPosition();

  for (int posType = OL; posType <= K; posType++) {
    Position currentPos = static_cast<Position>(posType);
    string posName = positionToString(currentPos);
    cout << "Top athletes for position " << posName << ":" << endl;

    int count = 0;

    for (int i = 0; i < list.getSize() && count < 2; i++) {
      if (list[i].getPosition() == currentPos) {
        cout << list[i].toString() << endl;
        count++;
      }
    }

    if (count == 0) {
      cout << "  No athletes found for this position" << endl;
    }

    cout << endl;
  }

  return 0;
}
