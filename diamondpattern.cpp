/*PROGRAM TO PRINT PATTERN
        1
      2 3 2
    3 4 5 4 3
      2 3 2
        1
 FOR N=5 AND SO ON */


#include<iostream>
using namespace std;
int main()
{
    int n,row,col,k,j;
    cin>>n;
    row=1,k=1,j=1;
    while(row<=n)
    {
        col=1;
        while(col<=n)
        {
            if(col<=n/2+1-k || col>=n/2+1+k)
                cout<<" ";
            else
              {
                  cout<<j;

                  if(col<n/2+1)
                    j=j+1;

                  else
                    j=j-1;
              }

            col=col+1;

            }
            cout<<endl;
            row=row+1;
            if(row<=n/2+1)
            {
                k=row;
                j=row;
            }
            else
             {
                 k=n+1-row;
                j=n+1-row;
             }
    }

    return 0;
}
