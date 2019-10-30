#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int smallOutput1 = fibonacci(n-1);
    int smallOutput2 = fibonacci(n-2);
    return smallOutput1 + smallOutput2;
}

int main()
{
    int n;
    cin>>n;
    int output = fibonacci(n);
    cout<<output;
}