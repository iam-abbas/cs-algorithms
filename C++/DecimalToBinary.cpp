#include<iostream>
using namespace std;

int main() {
	int n;
    long long int ans=0;
    cin>>n;
    int temp=n;
    int pv=1;
    int rem=1;
    while(temp)
    {
        rem=temp%2;
        ans+=pv*rem;
        pv=pv*10;
        temp=temp/2;
    }
    cout<<ans;
}
