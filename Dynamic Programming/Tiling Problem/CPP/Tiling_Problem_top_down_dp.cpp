#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define blue ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007;

/*

Probelm Statement:
    Given: (2 x n) board and tiles of size (2 x 1)
    Task: Count the number of ways to tile the given board using the 2 x 1 tiles.
    Conditions: A tile can either be placed horizontally as (1 x 2) tile or vertically as (2 x 1) tile.


Solution:
    If we place 1 tile vertically, it occupies (2 x 1) area
                        OR
    We can place 2 tiles horizontally, one above another to cover (2 x 2) area
    
    There is no other way

    so we form our recursion so as to count the number of ways to to fill the board horizontally with
    either 1's or 2's 

    Recurrence Equation:
        count(n) = count(n-1) + count(n-2)

    Base conditions: 
        if n == 1, return 1
        if n == 2, return 2

    Top Down DP Approach:
        We store the values of already calculated n-values in an array called DP
*/

int dp[100000]; // Declare a DP array 

int count_using_top_down_dp(int n) {
    if(n==1) return dp[1];
    if(n==2) return dp[2];

    // Before computing check if already present and if not, compute and store
    if(dp[n-1] == -1) dp[n-1]=count_using_top_down_dp(n-1); 

    if(dp[n-2] == -1) dp[n-2]=count_using_top_down_dp(n-2);

    return dp[n-1]+dp[n-2];
}

int main() {
    int n, total_number_of_ways; 
    
    n = 12; // The board is of size (2 x 12)

    memset(dp,-1,sizeof(dp)); // Initialize the dp array with -1
    
    dp[1]=1; dp[2]=2; // base conditions

    total_number_of_ways = count_using_top_down_dp(n);


    cout<<"The Total Number of ways to Tile the board are: "<<total_number_of_ways<<endl;
}

