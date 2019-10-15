
#include <bits/stdc++.h> 
using namespace std; 

void nutboltmatch(char nuts[], char bolts[], int n) 
{ 
	unordered_map<char, int> hash; 

	for (int i = 0; i < n; i++) 
		hash[nuts[i]] = i; 

	for (int i = 0; i < n; i++) 
		if (hash.find(bolts[i]) != hash.end()) 
			nuts[i] = bolts[i]; 
	cout << "matched nuts and bolts are-" << endl; 
	for (int i = 0; i < n; i++) 
		cout << nuts[i] << " "; 
	cout << endl; 
	for (int i = 0; i < n; i++) 
		cout << bolts[i] << " "; 
} 

int main() 
{ 
	char nuts[] = {'@', '#', '$', '%', '^', '&'}; 
	char bolts[] = {'$', '%', '&', '^', '@', '#'}; 
	int n = sizeof(nuts) / sizeof(nuts[0]); 
	nutboltmatch(nuts, bolts, n); 
	return 0; 
} 

