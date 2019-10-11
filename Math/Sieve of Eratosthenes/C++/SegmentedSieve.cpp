//Segemented Sieve: Generate prime numbers less than N
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void simpleSieve(ll limit, vector<ll>& prime){
    bool isPrime[limit+1];
    memset(isPrime, true, sizeof(isPrime));
    for(int i=2;i*i<limit;++i){
        if(isPrime[i]){
            for(int j=i*i;j<limit;j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(int i=2;i<limit;i++){
        if(isPrime[i]){
            cout<<i<<" ";
            prime.push_back(i);
        }
    }
}
void segmentedSieve(ll n){
    ll limit = sqrt(n)+1;
    vector<ll> prime;
    simpleSieve(limit,prime);
    ll low = limit;
    ll high = 2*limit;
    while(low<n){
        if(high>n){
            high = n;
        }
        bool mark[limit+1]; 
        memset(mark, true, sizeof(mark)); 
        for(int i=0;i<prime.size();++i){
            ll curPrime = prime[i];
            ll base = (low/curPrime)*curPrime;
            if(base<low){
                base = base + curPrime;
            }
            for(int j=base;j<high;j+=curPrime){
                mark[j-low] = false;
            }
            if(base==curPrime)
                mark[base-low] = true;
        }
        for(int i=low;i<high;i++){
            if(mark[i-low])
                cout<<i<<" ";
        }
        low = low + limit;
        high = high + limit;
    }
}
int main()
{
    segmentedSieve(10000);
}