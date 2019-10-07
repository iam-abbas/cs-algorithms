#include <bits/stdc++.h>
using namespace std;
//Knuth-Patt-Morris Algorithm for pattern searching in given string

/*
    X is original string and Y is the pattern to be searched
     Array next stores the index where a pattern is found
    Time Conmplexity: O(m+n)
*/

// Function for KMP algorithm
void KMP(string X, string Y)
{
    int m = X.length();
    int n = Y.length();

    // if Y is an empty string
    if (n == 0)
    {
        return;
    }

    // if X's length is less than lenngth of Y
    if (m < n)
    {
        cout << "Pattern not found";
        return;
    }

    // next[i] stores the index of next best partial match
    int next[n + 1];

    for (int i = 0; i < n + 1; i++)
        next[i] = 0;

    //Building LPS(Longest prefix which is also a suffix) array
    for (int i = 1; i < n; i++)
    {
        int j = next[i + 1];

        while (j > 0 && Y[j] != Y[i])
            j = next[j];

        if (j > 0 || Y[j] == Y[i])
            next[i + 1] = j + 1;
    }

    //Searching for pattern
    for (int i = 0, j = 0; i < m; i++)
    {
        if (X[i] == Y[j])
        {
            if (++j == n)
                cout << "Pattern found at index " << i - j + 1 << endl;
        }
        else if (j > 0)
        {
            j = next[j];
            i--; // since i will be incremented in next iteration
        }
    }
}

// Program to implement KMP Algorithm in C++
int main()
{
    string text = "AASADABACSADA";
    string pattern = "SAD";

    KMP(text, pattern);

    return 0;
}