#include<iostream>
using namespace std;
int stairCaseSearch(int a[][100],int R, int C, int key)
{
    int i=0,j=C-1;
    while(i<R && j>=0)
    {
        if(a[i][j]==key)
        {
            //cout<<"Found at position "<<i<<" "<<j<<endl;
            return 1;

        }
        if(a[i][j]>key)
        {
            j--;

        }
        else
        {
            i++;
        }

    }
    //<<"Element not found";
    return 0;

}
int main()
{
    int arr[100][100],R,C,NUM,ch;
    cin>>R>>C;



    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cin>>arr[i][j];

        }
    }
    cin>>NUM;
    ch=stairCaseSearch(arr,R,C,NUM);
    cout<<ch;

    return 0;

}
