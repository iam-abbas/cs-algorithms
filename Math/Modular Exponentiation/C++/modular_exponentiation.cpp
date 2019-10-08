#include <iostream>
using namespace std;


// Calculates (a^b) % m
// Time Complexity : O(log (a+b)) aka O(logN)
long long modPow(long long a, long long b, long long m) {
  a %= m;
  long long result = 1;
  while (b > 0) {
    if (b & 1)
      result = result * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return result;
}

int main() {
  cout << modPow(1009, 33, 1000000007) << endl;
  return 0;
}
