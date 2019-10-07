#include<iostream>
#include<bits/stdc++.h>
using namespace std;


long long int count( long long int S[], long long int m, long long int n )  
{   
    int table[m+1][n+1];   
    memset(table, 0, sizeof(table));  
     
    for(long long int i=0;i<=m;i++) 
   {
       table[i][0] = 1;  
   } 
    for(long long int i=1;i<=m;i++) 
      { 
            
          for(long long int j=1;j<=n;j++) 
          { 
              if(S[i-1]>j) 
              { 
                  table[i][j]=table[i-1][j]; 
                    
              } 
                
              else
              { 
                  table[i][j]=table[i-1][j]+table[i][j-S[i-1]]; 
              } 
                
          } 
      } 
    return table[m][n];  
} 
int main()
 {
	int t;long long int n,m,i;
	cin>>t;
	while(t--){
	    cin>>m;
	    long long int S[m];
	    for(i=0;i<m;i++)
	        cin>>S[i];
	    cin>>n;
	    cout<<count(S,m,n)<<endl;
    }
	return 0;
}