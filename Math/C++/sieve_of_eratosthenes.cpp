// C++ program to print all primes smaller than or equal to 
// n using Sieve of Eratosthenes in O(n*log(log(n)))

#include <iostream>
#include<vector> 
using namespace std;

vector < bool > prime; // vector of bool to store whether number is prime or not.
void sieve(int n) 
{ 
	prime.resize(n + 1); // re-sizing the vector to required size

	for(int j = 0; j <= n; j++)
		prime[j] = true;        // Initially we consider all numbers to be prime and then sieve them out
								            // prime[x] is true implies x is a prime number

	for (int p=2; p*p<=n; p++) 
	{ 
		// If prime[p] is not changed, then it is a prime 
		if (prime[p] == true) 
		{ 
			// Update all multiples of p greater than or 
			// equal to the square of it 
			// numbers which are multiple of p and are 
			// less than p^2 are already been marked. 
			for (int i=p*p; i<=n; i += p) 
				prime[i] = false; 
		} 
	} 
} 

// Program to test above function 
int main() 
{ 
	int n = 100; 
	sieve(n);
	cout << "Following are the prime numbers smaller than or equal to " << n << endl;
	for(int j = 2; j <= n; j++)
		if(prime[j])
			cout << j << endl;  
	return 0; 
} 
