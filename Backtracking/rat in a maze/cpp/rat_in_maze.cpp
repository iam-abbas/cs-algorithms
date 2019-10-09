/*
given a grid matrix , you have to find ways to get rat from 0,0 to n-1,n-1
there is obstacles in path represented by 0
if path is clean represented  by 1
you have to print all such paths
*/


#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector<string>vvv;
vector<string> printPath(int m[MAX][MAX], int n);
bool find(int m[MAX][MAX],int n,int i,int j,string s,int visi[MAX][MAX]){
if(i==n-1&&j==n-1){
  //printpath
  vvv.push_back(s);
  return false;
}
if(i==n||j==n||i<0||j<0){
  return false;
}
if(m[i][j]==0){
  return false;
}
visi[i][j]=1;
bool left=false,right=false,down=false,up=false;
if(j+1<n&&visi[i][j+1]!=1){visi[i][j+1]=1;
right=find(m,n,i,j+1,s+'R',visi);
visi[i][j+1]=0;
}
if(i+1<n&&visi[i+1][j]!=1){visi[i+1][j]=1;
 down=find(m,n,i+1,j,s+'D',visi);
 visi[i+1][j]=0;

}

if(i-1>=0&&visi[i-1][j]!=1){visi[i-1][j]=1;
 up=find(m,n,i-1,j,s+'U',visi);
 visi[i-1][j]=0;
}
if(j-1>=0&&visi[i][j-1]!=1){visi[i][j-1]=1;
 left=find(m,n,i,j-1,s+'L',visi);
 visi[i][j-1]=0;
}
if(right||down||up||left){
  return true;
}
return false;



}
vector<string> printPath(int m[MAX][MAX], int n){
    string s="";
 int visi[MAX][MAX];
  vvv.clear();
  find(m,n,0,0,s,visi);
 sort(vvv.begin(),vvv.end());
    return vvv;
}
int main() {
  // your code goes here
  int t;
  cin>>t;
  while(t--){
  int n;
  cin>>n;
  
  int m[100][100];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>m[i][j];
    }
  }
  
  vector<string> res = printPath(m,n);
  for(int i=0;i<res.size();i++)
  cout<<res[i]<<" ";
  cout<<endl;
}

/*
input:1
4
1 0 0 0
1 1 1 1
0 1 0 1
1 1 1 1 




output:
DRDDRR DRRRDD 



*/

  return 0;
}

