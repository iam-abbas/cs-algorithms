// Coding Binary Search Algorithm through Functions Topic Approach 
#include<iostream>
using namespace std ; 
//Function that implements the binary search algorithm
int BinarySearch(int arr[] ,int n , int val )
{
	int start=0 ; 
	int end=n-1 ;
	int mid ; 
	  

	while(start<=end)
	{
		mid=(start+end)/2 ;
		if(val==arr[mid])
		{
			return mid ; 
		}
		else if(val > arr[mid])
		{
			start=mid+1 ; 

		}
		else
		{
			end=mid-1 ; 
		}

	}
	return -1 ; 

}
//Driver code for the function
int main()
{
	int arr[50],n ;
	int result ;  
	cout << "Enter the no. of elements do u want to enter" ;
	cin >> n ; 

	cout << "Enter the elements that you want to insert in the Array " << endl ; 
	for(int i=0 ; i<n ; i++)
	{
		cin >> arr[i] ; 
	}

	cout << "Enter the element that you want to search for in the Array" << endl ; 
	int val ; 
	cin >> val ; 

	result= BinarySearch(arr,n,val) ; 
	cout << result << endl ; 

}
