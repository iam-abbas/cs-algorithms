// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/string-query-22/

/*
				C++
				encoding: UTF-8
				Modified: <04/Oct/2019 02:37:20 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define         ll                     long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

const int N = 2e5 + 5;
int arr[N], bit[N][26];
string s;
int n;

void update (int i, int c, int val) {
	while (i <= n) {
		bit[i][c] += val;
		i += (i & (-i));
	}
}

int query (int i, int x) {
	int ans = 0;
	while (i > 0) {
		ans += bit[i][x];
		i -= (i & (-i));
	}
	return ans;
}

int search (int k, int x) {
	int low = 1, high = n;
	while (low <= high) {
		int mid = (low + high + 1) >> 1;
		if (query (mid, x) < k) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return low;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> s;
	n = len (s);
	fr (i, 0, n) {
		update (i + 1, s[i] - 'a', 1);
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int k;
		char x;
		cin >> k >> x;
		int idx = search (k, x - 'a');
		update (idx, x - 'a', -1);
		s[idx - 1] = '#';
	}

	for (auto i : s) {
		if (i != '#') cout << i;
	}
	cout << "\n";

	return 0;
}
