// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/

/*
				C++
				encoding: UTF-8
				Modified: <03/Oct/2019 04:18:08 PM>

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

const int N = 1e5 + 5;
int arr[N];
int bit[N];
int n;

void update (int x, int val) {
	while (x <= n) {
		bit[x] += val;
		x += (x & (-x));
	}
}

int query (int x) {
	int ans = 0;
	while (x > 0) {
		ans += bit[x];
		x -= (x & (-x));
	}
	return ans;
}

int query (int l, int r) {
	return query (r) - query (l - 1);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n + 1) {
		cin >> arr[i];
		arr[i] &= 1;
		if (!arr[i]) update (i, 1);
	}
	int tc;
	cin >> tc;
	while (tc--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 0) {
			y &= 1;
			if (arr[x] and !y) {
				update (x, 1);
			}
			if (!arr[x] and y) {
				update (x, -1);
			}
			arr[x] = y & 1;
		} else if (t == 1) {
			int ans = query (x, y);
			pr (ans);
		} else {
			int ans = query (x, y);
			pr (y - x + 1 - ans);
		}
	}
	return 0;
}
