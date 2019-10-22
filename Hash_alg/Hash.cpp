#include <bits/stdc++.h>

using namespace std;

const long long M = 1e6 + 1, m = 1e9 + 7, P = 31;
long long h[M], h1[M], Pow[M];

void Hash(string& s, long long* h, long long* Pow)          //main hashing alg
{
    h[0] = 0;
    Pow[0] = 1;
    for (int i = 1; i <= s.size(); i++ )
    {
        h[i] = (h[i - 1] * P + s[i - 1]) % m;
        Pow[i] = Pow[i - 1] * P % m;
    }
}

int calculateHash(long long l, long long r, long long* h, long long* Pow)           //just calculating our hash
{
    return (h[r] - h[l] * Pow[r - l] + m * m) % m;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    string s1, s2;                                                                  //just an example
    cin >> s1 >> s2;
    Hash(s1, h, Pow);
    Hash(s2, h1, Pow);
    if (calculateHash(0, s1.size(), h, Pow) == calculateHash(0, s2.size(), h1, Pow))
    {
        cout << "\nStrigs are identical";
        return 0;
    }
    cout << "\nString are non identical";
    return 0;
}

