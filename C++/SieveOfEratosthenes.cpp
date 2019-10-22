#include <iostream>
#include <stdbool.h>
#include <cstring>
#include <conio.h>

using namespace std;

void SieveOfEratosthenes(int n)
{
	long int i,p;
	bool arr[n+1];
	memset(arr,true,sizeof(arr));
	for(i=2;i*i<=n;i++)
	{
		if(arr[i]==true)
		{
			for(p=i*i;p<=n;p=p+i)
			{
				arr[p]=false;
			}
		}
	}
	for(i=2;i<=n;i++)
	{
		if(arr[i]==true)
		cout<<i<<endl;
	}
}
int main()
{
	long int x;
	cin>>x;
	SieveOfEratosthenes(x);
	getch();
	return (0);
}
