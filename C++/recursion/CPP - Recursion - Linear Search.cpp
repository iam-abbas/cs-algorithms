#include<iostream>
using namespace std;

int linearSearch(int *a,int i,int n,int key)
{
    if(i==n)
    {
        return -1;
    }
    if(a[i]==key)
    {
        return i;
    }
    return linearSearch(a,i+1,n,key);
}
int main()
{
    int a[]={1,3,2,5,6,9};
    int n=sizeof(a)/sizeof(int);
    int key=5;
    cout<<linearSearch(a,0,n,key);
    return 0;
}
