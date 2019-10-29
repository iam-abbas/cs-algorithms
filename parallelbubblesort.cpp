#include<bits/stdc++.h>
#include<omp.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
typedef long long ll;

void sbubble(int arr[],int n){
time_point<system_clock> start,end;
	start=system_clock::now();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
end=system_clock::now();
	duration<double> time=end-start;

	cout<<"Serial Bubble Sort time is: "<<time.count()*1000<<"\n";
}


void pbubble(int arr[],int n){

	omp_set_num_threads(2);
	int first=0;
	time_point<system_clock> start,end;
	start=system_clock::now();
	for(int i=0;i<n;i++){
	 first=i%2;
	#pragma omp parallel for default(none),shared(arr,first,n)
		for(int j=first;j<n;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	end=system_clock::now();
	duration<double> time=end-start;

	cout<<"Paralel Bubble Sort time is: "<<time.count()*1000<<"\n";
}

int main(){
	int n;
	cout<<"Enter the size of the random array to be generated\n";
	cin>>n;
	
	int *a=new int[n];
	int *b=new int[n];
	int in=0,in1=0;
	for(int i=n-1;i>=0;i--){
		a[in++]=i;
		b[in1++]=i;
	}
	
	

	sbubble(a,n);
	pbubble(b,n);
	
	return 0;
}
	
	
/* Execution:
	
	1. Open terminal
	2. g++ -std=c++14 -fopenmp parallelbubblesort.cpp
	3. ./a.out
	
	Enter the size of the random array to be generated
	20000
	Serial Bubble Sort time is: 2406.04 milliseconds
	Paralel Bubble Sort time is: 1529.21 milliseconds
	
*/
