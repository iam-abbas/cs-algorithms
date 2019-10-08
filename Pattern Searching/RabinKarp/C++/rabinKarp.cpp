#include <bits/stdc++.h>
using namespace std;

// limit for characters
#define limit 256

void rabinKarp(string pat, string txt, int prime)
{
    int M = pat.length();
    int N = txt.length();

    int ph = 0; // hash value for pattern
    int th = 0; // hash value for txt
    int hash = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (int i = 0; i < M - 1; i++)
        hash = (hash * limit) % prime;

    //hash value for pattern and first window in txt
    for (int i = 0; i < M; i++)
    {
        ph = (limit * ph + pat[i]) % prime;
        th = (limit * th + txt[i]) % prime;
    }

    // Sliding window one by one
    for (int i = 0; i <= N - M; i++)
    {

        // Checking for hash values of the pattern
        //  and window, if they match then only
        // match the characters
        int j;
        if (ph == th)
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }

            // if pH == tH and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            //pattern found
            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text
        if (i < N - M)
        {
            th = (limit * (th - txt[i] * hash) + txt[i + M]) % prime;

            //if th value is negative, convert it to positive
            if (th < 0)
                th = (th + prime);
        }
    }
}

int main()
{
    string text = "ABCDCDACDBCDA";
    string pattern = "CDA";
    int prime = 101; // A prime number
    rabinKarp(pattern, text, prime);
    return 0;
}