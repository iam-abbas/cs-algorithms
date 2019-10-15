//Max sum array problem using Kadane's Algorithm
//Kadane's Algorithm helps us to reduce the for loop
//which are used to find the max sub array sum.
#include<iostream>
using namespace std;
int main()
{
    int a[100]={0};
    int n;
    int cs=0;//cs is the current sum
    int ms=0;//ms is the maximum sum
    cout<<"Enter the number of elements in the array";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cs = cs+a[i];
        if(cs<0)
        {
            cs=0;
        }
        ms=max(cs,ms);
    }
    cout<<"Maximum Sum"<<ms<<endl;
    return 0;
}
