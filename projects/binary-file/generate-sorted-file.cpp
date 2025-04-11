#include <fstream>
#include <iostream>

using namespace std;

int main() {
  const string FILENAME = "sortedInts";

  ofstream file(FILENAME, ios::binary);

  if (!file) {
    cerr << "Error: Could not create file " << FILENAME << endl;
    return 1;
  }

  for (int i = 1; i <= 20; i++) {
    file.write(reinterpret_cast<const char *>(&i), sizeof(int));
  }

  file.close();

  cout << "Successfully created " << FILENAME << " with integers 1-20" << endl;

  return 0;
}
