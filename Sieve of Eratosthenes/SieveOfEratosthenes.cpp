#include <iostream>
#include <string>
using namespace std;
/*
Sieve of Eratosthenes

Compiled Using Visual Studio 2019
by Divakar Lakhera
*/

/*
		char* sieveOfEratosthenes(int limit)
			- returns char* buffer of size "limit+1" with all the positions marked "1" for primes.
			- returns NULL if "limit" is set to "0".
*/

char* sieveOfEratosthenes(int limit)
{
	if (limit != 0) {
		char* buf = (char*)malloc(sizeof(char) * (limit + 1));
		if (buf == NULL)
		{
			cout << "Fatal: Internal error \"Cannot Malloc\" " << endl;
			exit(-1);
		}
		memset(buf, 1, limit + 1);

		for (int i = 2; i * i <= limit; i++)
		{
			if (buf[i] == 1)
			{
				for (int j = i * i; j <= limit; j += i)
				{
					buf[j] = 0;
				}
			}
		}
		return buf;
	}
	else
	{
		return NULL;
	}
}


void dispPrimes(int limit)
{

	char* a = sieveOfEratosthenes(limit);
	if (a != NULL) {
		for (int i = 2; i < limit; i++)
		{
			if (a[i] == 1)
			{
				cout << i << " ";
			}
		}
	}
	else
	{
		cout << "ERROR: Limit Set to 0" << endl;
	}
}
/*

Dummy main to check Function

int main()
{
	dispPrimes(0);
	return 0;
}
*/