// Span Problem 
// Here we have to find span of every element in an array, i.e number of consecutive elements before that element (including that element also)
// having values less than or equal to value of current element
// Note: Span of every element will be atleast 1 


#include<iostream>
#include<stack>
using namespace std;

//function for span problem
void spans(int *a, int n, int *span){
    stack<int> s;  
    
    for(int i = 0; i<n; i++){
        while(!s.empty() && a[i]>=a[s.top()]){
            s.pop();
        }
        if(s.empty()){
            span[i] = i+1;
            s.push(i);
        }
        else{
            span[i] = i-s.top();
            s.push(i);
        }
   }
   
}

//testing our span function
int main(){
    int a[] = {9,12,5,13};
    int span[4];
    stack<int> s;
    spans(a,4,span);
    for(int i = 0 ; i<4; i++) cout<<span[i]<<endl;
    
}