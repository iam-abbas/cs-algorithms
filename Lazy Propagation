#include<bits/stdc++.h>
using namespace std;

#define intmax 1000000
#define endl "\n"
#define add(a,b) a+b

typedef long long ll ;

ll tree[intmax];
ll lazy[intmax];

void update(ll node , ll start , ll end, ll l ,ll r, ll value)
{


    if(lazy[node]!= 0)
    {
        tree[node]+= (end-start +1)*lazy[node];
        if(start != end)
        {
            lazy[node*2]+= lazy[node];
            lazy[node*2+1]+= lazy[node];
        }
        lazy[node]=0;
    }
     if(start>end || r <start || l>end)
        return;
    if(l<= start && end<= r)
    {
        tree[node]+=(end-start +1) *value;
        if(start != end)
        {
            lazy[node*2]+=value;
            lazy[node*2+1]+= value;
        }
        return;
    }
    ll mid = (start+end)/2;
    update(node*2,start,mid,l,r,value);
    update(node*2+1,mid+1,end,l, r,value);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query (ll node , ll start, ll end , ll l, ll r)
{
    if(r<start || l> end ||start >end)
    {
        return 0;
    }
    if(lazy[node]!= 0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if(start != end)
        {
            lazy[node*2]+= lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]= 0;
    }
    if(l<= start && end <= r)
    {
        return tree[node];
    }
    ll mid = (start+end)/2;
    ll p1 = query(2*node, start ,mid , l, r);
    ll p2 = query(2*node +1, mid +1 , end, l , r);
    return (add(p1,p2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;

    while(t--){
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
    ll n , q;
    cin >> n>> q;
    while(q--)
    {

        int ch ;
        cin >> ch;
        if(ch == 1)
        {
            ll l ,r;
            cin >> l >>r;
            cout<<query(1,0,n-1,l-1,r-1)<<endl;
        }
        else
        {
            ll l  , r, value;
            cin >> l>>r>>value;
            update(1,0,n-1,l-1, r-1,value);
        }
    }
    }
    return 0;
}
