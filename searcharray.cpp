#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cout<<"Enter size of the array:"<<endl;
cin>>n;
int arr[n];
cout<<"Enter array elements:"<<endl;
for(int i=0;i<n;i++)
cin>>arr[i];
int x;
cout<<"Enter number to be found:"<<endl;
cin>>x;
//search
for(int i=0;i<n;i++){
if(arr[i]==x){
cout<<"Element found at:"<<i+1<<endl;
        }
  }
return 0;
}
