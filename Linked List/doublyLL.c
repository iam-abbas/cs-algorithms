#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int val;
	struct _node *prev,*next;
}node;

node *makenode(int);
void print(node *);
node *append(node *,node **,int);

void main()
{
	node *start='\0',*last='\0',*nd;
	int n;
	while(1)
	{
		printf("\nEnter an item : ");
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		start=append(start,&last,n);
	}
	print(start);

}

void print(node *ptr)
{
	if(ptr&&ptr->next)
	{
		while(ptr)
		{
			printf("%d ",ptr->val);
			ptr=ptr->next;
		}
		printf("\n");
	}
	else
	{
		while(ptr)
		{
			printf("%d ",ptr->val);
			ptr=ptr->prev;
		}
		printf("\n");
	}
}

node *makenode(int n)
{
	node *nd;
	nd=(node *)malloc(sizeof(node));
	nd->val=n;
	nd->prev=nd->next='\0';
	return nd;
}
node *append(node *start,node **last,int n)
{
	node *nd,*ptr;
	ptr=start;
	if(ptr=='\0')
	{
		nd=makenode(n);
		start=nd;
		*last=nd;
	}
	else
	{
		while(ptr!=*last)
		{
			ptr=ptr->next;
		}
		nd=makenode(n);
		ptr->next=nd;
		nd->prev=ptr;
		*last=nd;
	}
	return start;
}