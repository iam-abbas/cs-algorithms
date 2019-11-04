#include<bits/stdc++.h>

using namespace std;

int findmin(vector<int> dist,int N,std::vector<int> &freq){
  int mint;
  for(int i=0;i<N;i++){if(freq[i] == 0){mint = i;break;}}
  for(int i=0;((i<N));i++){
    if((freq[i]==0)){
    if(dist[mint]>dist[i]){mint = i;}
  }
  }
  freq[mint] = 1;
  return mint;
}

void printvector(std::vector<int> v,int N){
  for(int i=0;i<N;i++)cout<<v[i]<<' ';
  cout<<endl;
}
void dijkstras(vector<int> &dist,std::vector<std::vector<int> > l,vector<int> &prev,int N){
  // printvector(dist,N);
  vector<int> freq;
  for(int i=0;i<N;i++){freq.push_back(0);}
  dist[0] = 0;
  for(int j=0;j<N;j++){
    int u = findmin(dist,N,freq);
    for(int i=0;i<N;i++){
      if(l[u][i] != -1){
        if(dist[i] > (dist[u] + l[u][i])){
          dist[i] = (dist[u] + l[u][i]);
          prev[i] = u;
        }
      }
    }
    // printvector(dist,N);
  }
}
int main(){
  int N;cin>>N;
  vector<int> dist,prev;
  vector<vector<int>> l;
  int E;cin>>E;

  vector<int> temp;
  for(int i =0;i<N;i++){
    temp.push_back(-1);
    dist.push_back(INT_MAX);
    prev.push_back(-1);
  }
  for(int i=0;i<N;i++){
    l.push_back(temp);
  }

  for(int i=0;i<E;i++){
    int a,b,d;cin>>a>>b>>d; //format is a --(d)--> b represents an edge
    l[a-1][b-1] = d;
    // l[b][a] = d;
  }

  dijkstras(dist,l,prev,N);

  printvector(prev,N);
}
