#include<iostream>
using namespace std;

void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

void knapsack(int n,int m,int w[],float x[]){
	int u =m,i;
	for(i=0;i<n;i++){
		if(w[i]>u)
			break;
		else{
			x[i]=1;
			u -=w[i];
		}
	}
	if(i<=n){
		x[i] = ((u*1.0)/(w[i]*1.0));
	}
}

int main(){
	int n,m;
	cout<<"Enter the number of objects";
	cin>>n;
	int p[n],w[n];
	float r[n]={0.0};
	float x[n]={0.0};
	cout<<"Enter the profits of the objects";
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	cout<<"Enter the weights of the objects";
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		r[i]=(float)(p[i]/w[i]);
	}

	//sorting the profit by weight ratios using modified bubble sort
	for(int i=0;i<n-1;i++){
		int k=0;
		for(int j=0;j<n-i-1;j++){
			if(r[j]<r[j+1]){
				swap(r[j],r[j+1]);
				swap(p[j],p[j+1]);
				swap(w[j],w[j+1]);
				k++;
			}

		}

		if(k==0)
			break;
	}
	
	cout<<"Enter the size of the knapsack";
	cin>>m;
	knapsack(n,m,w,x);
	float profit = 0.0;
	for(int i=0;i<n;i++){
		profit += (p[i]*x[i]);	
	}
	cout<<"Maximum profit will be :"<<profit;
	return 0;
}