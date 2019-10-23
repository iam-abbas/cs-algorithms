/*
Input : str[] = "acb"
Output : Rank = 2

Input : str[] = "string"
Output : Rank = 598

Input : str[] = "cba"
Output : Rank = 6
*/

// C++ program to find lexicographic rank 
// of a string 
#include <bits/stdc++.h> 
#include <string.h> 
  
using namespace std; 
// A utility function to find factorial of n 
int fact(int n) 
{ 
    return (n <= 1) ? 1 : n * fact(n - 1); 
} 
  
// A utility function to count smaller characters on right 
// of arr[low] 
int findSmallerInRight(char* str, int low, int high) 
{ 
    int countRight = 0, i; 
  
    for (i = low + 1; i <= high; ++i) 
        if (str[i] < str[low]) 
            ++countRight; 
  
    return countRight; 
} 
  
// A function to find rank of a string in all permutations 
// of characters 
int findRank(char* str) 
{ 
    int len = strlen(str); 
    int mul = fact(len); 
    int rank = 1; 
    int countRight; 
  
    int i; 
    for (i = 0; i < len; ++i) { 
        mul /= len - i; 
  
        // count number of chars smaller than str[i] 
        // fron str[i+1] to str[len-1] 
        countRight = findSmallerInRight(str, i, len - 1); 
  
        rank += countRight * mul; 
    } 
  
    return rank; 
} 
  
// Driver program to test above function 
int main() 
{ 
    char str[] = "string"; 
    cout << findRank(str); 
    return 0; 
} 
  
// This code is contributed by Subrat Kumar Swain