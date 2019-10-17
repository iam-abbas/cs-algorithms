#include <iostream>
using namespace std;

// creating struct Node

struct Node { 
   int data; 
   struct Node *prev; 
   struct Node *next; 
}; 
struct Node* head = NULL; 

//Inserting new node

void insert(int newdata) { 
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); 
   newnode->data  = newdata; 
   newnode->prev = NULL; 
   newnode->next = head;     
   if(head !=  NULL) 
      head->prev = newnode ;     
   head = newnode; 
}   
//display linked list

void display() { 
   struct Node* ptr;
   ptr = head;  
   while(ptr != NULL) { 
      cout<< ptr->data <<" "; 
      ptr = ptr->next; 
  } 
} 
int main() { 
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   cout<<"The doubly linked list is: ";
   display(); 
   return 0; 
} 
