#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
    //srand(1);  // same output anytime
    srand(time(NULL));  // output vary anytime
    cout<<"The no is "<<rand()%100<<endl;
    return 0;
}
