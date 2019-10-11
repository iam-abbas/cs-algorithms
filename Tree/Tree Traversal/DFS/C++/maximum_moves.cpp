/*
				C++
				encoding: UTF-8
				Modified: <11/Oct/2019 09:57:40 PM>

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

const int N = 5e5 + 5;
ve< int > graph[N];
int depth[N];
int n, k;
int ans;

void init () {
	fr (i, 0, n + 5) {
		graph[i].clear ();
		depth[i] = 0;
	}
	ans = 0;
}

int dfs (int node, int parent) {
	int y = 0;
	for (int to : graph[node]) {
		if (to == parent) continue;
		y = max (y, dfs (to, node));
	}
	depth[y]++;
	return y + 1;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		init ();
		fr (i, 1, n) {
			int u, v;
			cin >> u >> v;
			graph[u].pb (v);
			graph[v].pb (u);
		}
		int x = dfs (1, 1);
		depth[x]++;

		fr (i, 0, k) ans += depth[i];
		pr (ans);
	}

	return 0;
}
