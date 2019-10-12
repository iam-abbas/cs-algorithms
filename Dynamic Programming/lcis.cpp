// C++ program to find length of the longest Common increasing Subsequence 
#include<bits/stdc++.h> 
using namespace std; 

// Returns the length and the lcis of two arrays a1[0..n-1] and a2[0..m-1] 
int lcis(int a1[], int n, int a2[], int m) 
{ 
	
	int table[m]; 
	for (int j=0; j<m; j++) 
		table[j] = 0; 

	// Traverse all elements of a1[] 
	for (int i=0; i<n; i++) 
	{ 
		// current length of lcis
		int c = 0; 

		
		for (int j=0; j<m; j++) 
		{ 
			
			if (a1[i] == a2[j]) 
				if (c + 1 > table[j]) 
					table[j] = c + 1; 

		
			if (a1[i] > a2[j]) 
				if (table[j] > c) 
					c = table[j]; 
		} 
	} 


	int result = 0; 
	for (int i=0; i<m; i++) 
		if (table[i] > result) 
		result = table[i]; 

	return result; 
} 

/* Driver program to test above function */
int main() 
{ 
	int a1[] = {2,3, 4, 9, 1}; 
	int a2[] = {5, 3, 8, 9, 10, 2, 1}; 

	int n = sizeof(a1)/sizeof(a1[0]); 
	int m = sizeof(a2)/sizeof(a2[0]); 

	cout << "Length of longest common increasing subsequence is "
		<< lcis(a1, n, a2, m); 
	return 0;
} 
