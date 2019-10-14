/* C++ program to find a prime factor of composite using 
Pollard's Rho algorithm */
#include<bits/stdc++.h> 
using namespace std; 

/* Function to calculate (base^exponent)%modulus */
long long int modular_pow(long long int base, int exponent, 
						long long int modulus) 
{ 
	/* initialize result */
	long long int result = 1; 

	while (exponent > 0) 
	{ 
		/* if y is odd, multiply base with result */
		if (exponent & 1) 
			result = (result * base) % modulus; 

		/* exponent = exponent/2 */
		exponent = exponent >> 1; 

		/* base = base * base */
		base = (base * base) % modulus; 
	} 
	return result; 
} 

/* method to return prime divisor for n */
long long int PollardRho(long long int n) 
{ 
	/* initialize random seed */
	srand (time(NULL)); 

	/* no prime divisor for 1 */
	if (n==1) return n; 

	/* even number means one of the divisors is 2 */
	if (n % 2 == 0) return 2; 

	/* we will pick from the range [2, N) */
	long long int x = (rand()%(n-2))+2; 
	long long int y = x; 

	/* the constant in f(x). 
	* Algorithm can be re-run with a different c 
	* if it throws failure for a composite. */
	long long int c = (rand()%(n-1))+1; 

	/* Initialize candidate divisor (or result) */
	long long int d = 1; 

	/* until the prime factor isn't obtained. 
	If n is prime, return n */
	while (d==1) 
	{ 
		/* Tortoise Move: x(i+1) = f(x(i)) */
		x = (modular_pow(x, 2, n) + c + n)%n; 

		/* Hare Move: y(i+1) = f(f(y(i))) */
		y = (modular_pow(y, 2, n) + c + n)%n; 
		y = (modular_pow(y, 2, n) + c + n)%n; 

		/* check gcd of |x-y| and n */
		d = __gcd(abs(x-y), n); 

		/* retry if the algorithm fails to find prime factor 
		* with chosen x and c */
		if (d==n) return PollardRho(n); 
	} 

	return d; 
} 

/* driver function */
int main() 
{ 
	long long int n = 10967535067; 
	printf("One of the divisors for %lld is %lld.", 
		n, PollardRho(n)); 
	return 0; 
} 
