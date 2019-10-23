#include <bits/stdc++.h>
using namespace std;

//Note that the below code works only for distinct longest increasing subsequence
// If you want also want duplicate elements in LIS then change lower_bound to upper_bound and it will account for duplicates as well

int main() {
  int n;
  cin >> n;
  vector<int> dp;
  
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto it = lower_bound(dp.begin(), dp.end(), x);
    if (it == dp.end()) {
      dp.push_back(x);
    } else {
      *it = x;
    }
  }
  
  cout << dp.size() << endl;
}
