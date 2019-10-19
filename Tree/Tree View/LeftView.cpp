#include <iostream>

using namespace std;

class Node {

public:
    int value;
    Node* left;
    Node* right;

    Node (int val) {
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int maxLevel;

void leftViewUtil(Node* root, int level) {
    // Check if new level reached is the highest
    if (maxLevel < level) {
        cout << root -> value << endl;
        maxLevel = level;
    }

    // Left side of the tree is traversed first so that
    // left nodes are checked first for the condition that
    // whether they have reached new max level or not.
    if (root -> left != NULL) {
        leftViewUtil(root -> left, level+1);
    }

    if (root -> right != NULL) {
        leftViewUtil(root -> right, level+1);
    }
}

void leftView(Node *root) {
   maxLevel = -1;

   leftViewUtil(root, 0);
}

int main () {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->left = new Node(7);


    /*
      ->        1
               / \
              /   \
             /     \
      ->    2       3
           / \     /
      ->  4   5   6
                 /
      ->        7
    */

    cout << "Left view of the tree: \n";
    leftView(root);

    return 0;
}
