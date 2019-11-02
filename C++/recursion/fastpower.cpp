#include <iostream>
using namespace std;

int fastPower(int a,int b)
{

    if(b==0)
    {
        return 1;
    }
    else{
        return a*fastPower(a,b-1);
    }
}

int main() {
    int a,b;
    cin>>a>>b;
    cout<<fastPower(a,b)<<endl;;
    return 0;

}
