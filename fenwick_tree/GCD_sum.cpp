/*
				C++
				encoding: UTF-8
				Modified: <01/Oct/2019 03:02:07 PM>

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
#define int long long

const int N = 1e6 + 5;
int arr[N];
int bit[N];
int n;
const int mod = 1e9 + 7;

int phi[N], F[N];
void precompute () {
	fr (i, 1, N) {
		phi[i] += i;
		phi[i] %= mod;
		for (int j = 2 * i; j < N; j += i) {
			phi[j] -= phi[i];
			phi[j] = (phi[j] + mod) % mod;
		}
	}
	fr (i, 1, N) {
		for (int j = i; j < N; j += i) {
			F[j] += j / i * phi[i];
			F[j] = (F[j] + mod) % mod;
			// F[j] %= mod;
		}
	}
}

int query (int x) {
	int ans = 0;
	for (; x > 0; x -= (x & (-x))) {
		ans += bit[x];
		ans %= mod;
	}
	ans = (ans + mod) % mod;
	// ans %= mod;
	return ans;
}

void update (int x, int val, int previous) {
	for (; x <= n; x += (x & (-x))) {
		bit[x] -= previous;
		bit[x] += val;
		bit[x] %= mod;
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	precompute ();
	cin >> n;
	fr (i, 1, n + 1) cin >> arr[i];

	dfr (i, n, 0) {
		update (i, F[arr[i]], 0);
	}

	int tc;
	cin >> tc;
	while (tc--) {
		char t;
		int x, y;
		cin >> t >> x >> y;
		if (t == 'C') {
			int b = query (y);
			int a = query (x - 1);
			pr ((b - a + mod) % mod);
		} else {
			int p = F[arr[x]];
			arr[x] = y;
			update (x, F[y], p);
		}
	}
	return 0;
}
