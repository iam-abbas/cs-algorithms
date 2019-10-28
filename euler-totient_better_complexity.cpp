#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

//to calculate prime numbers which are stored in prime vector
int sieve[1000000];
vector<int> prime;
void init()
{
	for(int i=0;i<1000000;i++)
	{
		sieve[i]=0;
	}
	
}
void getprime()
{
	int i,j;
	for(i=2;i*i<1000000;i++)
	{
		if(!sieve[i])
		{
			for(j=i*i;j<1000000;j=j+i)
			{
				sieve[j]=1;
			}
		}
	}
	
	for(i=2;i<1000000;i++)
	{
		if(!sieve[i])
			prime.push_back(i);
	}
	//cout<<prime.size();
}


// totient function
int totientfunc(int n)
{
	int i;
	int ans=n;
	for(i=0;prime[i]*prime[i]<=n && i<prime.size();i++)
	{
		if(n%prime[i]==0)
		{
			ans=ans*(1-1.0/prime[i]);
			while(n%prime[i]==0)
			{
				n=n/prime[i];
			}
		}
	}
	if(n>1)
	{
		ans=ans*(1-1.0/n);
	}
	return ans;
}


// driver code to run the euler totient function and get the prime numbers
int main() {
	fastIO;
	
    init();
    getprime();
	int n,i,j;
	int t,q;
    for(i=1;i<=10;i++)
    {
    	cout<<totientfunc(i)<<endl;
    }

	return 0;
}
