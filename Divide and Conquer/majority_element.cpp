#include <algorithm>
#include <iostream>
#include <vector>
#include<map>
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  map<int,int> m;
  for(int i=0;i<a.size();i++){
  	if(m.count(a[i])!=0){
  		m[a[i]]+=1;
	  }
	  else{
	  	m[a[i]]=1;
	  }
  }
  int eq=a.size()/2+1;
  for(auto x: m){
  	if(x.second>=eq){
  		return 1;
	  }
  }
  
  


  
  
  //write your code here
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << (get_majority_element(a, 0, a.size())) << '\n';
}
