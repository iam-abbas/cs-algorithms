#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Program to study vectors and see its different functions use
   // vector<int> v;
       vector<int> v;
    vector<int> arr{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
  
    sort(arr.begin(), arr.end()); 
  
    cout << "Sorted \n"; 
    for (int i=0;i<arr.size();i++) 
       { cout <<arr[i]<< " "; }
       cout<<"\n";
    
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

