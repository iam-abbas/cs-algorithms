#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int m,int r){
	//int n=r+1;
	int n1=m-l+1;
	int n2 = r-m;
	int a[n1],b[n2];
	//int i=1,j=1;
	for(int i=0;i<n1;i++){
		a[i] = arr[l+i];
	}
	for(int j=0;j<n2;j++){
		b[j]=arr[m+1+j];}
	
	int i = 0; // Initial index of first subarray 
    int j = 0; // Initial index of second subarray 
    int k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (a[i] <= b[j]) 
        { 
            arr[k] = a[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = b[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = a[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = b[j]; 
        j++; 
        k++; 
    } 
	
	
	}
	void mergesort(int arr[],int l,int r){
		if(l<r){
			int m = l+(r-l)/2;
			mergesort(arr,l,m);
			mergesort(arr,m+1,r);
			merge(arr,l,m,r);
		}
	}
	
	void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergesort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
