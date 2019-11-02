#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void shuffle(int *a,int s,int e)
{
    srand(time(NULL));
    int i,j,temp;
    for(int i=e;i>0;i--)
    {
        // create one random index
        j=rand()%(i+1);
        swap(a[i],a[j]);
    }
}

int partition(int *a,int s,int e)
{
    int i=s-1;
    int j=s;
    int pivot=a[e];
    for( ;j<e;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    // Bring the pivot element to its sorted position
    swap(a[i+1],a[e]);
    return i+1;
}
void quickSort(int *a,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int p=partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}
int main()
{
    int a[]={1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(int);
    shuffle(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

