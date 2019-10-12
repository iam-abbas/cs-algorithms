//Coding Bubble Sort Algorithm 
#include<iostream>
using namespace std ; 

void BubbleSort(int arr[] , int n)
{
	

	for(int i=0 ; i<n-1 ; i++) // Iterating for (n-1) Rounds 
{

	for(int j=0 ; j<n-1-i ; j++)
	{
		if(arr[j]>arr[j+1])
		{
			int temp ; 
			temp=arr[j]; 		//perform swap
			arr[j]=arr[j+1];
			arr[j+1]=temp ; 
		}
		
	}
}

}

int main(){
	int n,arr[50] ; 
	cin >> n ; 

	for(int i=0 ; i<n ; i++)
	{
		cin >> arr[i]; 
	}

	BubbleSort(arr,n);

	for(int i=0 ; i<n ; i++)
	{
		cout << arr[i] << " " ; 
	}
}

