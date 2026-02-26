#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n; 
    //Input number
    cout<<"Enter number in decimal: "
    cin >> n;
    int i=0, rem, octal=0;
    
    //While number is greater than zero
    while(n>0)
    {
        //% calculate the remainder. In this case after dividing by 8
        rem = n % 8;
        
        octal = octal + rem * pow(10,i);
        n = n / 8;
        i++;
    }
    
    //Number in octal
    cout << "Number in octal is: " << octal;

}
