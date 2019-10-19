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

void topViewUtil (Node* root, int horDist) {
    if (root == NULL) {
        return;
    }

    if (!dq.empty() && horDist > high) {
        dq.push_back(root->value);
        high++;
    } else if (horDist < low) {
        dq.push_front(root->value);
        low--;
    }
    topViewUtil (root->left, horDist-1);
    topViewUtil (root->right, horDist+1);
}

void topView (Node* root) {
    low = 0;
    high = 0;

    dq.push_back(root->value);
    topViewUtil (root, 0);

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
              / . \
             2  .  3
            /.\ .  |
           / . \.  |
          4  .  5  |
             .  . /
             .  ./
             .  6
             . /
             ./
             7
    */

    topView(root);

    return 0;
}
