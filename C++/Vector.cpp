#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //Program to study vectors and see its different functions use
    vector<int> v;
    int n;
    v.reserve(469);
    cin>>n;
    v.push_back(n);
    cout<<v.size()<<endl;
    v.clear();
    cout<<v.size()<<endl;
    cout<<v[0]<<" "<<v.capacity()<<endl;
    cout<<v.max_size()<<endl;

    return 0;
}
