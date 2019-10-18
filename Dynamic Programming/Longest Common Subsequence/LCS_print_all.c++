#include<bits/stdc++.h>
using namespace std;

int dp[50][50];
//use recursion to print all possible solutions
//set to store the possible lcs in non-repeating and in increasing order(alphabetically)
set<string> getAllLCS(string a,string b,int n,int m)
{
	set<string> ans;

    if(n==0 || m==0)
    {
    	ans.insert("");
    	return ans;
    }

	if(a[n-1]==b[m-1])
	{
		set<string> tmp=getAllLCS(a,b,n-1,m-1);
		for(string s:tmp)
			ans.insert(s+a[n-1]);

	}


	else
	{
		 if(dp[n-1][m]>=dp[n][m-1])
		 	ans=getAllLCS(a,b,n-1,m);


		 if(dp[n][m-1]>=dp[n-1][m])
		 {
		 	set<string> tmp=getAllLCS(a,b,n,m-1);

		 	ans.insert(tmp.begin(),tmp.end());
		 }
	}

	return ans;


}
int main()
{
	string a,b;
	cin>>a>>b;

	int n=a.size();
	int m=b.size();

	

	memset(dp,0,sizeof(dp));

    //construct the lcs matrix
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}

   set<string> ans=getAllLCS(a,b,n,m);

   for(auto it:ans)
   cout<<it<<" ";	
}