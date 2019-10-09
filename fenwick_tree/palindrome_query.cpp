//problem link=https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-palindrome-research/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define len(a) (int)a.size()
#define fr(i,x,y) for(int i=x;i<y;i++)
using namespace std;
 
const int N=1e6+5;
 
int a[N];
int BIT[26][N];
 
void update(int x,int val,int n,char ch){
    for(;x<=n;x+=(x&-x)) BIT[ch-'a'][x]+=val;
}
 
int query(int l,int r){
    int sum=0;
    for(;l>0;l-=(l&-l)) {
      sum+=BIT[r][l];
    }
    
    return sum;
}
 
int main()
{   
    fast
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
 
    memset(BIT,0,sizeof(BIT));
 
    int nn=len(s);
 
    for(int i=1;i<=nn;i++){
      update(i,1,nn,s[i-1]);
    }
 
 
    fr(i,0,q){
      int x;
      cin>>x;
      if(x==2){
        int l,r;
        cin>>l>>r;
        bool flag1=false,flag2=true;
        fr(i,0,26){
        if((query(r,i)-query(l-1,i))%2!=0 and flag1==false) flag1=true;
        else if((query(r,i)-query(l-1,i))%2!=0 and flag1==true){
            flag2=false;
            break;
        } 
      }
 
      if(flag2) cout<<"yes\n";
      else
      cout<<"no\n";
 
      }else{
        int index;
        char c;
        cin>>index>>c;
        update(index,-1,nn,s[index-1]);
        update(index,1,nn,c);
        s[index-1]=c;
 
      }
    }
}
