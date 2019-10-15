#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int temp=n;
	int dec=0;
	int t=1;
	int base=1;
	while(temp)
	{
		t=temp%10;
		dec=dec+t*base;
		base=base*2;
		temp=temp/10;

	}
	cout<<dec<<endl;
	return 0;
}
