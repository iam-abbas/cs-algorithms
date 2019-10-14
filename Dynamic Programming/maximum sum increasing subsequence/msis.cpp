
#include <bits/stdc++.h> 
using namespace std; 

int maxSum(int a[], int N) 
{ 
	int i, j, max = 0; 
	int dp[N]; 

	for ( i = 0; i < N; i++ ) 
		dp[i] = a[i]; 

	for ( i = 1; i < N; i++ ) 
		for ( j = 0; j < i; j++ ) 
			if (a[i] > a[j] && 
				dp[i] < dp[j] + a[i]) 
				dp[i] = dp[j] + a[i]; 

	return *max_element(dp, dp+N); 
} 


int main() 
{ 
	int arr[] = {1, 100, 6, 4, 105, 2, 3}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Sum of elements in the maximum sum increasing "
			"subsequence is " << maxSum( arr, n ) << endl; 
	return 0; 
} 

