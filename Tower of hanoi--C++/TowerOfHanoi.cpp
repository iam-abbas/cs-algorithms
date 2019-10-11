#include <bits/stdc++.h>
using namespace std; 

void towerOfHanoi(int n, char sor, char des, char aux) 
{ 
	if (n == 1) 
	{ 
		cout << "Move disk 1 from rod " << sor << " to rod " << des<<endl; 
		return; 
	} 
	
	towerOfHanoi(n - 1, sor, aux, des); 
	cout << "Move disk " << n << " from rod " << sor << " to rod " << des << endl; 
	towerOfHanoi(n - 1, aux, des, sor); 
} 
int main() 
{ 
	int n = 3; // Number of disks 
	towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
	return 0; 
} 

