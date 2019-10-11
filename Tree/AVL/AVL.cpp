/*AVL TREE INSERTION*/ 
#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	int height;
	Node* left;
	Node* right;
};

int height(Node* root){
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;
}

void preOrder(Node * root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
	return;
}

Node* createNewNode(int val){
	Node* newNode = new Node();
	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node * rotateRight(Node * root){
	Node * newroot = root->left;
	root->left = newroot->right;
	newroot->right = root;
	root->height = height(root);
	newroot->height = height(newroot);
	return newroot;
}

Node * rotateLeft(Node * root){
	Node* newroot = root->right;
	root->right = newroot->left;
	newroot->left = root;
	root->height = height(root);
	newroot->height = height(newroot);
	return newroot;
}

Node* insertAVL(Node* root, int val){
	if(root==NULL){
		root = createNewNode(val);
	}
	else if(val<root->data){
		root->left = insertAVL(root->left, val);
	}
	else if(val>root->data){
		root->right = insertAVL(root->right, val);
	}
	int balance = height(root->left) - height(root->right);
	if(balance>1){ //left height is greater
		if(height(root->left->left) >= height(root->left->right)){
			//LL imbalance
			root = rotateRight(root);
		}
		else{
			//LR imabalace
			root->left = rotateLeft(root->left);
			root = rotateRight(root);
		}
	}
	if(balance<-1){
		if(height(root->right->right) >= height(root->right->left)){
			//RR imbalance
			root = rotateLeft(root);
		}
		else{
			//RL imabalace
			root->right = rotateRight(root->right);
			root = rotateLeft(root);
		}
	}
	root->height = height(root);
	return root;
}

Node* createAVL(int arr[], int n, Node* root){
	for(int i=0;i<n;i++){
		root = insertAVL(root, arr[i]);
	}
	return root;
}

int main()
{
    int arr[] = {40,20,10,25,30,22,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = NULL;
    root = createAVL(arr,n,root);
    preOrder(root);
    cout<<endl;
    insertAVL(root,60);
    preOrder(root);
    cout<<endl;
    return 0;
}