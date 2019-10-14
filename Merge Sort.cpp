#include<iostream>
using namespace std;
//s stands for starting element
// e stands for last element
int merge(int *a,int s,int e)
{
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;

    int temp[100];

    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=e)
    {
        temp[k++]=a[j++];
    }
    //We need to copy all the elements to the original array
    for(int i=s;i<=e;i++)
    {
        a[i]=temp[i];

    }
}
int mergesort(int a[],int s,int e)
{
    //Base Case -1 or 0 elements
    
    if(s>=e)
    {
        return 0;
    }
    int mid =(s+e)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);

    //Merge the two parts
    merge(a,s,e);

}
int main()
{
    int a[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<",";
    }
    return 0;
}
