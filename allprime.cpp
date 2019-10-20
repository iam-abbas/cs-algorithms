//PROGRAM TO PRINT FIRST N PRIME NUMBERS

#include<iostream>
using namespace std;
int main()
{
 int i,n=2,N,j;
 cin>>N;
     for(i=1;i<=N;i++)
     {
         for(j=2;j<=n;j++)
         {
         if(n%i==0)
          continue;
         }
         cout<<endl<<n;
         n++;
     }



 return 0;
}
