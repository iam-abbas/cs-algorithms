#include<bits/stdc++.h> 
using namespace std; 


unsigned long int cata(unsigned int n) 
{ 

	if (n <= 1) return 1; 


	unsigned long int result = 0; 
	for (int i=0; i<n; i++) 
		result += cata(i)*cata(n-i-1); 

	return result; 
} 


int main() 
{ 
  cout<<" Catalan numbers upto 40 : "<<endl;
	for (int i=0; i<40; i++) 
		{
      cout << cata(i) <<" "; 
	  }
  return 0; 
} 
