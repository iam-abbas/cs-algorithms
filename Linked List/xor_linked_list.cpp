//Doubly Linked List cost too much space because it stores previous and next address.
//So, XOR Linked List stores XOR of previous and next address and hence saves data.

#include <iostream>
#include <cstdint> // for including "uintptr_t" data structure.

using namespace std;

//Node is defined here and constructor is created.
class Node {
  public:
    int data;
    Node *link;

    Node(int info) {
      data = info;
      link = NULL;
    }
};

//function returns XOR of previous and next pointer.
Node* XOR(Node *a, Node *b) {
//uintptr_t stores XOR of address.
  return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

//function to create a node at beginning.
void push(Node **head, int data) {
  Node *temp = new Node(data);
  
  //link stores XOR of head address and NULL.
  temp->link = XOR(*head, NULL);

  if ((*head) != NULL) {
    //if head != NULL link stores XOR of prev and next node.
    (*head)->link = XOR(temp, XOR((*head)->link, NULL));
  }
  
  (*head) = temp;

}

void print(Node *head) {
  Node *curr = head;
  Node *prev = NULL;
  Node *next;

  while(curr != NULL) {
    cout << curr->data << " ";

    next = XOR(prev, curr->link);

    prev = curr;

    curr = next;
  }
}

int main() {
  Node *head;
  push(&head, 1);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
  push(&head, 5);
  push(&head, 6);
  print(head);
  
}
