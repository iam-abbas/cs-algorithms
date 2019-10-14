#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n; cin>>n;
    int i=0;
    int rem;
    int octal=0;
    while(n>0)
    {
        rem=n%8;
        octal=octal+rem*pow(10,i);
        n=n/8;
        i++;
    }
    cout<<octal;

}
