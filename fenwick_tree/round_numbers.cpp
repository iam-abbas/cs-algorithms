// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-round-numbers/
/*
				C++
				encoding: UTF-8
				Modified: <04/Oct/2019 04:56:19 PM>

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

#define         int                    long long
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
int arr[N], bit[N];
int n, q;

int rnd (int x) {
	if (x < 0) return 0;
	int p = (x % 10);
	int q;
	while (x > 0) {
		q = (x % 10);
		x /= 10;
	}
	return (p == q);
}

void update (int i, int val) {
	while (i <= n) {
		bit[i] += val;
		i += (i & (-i));
	}
}

int query (int i) {
	int sum = 0;
	while (i > 0) {
		sum += bit[i];
		i -= (i & (-i));
	}
	return sum;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> q;
	fr (i, 1, n + 1) {
		cin >> arr[i];
		int c = rnd (arr[i]);
		if (c) update (i, 1);
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r;
			cin >> l >> r;
			int ans = query (r) - query (l - 1);
			pr (ans);
		} else {
			int i, k;
			cin >> i >> k;
			if (rnd (arr[i]) and !rnd (k)) {
				update (i, -1);
			} else if (!rnd (arr[i]) and rnd (k)) {
				update (i, 1);
			}
			arr[i] = k;
		}
	}
	return 0;
}
