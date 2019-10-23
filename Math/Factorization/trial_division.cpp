#include <vector>
#include <iostream>
using namespace std;

// Input = Number to be factorized
// Output = factors

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main() {
  vector<long long> factors = trial_division1(55);
  for (int factor : factors) {
    cout << factor << " ";
  }
  return 0;
}