
#include<bits/stdc++.h> 
using namespace std;
int count(int n, int m) 
{ 
	int stairs[n]; 
	stairs[0] = 1; stairs[1] = 1; 
	for (int i=2; i<n; i++) 
	{ 
	stairs[i] = 0; 
	for (int j=1; j<=m && j<=i; j++) 
		stairs[i] += stairs[i-j]; 
	} 
	return stairs[n-1]; 
} 

// Returns number of ways to reach n'th stair 
int countstairs(int n, int m) 
{ 
	return count(n+1, m); 
} 


int main () 
{ 
	int n = 7, m = 3; 
	cout<<"Number of ways : "<<countstairs(n, m); 
	return 0; 
} 
