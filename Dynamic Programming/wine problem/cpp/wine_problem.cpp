//wine problem
/*
problem statement:
Given n wines in a row, with integers denoting the cost of each wine respectively. Each year you can sale the first or the last wine in the row. However, the price of wines increases over time. Let the initial profits from the wines be P1, P2, P3…Pn. On the Yth year, the profit from the ith wine will be Y*Pi. For each year, your task is to print “beg” or “end” denoting whether first or last wine should be sold. Also, calculate the maximum profit from all the wines.

Input: Price of wines: 2 4 6 2 5
Output: beg end end beg beg 
         64
explanation a)ans=ans+2*1    {ans=2}
            b)ans=ans+5*2    {ans=12}    
            c)ans=ans+2*3    {ans=18}
            d)ans=ans+4*4    {ans=34}
            e)ans=ans+6*5    {ans=64}

*/
#include<bits/stdc++.h>
using namespace std;

//dp solution
int maxproft(int arr[],int n){
 
// This array stores the "optimal action" 
// for each state i, j 
int dp[100][100]={0};

int year=n;
for(int i=0;i<n;i++){
    dp[i][i]=year*arr[i];    
}
year--;
//sliding window
for(int len=2;len<=n;len++){
    int srt=0;
    int end=n-len;
    while(srt<=end){
int endwindow=srt+len-1;
dp[srt][endwindow]=max(

arr[srt]*year+dp[srt+1][endwindow],
arr[endwindow]*year+dp[srt][endwindow-1]
    );
srt++;
    }
    year--;
}
/*
uncomment this to show dp table
for(int x=0;x<n;x++){
 for(int w=0;w<n;w++){
     cout<<setw(3)<<dp[x][w]<<" ";   
    }   
    cout<<endl;
}
cout<<endl<<endl;
*/return dp[0][n-1];
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int x=0;x<n;x++){
        cin>>a[x];   
    }

    cout<<maxproft(a,n)<<endl;

/*
input
4
1 4 2 3

gives:-29

5
2 3 5 1 4

gives(50) {greedy :-49 fails here};


*/


}