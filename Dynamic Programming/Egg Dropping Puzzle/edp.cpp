// A Dynamic Programming based C++ Program for the Egg Dropping Puzzle 
# include <bits/stdc++.h> 

int max(int a, int b) { return (a > b)? a: b; } 
  
int eggDrop(int n, int k) 
{
    int dp[n+1][k+1]; 
    int r; 
    int i, j, x; 
  
    for (i = 1; i <= n; i++) 
    { 
        dp[i][1] = 1; 
        dp[i][0] = 0; 
    } 
  
    for (j = 1; j <= k; j++) 
        dp[1][j] = j; 

    for (i = 2; i <= n; i++) 
    { 
        for (j = 2; j <= k; j++) 
        { 
            dp[i][j] = INT_MAX; 
            for (x = 1; x <= j; x++) 
            { 
                r = 1 + max(dp[i-1][x-1], dp[i][j-x]); 
                if (r < dp[i][j]) 
                    dp[i][j] = r; 
            } 
        } 
    } 
  
    return dp[n][k]; 
} 
  
int main() 
{ 
    int n = 2, k = 36; 
    printf ("Minimum trials in worst case with %d eggs and "
             "%d floors is %d \n", n, k, eggDrop(n, k)); 
    return 0; 
} 
