/*
problem statement:
you have given a array . you have to tell whether it is possible tomak partition into two subsets such that each subset has eual sum

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int a[n];
    int total=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        total+=a[i];
    }
if(total%2!=0){
    cout<<"NO"<<endl;
    continue;
}
int sum=total;
bool dp[total/2+1][n+1];

//here dp represent that can we make (dp[i][j]) subset of sum i consist of j elements
//if yes then it stores true otherwise false

for(int i=0;i<=n;i++){
    dp[0][i]=true;
}
for(int i=1;i<sum/2+1;i++){
    dp[i][0]=false;
}

for(int i=1;i<sum/2+1;i++){
    for(int j=1;j<=n;j++){
        //case  1:
        dp[i][j]=dp[i][j-1];
        
        //case2:
        //not considering the current element in current subset , means 
        //we are considering in another subset
        if(i>=a[j-1]){
            dp[i][j]=(dp[i][j]||dp[i-a[j-1]][j-1]);
   
        }
    }
}

if(dp[sum/2][n]){
    cout<<"YES"<<endl;

}
else{
    cout<<"NO"<<endl;
}

/*
input 
1
3
2 4 6



output:
YES

*/


}}
