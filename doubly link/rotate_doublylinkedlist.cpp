#include<bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  struct node*next,*prev;
};

struct node* update(struct node*start,int p);

int main()
{

        int n,p; // n is the number of nodes in the linked list , p is the number of nodes to be rotated starting from the head of linked list 
        cin>>n>>p;
        struct node*start=NULL,*cur=NULL,*ptr=NULL;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            ptr=new(struct node);
            ptr->data=a;
            ptr->next=NULL;
            ptr->prev=NULL;
            if(start==NULL)
            {
                start=ptr;
                cur=ptr;
            }
            else
            {
                cur->next=ptr;
                ptr->prev=cur;
                cur=ptr;
            }
        }
        struct node*str=update(start,p);
        while(str!=NULL)
        {
            cout<<str->data<<" ";
            str=str->next;
        }
        cout<<endl ;
}

struct node*update(struct node*start,int p)
{
    node* temp = start ;
    
    while(temp->next!=NULL)
    {
        temp = temp->next ;
    }
    node* s= start ;
    for(int i=0;i<p;i++)
    {
        node* t = s ;
       s = s->next ;
       temp->next = t ;
       t->prev = temp ; 
       temp=temp->next ;
       t->next = NULL ;
    }
    return s ;
}


