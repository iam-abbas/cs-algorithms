 
#include<bits/stdc++.h> 
using namespace std; 

int uKnapsack(int C, int N, int value[], int weight[]) 
{ 
	int Knap[C+1]; 
	memset(Knap, 0, sizeof Knap); 

	int res = 0; 
	for (int i=0; i<=C; i++) 
	for (int j=0; j<N; j++) 
		if (weight[j] <= i) 
			Knap[i] = max(Knap[i], Knap[i-weight[j]]+value[j]); 

	return Knap[C]; 
} 

int main() 
{ 
	int Capacity = 100; 
	int value[] = {15, 20, 30}; 
	int weight[] = {5, 10, 15}; 
	int n = sizeof(value)/sizeof(value[0]); 

	cout << uKnapsack(Capacity, n, value, weight); 

	return 0; 
} 
