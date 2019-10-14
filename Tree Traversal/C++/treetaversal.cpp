// C++ program for different tree traversals 
#include <bit/stdc++.h> 
using namespace std; 
  
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
    Node(int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 
  
/* Given a binary tree, print its nodes according to the 
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right subtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->data << " "; 
} 
  
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    cout << node->data << " "; 
  
    /* now recur on right child */
    printInorder(node->right); 
} 
  
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    cout << node->data << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->left);  
  
    /* now recur on right subtree */
    printPreorder(node->right); 
}  

/* Given a binary tree, print its nodes in Levelorder*/
void printLevelOrder(Node *root) 
{ 
    // Base Case 
    if (root == NULL)  return; 
  
    // Create an empty queue for level order tarversal 
    queue<Node *> q; 
  
    // Enqueue Root and initialize height 
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        // Print front of queue and remove it from queue 
        Node *node = q.front(); 
        cout << node->data << " "; 
        q.pop(); 
  
        /* Enqueue left child */
        if (node->left != NULL) 
            q.push(node->left); 
  
        /*Enqueue right child */
        if (node->right != NULL) 
            q.push(node->right); 
    } 
} 

/* Given a binary tree, print its nodes in Levelorder in spiral form*/
void printLevelOrderSpiral(Node *root) 
{ 
    // Base Case 
    if (root == NULL)  return; 
  
    // Create two empty stacks 
    stack<Node *> s1;
    stack<Node *> s2; 
    
    // Push Root in s1 
    s1.add(root);
    
    while (!s1.empty() || !s2.empty()) 
    { 
        //Print nodes of current level from s1 and push nodes of next level to s2
        while (!s1.empty()) { 
        Node *node = s1.top();
        s1.pop();
        cout << node->data << " ";
          
        //Node that is right is pushed before left
        if (temp->right) 
            s2.push(temp->right); 
        if (temp->left) 
            s2.push(temp->left);
          
        }
  
        //Print nodes of current level from s2 and push nodes of next level to s1
        while (!s2.empty()) { 
        Node *node = s2.top();
        s2.pop();
        cout << node->data << " ";
          
        //Node that is right is pushed before left
        if (temp->right) 
            s1.push(temp->right); 
        if (temp->left) 
            s1.push(temp->left);
          
        } 
    } 
} 


  
/* Driver program to test above functions*/
int main() 
{ 
    struct Node *root = new Node(1); 
    root->left             = new Node(2); 
    root->right         = new Node(3); 
    root->left->left     = new Node(4); 
    root->left->right = new Node(5);  
  
    cout << "\nPreorder traversal of binary tree is \n"; 
    printPreorder(root); 
  
    cout << "\nInorder traversal of binary tree is \n"; 
    printInorder(root);  
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    printPostorder(root); 
  
    cout << "Level Order traversal of binary tree is \n"; 
    printLevelOrder(root); 
  
    cout << "Level Order traversal in Spiral form of binary tree is \n";
    printLevelOrderSpiral(root); 

    return 0; 
} 
