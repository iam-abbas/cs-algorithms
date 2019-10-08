'''Given an array of integers of size ‘n’.
Our aim is to calculate the maximum sum of ‘k’ 
consecutive elements in the array'''

import sys 
INT_MIN = -sys.maxsize -1
  
def maxSum(arr, n, k): 
 
    max_sum = INT_MIN ; 

    for i in range(n - k + 1): 
        current_sum = 0; 
        for j in range(k): 
            current_sum = current_sum + arr[i + j]; 

        max_sum = max(current_sum, max_sum ); 
  
    return max_sum; 
  

arr = [1, 4, 2, 10, 2,  
          3, 1, 0, 20]; 
k = 4; 
n = len(arr); 
print(maxSum(arr, n, k)); 
