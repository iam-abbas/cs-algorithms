#include <bits/stdc++.h>
using namespace std;

// A utility function to get sum of array elements
// freq[i] to freq[j]
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

/* A DP based function that calculates  
minimum cost of a Binary Search Tree. */
int optimalBST(int keys[], int freq[], int n)
{
    /*Auxiliary array to store results of subproblems*/
    int cost[n][n];

    /* cost[i][j] = Optimal cost of binary search tree  
    that can be formed from keys[i] to keys[j].  
    cost[0][n-1] will store the resultant cost */

    // For a single key, cost is equal to frequency of the key
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Considering chains of L= 2,3,4...
    // L is chain length.
    for (int L = 2; L <= n; L++)
    {
        // i is row number in cost[][]
        for (int i = 0; i <= n - L + 1; i++)
        {
            // Get column number j from row number i and
            // chain length L
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in interval keys[i..j] as root
            for (int r = i; r <= j; r++)
            {
                // c = cost when keys[r] becomes root of this subtree
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}

// Driver code
int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {36, 12, 56};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << " Optimal BST cost = " << optimalBST(keys, freq, n);
    return 0;
}