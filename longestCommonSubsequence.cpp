#include<bits/stdc++.h>

using namespace std;

int lcs(string &X, string &Y, int m, int n)
{
	int dp[m+1][n+1];
	for(int i=0; i<m+1; ++i)
	{
		for(int j=0; j<n+1; ++j)
		{
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(X[i-1] == Y[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[m][n];
}

int main()
{
	//char X[] = "AGGTAB"; 
  	//char Y[] = "GXTXAYB"; 
   string X("AGGTAB");
   string Y("GXTXAYB");
  	//int m = strlen(X); 
  //	int n = strlen(Y); 
   
  	//printf("Length of LCS is %d", lcs( X, Y, m, n ) ); 
     	printf("Length of LCS is %d", lcs( X, Y, X.length(), Y.length() )); 

	return 0;
}
