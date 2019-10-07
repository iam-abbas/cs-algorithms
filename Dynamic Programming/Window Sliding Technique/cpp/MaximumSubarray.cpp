/*
Explanation 

Given an array of integers of size ‘n’. Our aim is to calculate the maximum sum of ‘k’ 
consecutive elements in the array.

--Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700
--Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
         k = 4 
Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23}
of size 4.
--Input  : arr[] = {2, 3}
         k = 3
Output : Invalid
There is no subarray of size 3 as size of whole
array is 2.
*/



#include <bits/stdc++.h> 
using namespace std; 
  
int maxSum(int a[], int n, int k) 
{ 
    if (n < k) { 
        cout << "Size of SubArray is greater than the Array"; 
        return -1; 
    }  
    int max_s = 0; 
    for (int i = 0; i < k; i++) 
        max_s += arr[i];     
    int w_sum = max_s; 
    for (int i = k; i < n; i++) { 
        w_sum += a[i] - a[i - k]; 
        max_s = max(max_s, w_sum); 
    }  
    return max_s; 
} 
int main() 
{ 
    int ar[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 }; 
    int k = 4; 
    int n = sizeof(ar) / sizeof(ar[0]); 
    cout << maxSum(ar, n, k); 
    return 0; 
} 