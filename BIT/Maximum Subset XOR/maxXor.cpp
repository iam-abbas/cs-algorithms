#include<bits/stdc++.h> 
using namespace std; 
  
#define INT_BITS 32 
 
int maxSubarrayXOR(int set[], int n) 
{ 

    int indx = 0; 
 
    for (int i = INT_BITS-1; i >= 0; i--) 
    { 
        int maxInd = indx; 
        int maxEle = INT_MIN; 
        for (int j = indx; j < n; j++) 
        { 

            if ( (set[j] & (1 << i)) != 0  
                     && set[j] > maxEle ) 
                maxEle = set[j], maxInd = j; 
        } 
  
        if (maxEle == INT_MIN) 
        continue; 
  
        swap(set[indx], set[maxInd]); 

        maxInd = indx; 
   
        for (int j=0; j<n; j++) 
        {  
            if (j != maxInd && 
               (set[j] & (1 << i)) != 0) 
                set[j] = set[j] ^ set[maxInd]; 
        } 
  
        // Increment index of 
        // chosen elements 
        indx++; 
    } 
  
    int result = 0; 
    for (int i = 0; i < n; i++) 
        result ^= set[i]; 
    return result; 
} 
  
  
int main() 
{ 
    int set[] = {10, 8, 5}; 
    int n = sizeof(set) / sizeof(set[0]); 
      
    cout << "Maximum subset XOR is "; 
    cout << maxSubarrayXOR(set, n); 
    return 0; 
} 
