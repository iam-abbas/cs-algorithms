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
*/

int count_using_recursion(int n) {
    if(n==1) return 1;
    if(n==2) return 2;

    return count_using_recursion(n-1)+count_using_recursion(n-2);
}

int main() {
    int n, total_number_of_ways; 
    
    n = 12; // The board is of size (2 x 12)

    total_number_of_ways = count_using_recursion(n);

    cout<<"The Total Number of ways to Tile the board are: "<<total_number_of_ways<<endl;
}

