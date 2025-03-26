#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int n) {
  vector<bool> l(n + 1, true);
  l[0] = false;
  l[1] = false;

  for (int p = 2; p * p <= n; p++) {
    if (l[p]) {
      for (int i = p * p; i <= n; i += p) {
        l[i] = false;
      }
    }
  }

  vector<int> primes;
  for (int p = 2; p <= n; p++) {
    if (l[p]) {
      primes.push_back(p);
    }
  }

  return primes;
}

int main() {
  cout << "Input n: ";
  int n;
  cin >> n;
  cout << endl;

  vector<int> primes = sieve(n);

  cout << "The " << primes.size() << " primes up to " << n << " are:" << endl;
  for (unsigned int i = 0; i < primes.size(); i++) {
    cout << primes[i] << " ";
  }
  cout << endl;

  return 0;
}
