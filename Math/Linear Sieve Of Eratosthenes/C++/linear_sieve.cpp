#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e6+5;     // maxn is the constant upto which all primes will be calculated it can be changed according to your needs.
bool is_composite[maxn];    // is_composite[i] tells if i is a composite number or not, initially all numbers are considered as primes.
vector <int> primes;        // vector primes will be used to store primes.

/*
This algorithm will run in O(n) complexity.
Traditional Implementation of Sieve of eratosthenes (O(nlogn)) checks a composite number
multiple times and this is the bottleneck this algorithm removes which makes it much more efficient

Any composite number (p) having smallest prime factor let's denote it as spf(p) can be broken down
like this p = spf(p) * q
Since spf(p) is the smallest prime factor q >= spf(p) and no prime number smaller than spf(p) can divide q

Now let's see how the algorithm works:
- first i loops through i to maxn
- vector primes will always contain primes <= i
- mark all the composite number with primes[j] as their smallest prime factor
- if primes[j] divides i this mean's that number's formed after this iteration will not have current prime as their spf
- composite number are only marked by their spf
- each composite number is only considered once and so the compexity is O(n)

Ref:- https://codeforces.com/blog/entry/54090
*/
void sieve()
{
    // setting each number as prime in the beginning
    fill(is_composite,is_composite+maxn,false);
    // starting loop from 2 to maxn
    for(int i=2;i<maxn;i++)
    {
        // if the number is not composite i.e. prime push it to primes vector
        if(is_composite[i]==false)
        {
            primes.push_back(i);
        }
        // loop through each prime and mark composite number having current prime as it's spf
        for(int j=0;j<primes.size() && i*primes[j]<maxn;j++)
        {
            is_composite[i*primes[j]]=true;
            if(i%primes[j]==0)  // This is very important as it stops unnecessary computation's
                break;
        }
    }
}
int main()
{
    // preprocess all the prime numbers
    sieve();
    int n;
    // Enter the number of primes you want limit is the size of primes vector
    cin>>n;
    if(n > (int)primes.size())
        return cout<<"Not Enough Prime!!\n",0;
    cout<<"First "<<n<<" Prime Numbers =\n";
    for(int i=0;i<n;i++)
        cout<<primes[i]<<" \n"[i==n-1];
    return 0;
}
