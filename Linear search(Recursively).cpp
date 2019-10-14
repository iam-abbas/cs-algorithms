#include<iostream>
using namespace std;
int linearSearch(int *a,int i,int n,int key)
{
    // If element is not present then it will return -1
    if(i==n)
    {
        return -1;
    }
    //If the element is present then it will return the index where the element is present
    if(a[i]==key)
    {
        return i;
    }
    return linearSearch(a,i+1,n,key);
}
int main()
{
    int a[6]={1,3,2,5,6,9};
    int n=sizeof(a)/sizeof(int);
    int key = 15;
    cout<<linearSearch(a,0,n,key);
    return 0;
}
