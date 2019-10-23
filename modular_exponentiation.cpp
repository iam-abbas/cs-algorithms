#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int 
#define pb push_back
#define mp make_pair
#define rep(a,b,c) for(int i = a; i < b; i+=c)

/* Iterative Function to calculate (x^y) in O(log y) */
int power(int x, unsigned int y) 
{ 
    int res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 
        // y must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}

int main()
{
	int n,m;
	cin>>n>>m;
	cout<<power(n,m)<<endl;
	return 0;
}