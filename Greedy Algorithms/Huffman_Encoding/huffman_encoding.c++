#include <bits/stdc++.h>
using namespace std;

//leaf node contains character(data), intermediate nodes contains frequency
struct node
{
    struct node *l;
    struct node *r;
    char data; 
    int freq;
};

struct compare{
    bool operator()(struct node *n1,struct node *n2)
    {
         return n1->freq>n2->freq;
    }
};

void traverse(node *root,string str)
{
    if(!root)
    return ;
 
    if(root->data!='#'){
     cout<<str<<" ";
     return;}    

    //append 0 if traverse to left branch of the node otherwise append 1 
    
    // if(root->l)
    traverse(root->l,str+"0");
    //if(root->r)
    traverse(root->r,str+"1");
}
int main() {
	//code
	
	int t; //for number of test cases
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    priority_queue<node*,vector<node*>,compare> pq;//minheap;
	    
	    
	    int x;
	    for(int i=0;i<s.length();i++)
	    {
	        struct node *nn=(struct node *)malloc(sizeof(struct node));
	        cin>>x;
	        nn->freq=x;
	        nn->data=s[i];
	        nn->l=nn->r=NULL;
	        pq.push(nn);
	    }
	    
	   while(pq.size()!=1)
	    {
	        struct node *left=pq.top();
	        pq.pop();
	        
	        struct node *right=pq.top();
	        pq.pop();
	        
            node *heapNode=(node*)malloc(sizeof(node));
            heapNode->data='#'; //  '#'' acts as character in intermediate nodes 
            heapNode->freq=left->freq+right->freq;
            heapNode->l=left;
            heapNode->r=right;
            
            pq.push(heapNode);
	    }
	    
	    struct node *root=pq.top();
	        string ans="";
	        traverse(root,ans);
	        cout<<endl;
	        
	}
	return 0;
}