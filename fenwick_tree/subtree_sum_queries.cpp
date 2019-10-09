//problem link=https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/rescue-brook/

#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+10;

int tin[N], tout[N];
int isprime[N];
int bit[N];
int a[N];
vector<int> g[N];
int n, q, timer;

void update(int i, int x,int n){
    while(i <= n){
        bit[i] += x;
        i = i + (i & (-i));
    }
}

int query(int i){
    int ans = 0;
    while(i != 0 && i > 0){
        ans += bit[i];
        i = (i & (i-1));
    }
    return ans;
}


void dfs(int v, int p){
    tin[v] = ++timer;
    for(auto it : g[v]){
        if(it == p)
            continue;
        dfs(it, v);
    }
    tout[v] = timer;
}

void sieve(){
    memset(isprime,0,sizeof(isprime));
    isprime[0]=isprime[1]=1;

    for(int i=2;i*i<N;i++){
        if(!isprime[i]){
            for(int j=2*i;j<N;j+=i) isprime[j]=1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin>>t;
    while(t--){

        cin>>n>>q;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
        }
        timer=0;
        for(int i=1;i<=n;i++){
            g[i].clear();
            tin[i]=tout[i]=bit[i]=0;
        }

        int u, v, type, x;

        for(int i = 1; i < n; ++i){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1,0);

        for(int i = 1; i<= n; ++i){
            if(a[i]>0 and isprime[a[i]]==0)
                update(tin[i],1,n);
        }


        while(q--){

            cin>>type;

            if(type == 1){
                cin>>u>>x;
                if(a[u]>0 and isprime[a[u]]==0){
                    if(x>0 and isprime[x]==1)
                      update(tin[u],-1,n);

                }else if((a[u]>0 and isprime[a[u]]==1) or a[u]<=0){
                    if(x>0 and isprime[x]==0)
                    update(tin[u],1,n);
                }
                a[u]=x;

            }
            else{

                cin>>u;
                printf("%d\n", query(tout[u]) - query(tin[u] - 1));
            }
        }
    }
}
