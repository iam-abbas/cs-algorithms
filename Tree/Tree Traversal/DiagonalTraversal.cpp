#include <iostream>
#include <vector>

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

vector< vector< int > > diaTree;

void diagonalTraversalUtil (Node* root, int index) {
    if (root == NULL) {
        return;
    }

    if (index < diaTree.size()) {
        diaTree[index].push_back(root->value);
    } else {
        vector<int> temp = {root->value};

        diaTree.push_back(temp);
    }
    diagonalTraversalUtil (root->left, index+1);
    diagonalTraversalUtil (root->right, index);
}

void diagonalTraversal (Node* root) {

    diagonalTraversalUtil (root, 0);

    for (int i = 0; i < diaTree.size(); i++) {
        cout << "Diagonal " << i+1 << ": ";
        for (int j = 0; j < diaTree[i].size(); j++) {
            cout << diaTree[i][j] << " ";
        }
        cout << endl;
    }
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
                1
               / \
              /   \
             2     3
            / \    |
           /   \   |
          4     5 /
                 6
                /
               7
    */

    diagonalTraversal(root);

    return 0;
}
