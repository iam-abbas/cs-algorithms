#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the length of the array : ";
    cin>>n;
    int a[n];
    cout<<"Insert the elements to perform sorting... "<<endl;
    for (int u = 0; u <n ; u++)
    {
        cout<<"Enter the "<<u+1<<" element : ";
        cin>>a[u];
    }


    int j,key,i;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j>=0&& a[j]>key)
        {
            a[j + 1] = a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    for (i = 0; i < n; i++)
        cout<<a[i]<< " ";
    return 0;
}
