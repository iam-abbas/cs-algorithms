//hackerearth problem picked from noveasy19
//Problem url:https://www.hackerearth.com/problem/algorithm/money-exchange-48c4a575/

/*question:There are n types of money denomination in your country having values a1,a2,..an .
You went to a shop to buy a product worth p units,
predict whether is it possible to complete the purchase or not 
(You and the shopkeeper can choose notes of each denomination any number of times).
You need to process Q queries for this. 
Print "YES" if it is possible to complete the purchase,
else print "NO".*/

//Program
#include<bits/stdc++.h>

using naemespace std;

#define llt long long int
int main()
{
    llt t n,q;
    cin>>n>>q;
    //long long int type
    llt a[n],g=0;
    for(llt i=0;i<n;i++)
    {
        cin>>a[i];
        //__gcd is inbuild funtion in cpp to calculate gcd of two numbers
        g=__gcd(a[i],g);
    }
    
    //q number of query
    
    while(q--)
    {
     llt p;
     cin>>p;
     if(__gcd(g,p)==g)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }

}

/*
Input:
2 2
6 9
3
4
Output:
YES
NO

Note:For the first query p=3 , you give a note of 9 to the salesman and he returns 6  to you,
hence the purchase completed successfully.
*/
