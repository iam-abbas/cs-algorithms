#include<bits/stdc++.h>

using namespace std;

/*
SELECTION SORT

LOGIC
We divide the array such that one part is sorted and the other part is unsorted

STEP 1: Select the smallest element in the unsorted array
STEP 2: Place in the sorted part

EXAMPLE

Given Array: 80 15 19 90 11 13 32

* Element * -> Denotes the smallest element

Sorted Part | Unsorted Part

 | 80 15 19 90 *11* 13 32
11| 80 15 19 90 *13* 32
11 13 | 80 *15* 19 90 32
11 13 15 | 80 *19* 90 32
11 13 15 19 | 80 90 *32*
11 13 15 19 32 | *80* 90 
11 13 15 19 32 80 | *90* 
11 13 15 19 32 80 90 | 
*/

void swap(int *a, int *b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}

void sort(int* arr, int n)  
{  
    int i, j;
    int minIndex = -1;  
  
    for (i = 0; i < n-1; i++)  
    {  
        minIndex = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[minIndex])  
            minIndex = j;  
  
        swap(&arr[minIndex], &arr[i]);  
    }  
}  

void printArray(int arr[], int size)  
{  
    for (int i=0 ; i < size ; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
} 

int main()
{
  
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  	int arr[] = {80, 15, 19, 90, 11, 13, 32};  
    int n = sizeof(arr)/sizeof(arr[0]); 

    sort(arr, n);  
    printArray(arr, n); 
	
}