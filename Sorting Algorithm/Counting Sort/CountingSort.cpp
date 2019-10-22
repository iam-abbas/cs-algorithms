#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
int main(){
ios::sync_with_stdio(0);
//cin.tie(0);
int SIZE=10,MAX_SIZE=10000;
int arr[10]={5,2,3,1,9,10,10,2,9,19};
int count[MAX_SIZE]={0};
for(int i=0;i<SIZE;i++){
	count[arr[i]]++;
}
int j=0;
for(int i=0;i<MAX_SIZE;i++){
	if(count[i]!=0){
		while(count[i]!=0){
			arr[j++]=i;
			count[i]--;
		}
	}
}
for(int i=0;i<SIZE;i++){
	cout<<arr[i]<<" ";
}
}

