#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int beg,int mid,int end)
{
    int a[10];
    int k=0,i=beg,j=mid+1;

    while(i<=mid&&j<=end)
    {
        if(arr[i]<arr[j])
        {
            a[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            a[k]=arr[j];
            k++;
            j++;
        }
    }

    if(i>mid)
    {
        while(j<=end)
        {
            a[k]=arr[j];
            k++;
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            a[k]=arr[i];
            k++;
            i++;
        }
    }
    int l=0;
    for(int i=beg;i<=end;i++)
    {
      arr[i]=a[l];
      l++;
    }

}


void mergesort(int arr[],int beg,int end)
{
    if(beg<end)
    {
        int mid=(beg+end)/2;
        mergesort(arr,beg,mid);
        mergesort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }

}

int main()
{
    int arr[10]={5,3,7,9,11,8,2,4,10,6};

    mergesort(arr,0,9);
    for(int i=0;i<10;i++)
        cout<<arr[i]<<endl;
    return 0;

}
