#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

	
typedef struct Node
{
	struct Node* next;
	int data;
}Node;


Node* create(int data)
{
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->data=data;
	temp->next=NULL;;
	return temp;
}
void insert_order(struct Node**l,int data)
{	Node *temp=create(data);
	Node *p=NULL;
	Node *q=NULL;
	if(*l==NULL)
		*l=temp;
	else 
	{p=*l;
		while(p!=NULL &&(data>(p->data)))
			{
				q=p;
				p=p->next;
			}
			if(q!=NULL)
			{
				q->next=temp;
				temp->next=p;
			}
			else if(q==NULL)
			{
				temp->next=p;
				*l=temp;
			}
			else
			{
				q->next=temp;
			} 	temp->next=NULL;
	}
}

void display(Node *p)
{
	if(p==NULL)
		printf("\nEmpty list\n");
	else
	{	
		Node *temp=p;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}

void insert_tail(struct Node**l,int data)
{	Node *temp=create(data);
	if(*l==NULL)
		*l=temp;
	else
	{
		Node *q=*l;
		while(q->next!=NULL)
			q=q->next;
		q->next=temp;
		temp->next=NULL;
	}
}

void merge(Node *first,Node *second,Node **final)
	{
		while((first!=NULL)&&(second!=NULL))
			{	if((first->data)<(second->data))
					{
						insert_tail(final,first->data);
						first=first->next;
					}
				else if((first->data)>(second->data))
					{
						insert_tail(final,second->data);
						second=second->next;
					}
			}
		if(first==NULL)
		{	while(second!=NULL)
			{insert_tail(final,second->data);
			second=second->next;
			}
		}
		else
		{
			while(first!=NULL)
			{insert_tail(final,first->data);
			first=first->next;
			}		
		}
	}


int main()
{
	Node* first, *second, *third;
		first=second=third=NULL;
	int choice=0;
	printf("\n1.Insert into lists\n2.Display\n3.Merge\n");
	do
		{
			printf("\nEnter choice:");
			scanf("%d",&choice);char ch='y';char ch2='Y';
			int ele;
			int opt=0;
			switch(choice)
			{
				case 1:while(ch=='y')
						{	printf("\nEnter element into list1:");
							scanf("%d",&ele);
							insert_order(&first,ele);
							printf("\nTo add to list 1,press y..");
							fflush(stdin);	
							ch=getchar();
							
						}
						while(ch2=='Y')	
						{	printf("\nEnter element into list 2:");
						 	scanf("%d",&ele);
							insert_order(&second,ele);
							printf("\nTo add to list 2,press Y..");
							fflush(stdin);	
							ch2=getchar();
						}
						break;
				
				case 2:	printf("\nFirst list is:"); 
						display(first);
						printf("\nSecond List is:");
						display(second);
						break;
				
				case 3:merge(first,second,&third);
					   printf("\nMerged list is:");
					   display(third);
						break;
				default:exit(0);
			}
		}while(choice);
	getch();
	return 0;
}
			
