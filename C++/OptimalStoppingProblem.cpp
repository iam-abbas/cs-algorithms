#include <iostream> 
#include <time.h>
#include <cmath>
#define e 2.71828 
using namespace std; 

void printBestCandidate(int candidate[], int n) 
{ 
	int sample_size = round(n/e); 
	cout << "\n\nSample size is " << sample_size << endl; 
	int best = 0; 
	for (int i = 1; i < sample_size; i++) 
		if (candidate[i] > candidate[best]) 
			best = i;
	for (int i = sample_size; i < n; i++) 
		if (candidate[i] >= candidate[best]) { 
			best = i; 
			break; 
		} 
	if (best >= sample_size) 
		cout << endl << "Best candidate found is "
			<< best + 1 << " with talent "
			<< candidate[best] << endl; 
	else
		cout << "Couldn't find a best candidate\n"; 
} 

int main() 
{ 
	int n; 
  cin >> n;
	int candidate[n]; 
	cout << "Enter number of talents of the candidates\n"; 
	for (int i = 0; i < n; i++) 
		cin >> candidate[i]; 
	cout << "Candidate : "; 
	for (int i = 0; i < n; i++) 
		cout << i + 1 << " "; 
	cout << endl; 
	cout << " Talents : "; 
	for (int i = 0; i < n; i++) 
		cout << candidate[i] << " "; 
	printBestCandidate(candidate, n); 
	return 0; 
} 
