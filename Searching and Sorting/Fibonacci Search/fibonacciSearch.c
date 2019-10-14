#include <stdio.h>


/*
    Fibonacci Search
    Coded by ShubhankarKG

    Properties :
    1. Works with sorted arrays
    2. A Divide and Conquer ALgorithm
    3. Has Log n time complexity

*/

// Utility function that returns the minimum of two numbers
int min(int a, int b){
    if (a <= b) return a;
    else return b;
}


/*
    Main function :
    parameters :
    1. Integer Array where element is to be searched
    2. Integer Element that is to be searched.
    3. Length of Array (n)
    
    Find the fibonacci number just greater than n.
    Find the two preceding Fibonacci numbers.
    Scan all the elements in array as follows :
        a. Compare element with last element of range covered by fib2
        b. if x matches, return index.
        c. Else if x is less than the element, move the three Fibonacci variables two Fibonacci down, indicating elimination of
         approximately rear two-third of the remaining array.
        d. Else x is greater than the element, move the three Fibonacci variables one Fibonacci down. Reset offset to index. 
         Together these indicate elimination of approximately front one-third of the remaining array.

    Since there might be a single element remaining for comparison, check if fibMm1 is 1. If Yes, compare x with that remaining element. If match, return index.

*/
int fibonacciSearch(int arr[], int x, int n){
    int fib2 = 0;
    int fib1 = 1;
    int fibM = fib1 + fib2;

    while(fibM<n){
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib1 + fib2;
    }

    int offset = -1;

    while(fibM > 1){
        int i = min(offset + fib2 , n-1);

        if (arr[i]<x){
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        }

        else if (arr[i]>x){
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        }

        else return i;
    }

    if (fib1 && arr[offset+1] == x) return (offset+1);

    return -1;
}

/* Driver code to check search

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,11, 12,13};
    int n = sizeof(arr)/sizeof(arr[1]);
    int x = 6;
    printf("Element found at index %d", fibonacciSearch(arr,x,n));
    return 0;
}

*/