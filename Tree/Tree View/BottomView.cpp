#include <iostream>
#include <deque>

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

deque <int> dq;
int low, high;

void bottomViewUtil (Node* root, int horDist) {
    if (root == NULL) {
        return;
    }

    if (!dq.empty() && horDist > high) {
        dq.push_back(root->value);
        high++;
    } else if (horDist < low) {
        dq.push_front(root->value);
        low--;
    } else {
        dq[horDist-low] = root->value;
    }
    bottomViewUtil (root->left, horDist-1);
    bottomViewUtil (root->right, horDist+1);
}

void bottomView (Node* root) {
    low = 0;
    high = -1;

    bottomViewUtil (root, 0);

    deque <int> :: iterator i;

    cout << "Bottom View: ";
    for (i = dq.begin(); i != dq.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
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
               /.\
              2 . 3
             /.\. |
            4 . 5 |
              . ./
              . 6
              ./
              7
    */

    bottomView(root);

    return 0;
}
