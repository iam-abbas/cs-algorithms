#include <iostream>
using namespace std;
struct node { 
   int data; 
   node *next; 
}; 
struct node* head = NULL; 
void insert(int data) 
{ 
   node *new_node = new node(); 
   node *ptr = head;  
   new_node->data = data; 
   new_node->next = head; 
   if (head!= NULL) 
   { 
      while (ptr->next != head) 
         ptr = ptr->next; 
      ptr->next = new_node; 
   } 
   else
      new_node->next = new_node;   
    head = new_node; 
}  
void display() { 
   node* ptr;
   ptr = head;
   do { 
      cout<<ptr->data <<" "; 
      ptr = ptr->next; 
   } while(ptr != head);
}   
int main() { 
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);  
   cout<<"The circular linked list is: ";
   display(); 
   return 0; 
   
    // The output is:
    //The circular linked list is: 9 2 7 1 3 
} 