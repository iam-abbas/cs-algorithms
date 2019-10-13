#include<iostream>
using namespace std;

sumofarray(int arr[], int n)
{
    if(n==0) return 0;
    int ans=sumofarray(arr+1,n-1);
    return arr[0]+ans;
}

int main()
{
    int n;cin>>n;
    while(n--)
    {
        int a; cin>>a;
        int arr[a];
        for(int i=0;i<=n;i++)
        {
            cin>>arr[i];
            cout<<sumofarray(arr,a);
        }
    }
}
