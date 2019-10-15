#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

int height(BinaryTreeNode<int> *root);

bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
  if(root == NULL)
    return true;
  int hr = height(root->right);
  int hl = height (root->left);
  //bool flag = false;
  if(hl-hr == -1 || hl-hr ==1 || hr-hl == 0)
  {
      bool i = isBalanced(root->left);
      bool j = isBalanced(root->right);
       if(i==true && j == true) //&& flag  )
           return true;
  }
  else
      return false;


}
int height(BinaryTreeNode<int> *root) {

  if(root == NULL)
    return 0;
  int hl = height(root->left);
  int hr = height(root->right);
  if(hr>hl)
    return hr+1;
  else
    return hl+1;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    if(isBalanced(root))
    	cout << "true" << endl;
    else
	cout << "false" << endl;
}
