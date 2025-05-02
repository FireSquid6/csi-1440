#include <iostream>
#include <chrono>
#include "proj10-Queue1.h"
#include "proj10-Queue2.h"
#include "proj10-Queue3.h"

using namespace std;

long getTime() {
  auto now = chrono::system_clock::now();
  auto duration = now.time_since_epoch();
  long miliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
  return miliseconds;
}

// bit of code duplication here but its ok
void testQueue1(int num) {
  cout << "Running queue1 with " << num << " elements" << endl;
  double t1 = getTime();

  Queue1<int> q;
  for (int i = 0; i < num; i++) {
    q.enqueue(i);
  }

  for (int i = num - 1; i >= 0; i--) {
    int v;
    q.dequeue(v);
  }
  long t2 = getTime();

  double dt = t2 - t1;
  cout << "Duration: " << dt << "ms" << endl;
  cout << endl;
}

void testQueue2(int num) {
  cout << "Running queue2 with " << num << " elements:" << endl;
  double t1 = getTime();

  Queue2<int> q;
  for (int i = 0; i < num; i++) {
    q.enqueue(i);
  }

  for (int i = num - 1; i >= 0; i--) {
    int v;
    q.dequeue(v);
  }
  long t2 = getTime();

  double dt = t2 - t1;
  cout << "Duration: " << dt << "ms" << endl;
  cout << endl;
}

void testQueue3(int num) {
  cout << "Running queue3 with " << num << " elements:" << endl;
  double t1 = getTime();

  Queue3<int> q;
  for (int i = 0; i < num; i++) {
    q.enqueue(i);
  }

  for (int i = num - 1; i >= 0; i--) {
    int v;
    q.dequeue(v);
  }
  long t2 = getTime();

  double dt = t2 - t1;
  cout << "Duration: " << dt << "ms" << endl;
  cout << endl;
}

int main() {
  // beyond this queue1 gets slow
  testQueue1(100000);
  testQueue2(100000);
  testQueue3(100000);
}

