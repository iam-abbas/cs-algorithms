
#include <bits/stdc++.h> 
using namespace std; 
  
class Node { 
public: 
    int data; 
    Node* next; 
}; 
  
void push(Node** head_ref, int new_data) 
{ 
    Node* new_node = new Node(); 
  
    new_node->data = new_data; 
  
    new_node->next = (*head_ref); 
  
    (*head_ref) = new_node; 
} 
  
int detectloop(Node* list) 
{ 
    Node *slow = list, *fast = list; 
  
    while (slow && fast && fast->next) { 
        slow = slow->next; 
        fast = fast->next->next; 
        if (slow == fast) { 
            cout << "Loop Exists"; 
            return 1; 
        } 
    } 
    return 0; 
} 
  
int main() 
{ 
    Node* head = NULL; 
  
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 10); 
  
    head->next->next->next->next = head; 
    detectloop(head); 
  
    return 0; 
}
