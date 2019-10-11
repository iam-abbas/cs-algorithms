// https://www.codechef.com/EXPP2019/problems/EXUND

/*
				C++
				encoding: UTF-8
				Modified: <11/Oct/2019 10:08:44 PM>

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

const int N = 1e6 + 5;
int arr[N], s[N], tree[4 * N], lazy[4 * N];
int n, q;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> q;
	fr (i, 1, n + 1) cin >> arr[i];
	int c = 1;
	s[1] = 1;
	fr (i, 2, n + 1) {
		if (arr[i] % arr[i - 1]) continue;
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int idx, x;
			cin >> idx >> x;
		} else {
			int idx;
			cin >> idx;
			pr (idx);
		}
	}
	return 0;
}
