#include <bits/stdc++.h> 
using namespace std; 
struct node 
{ 
	int data; 
	node* next; 
	node* prev; 
}; 
void push(node** head, int data) 
{ 
	node* new_node = new node(); 
	new_node->data = data; 
	new_node->next = (*head); 
	new_node->prev = NULL; 
	if ((*head) != NULL) 
		(*head)->prev = new_node; 
	(*head) = new_node; 
} 
void printList(node* head)  
{  
    while (head != NULL)  
    {  
        cout<<" "<<head->data<<" ";  
        head = head->next;  
    }  
  
}  
int main() 
{ 
	node* head = NULL; 
	push(&head, 1);  
	push(&head, 4); 
	cout << "DLL: "; 
	printList(head); 
	return 0; 
} 
// Output is 
// DLL:  4  1 