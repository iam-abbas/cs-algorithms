//This program uses the Mathematical definition of nth Catalan number
//nth catalan_no = C(2*n,n)/(n+1)

#include<iostream>
using namespace std;
#define MAXN 20

// Function to Calculate value of Binomial Coefficient C(n, k)
long long binomialCoefficient(long long n, long long k)
{
	long long result = 1;

	// Since C(n, k) = C(n, n-k)
	if (k > n - k)
		k = n - k;

	// Calculation of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
	for (int i = 0; i < k; ++i)
	{
		result *= (n - i);
		result /= (i + 1);
	}

	return result;
}

// A Binomial coefficient based function to find nth catalan
// number in O(n) time
long long catalan_no(long long n)
{
	// Calculate value of 2nCn
	long long c = binomialCoefficient(2*n, n);

	// return 2nCn/(n+1)
	return c/(n+1);
}

int main()
{
	for (int i = 0; i < MAXN; i++)
		cout << catalan_no(i) << " ";
	return 0;
}
