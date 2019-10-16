#include<stdio.h>
#include<stdlib.h>

void insertfirst(void);
void insertlast(void);
void insertbtw(void);
void deletefirst(void);
void deletelast(void);
void deletebtw(void);
void search(int i);
int compare(char a[],char b[]);
void display(void);
struct info *newnode(void);
int count(void);

struct info
{
	char name[80];
	char roll[9];
	float cgpa;
	struct info *next;
};

struct info *head;

int main()
{
	head=NULL;
	printf("This program creates circular a linked list.\n\n");
	printf("------------------------------------------------------------\n");
	int i;
	while(1)
	{
		printf("Enter 1 for Insertion\nEnter 2 for Deletion\nEnter 3 for Search\nEnter 4 for Display\nEnter 5 for exit.\n\n");
		scanf("%d",&i);
		if(i==5)
		{
			return 0;
		}
		switch(i)
		{
			case 1:
				printf("Enter 1 for insertion at first node\nEnter 2 for insertion at last node\nEnter 3 for insertion in between node.\n\n");
				scanf("%d",&i);
				switch(i)
				{
					case 1:
						insertfirst();
						break;
					
					case 2:
						insertlast();
						break;
						
					case 3:
						insertbtw();
						break;
						
					default:
						printf("Error in input.\n");
						break;			
				}
				break;
			
			case 2:
				if(head==NULL)
				{
					printf("List Empty.\nNo deletion is possible.\n");
					break;
				}
				printf("Enter 1 for deletion at first node\nEnter 2 for deletion at last node\nEnter 3 for deletion in between node.\n\n");
				scanf("%d",&i);
				switch(i)
				{
					case 1:
						deletefirst();
						break;
					
					case 2:
						deletelast();
						break;
						
					case 3:
						deletebtw();
						break;
						
					default:
						printf("Error in input.\n");
						break;			
				}
				break;	
				
			case 3:
				if(head==NULL)
				{
					printf("List Empty.\nNo search is possible.\n");
					break;
				}
				printf("Enter 1 for search by name\nEnter 2 for search by roll number\nEnter 3 for search by cgpa.\n");
				scanf("%d",&i);
				if(i<1||i>3)
				{
					printf("Error in input.\n");
				}	
				else
				{
					search(i);
				}
				break;
				
			case 4:
				display();
				break;
				
			default:
				printf("Error in input.\n");
				break;		
		}
			printf("------------------------------------------------------------\n");
	}
	getch();
	return 0;
}

struct info *newnode(void)
{
	struct info *n=(struct info*)malloc(sizeof(struct info));
	printf("Enter Name.\n");
	gets(n->name);
	gets(n->name);
	printf("Enter Roll number.\n");
	gets(n->roll);
	printf("Enter cgpa.\n");
	scanf("%f",&n->cgpa);
	n->next=NULL;
	return n;
}

void insertfirst(void)
{
	struct info *temp,*temp1,*temp2;
	temp=newnode();
	if(head==NULL)
	{
		head=temp;
		temp->next=head;
		return;
	}
	temp1=head;
	temp2=head;
	while(temp1->next!=head)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;	
	head=temp;
	temp->next=temp2;
}

void insertlast(void)
{
	struct info *temp,*temp1;
	temp=newnode();
	if(head==NULL)
	{
		head=temp;
		head->next=head;
		return;
	}
	temp1=head;
	while(temp1->next!=head)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;
	temp->next=head;
}

void insertbtw(void)
{
	int i,j;
	struct info *temp,*temp1,*temp2;
	printf("Enter the position at which node is to be inserted.\n");
	scanf("%d",&i);
	if(i>count()+1)
	{
		printf("\nINVALID POSITION.\n");
		return;
	}
	temp=newnode();
	if(head==NULL)
	{
		if(i==1)
		{
			head=temp;
			head->next=head;
			return;
		}
	}
	if(i==1)
	{
		temp1=head;
		while(temp1->next!=head)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
		temp1=head;
		head=temp;
		head->next=temp1;
		return;
	}
	temp1=head;
	for(j=1;j<=i-2;j++)
	{
		temp1=temp1->next;
	}
	temp2=temp1->next;
	temp1->next=temp;
	temp->next=temp2;
}

void deletefirst(void)
{
	if(head==NULL)
	{
		printf("\nLIST EMPTY.\nNO DELETION IS POSSIBLE.\n");
		return;
	}
	struct info *temp,*temp1,*temp2;	
	temp=head->next;
	temp1=head;
	temp2=head;
	while(temp1->next!=head)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;
	head=temp;
	if(temp1->next==temp2)
	{
		head=NULL;
	}
	printf("\nThe entry deleted is -\n");
	printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp2->name,temp2->roll,temp2->cgpa);
	free(temp2);
}

void deletelast(void)
{
	if(head==NULL)
	{
		printf("\nLIST EMPTY.\nNO DELETION IS POSSIBLE.\n");
		return;
	}
	struct info *temp,*temp1;
	temp=head;
	if(temp->next==head)
	{
		head=NULL;
		printf("\nThe entry deleted is -\n");
	    printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
		free(temp);
		return;
	}
	while(temp->next->next!=head)
	{
		temp=temp->next;
	}
	temp1=temp->next;
	temp->next=head; 
	printf("\nThe entry deleted is -\n");
	printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp1->name,temp1->roll,temp1->cgpa);
	free(temp1);
}

void deletebtw(void)
{
	if(head==NULL)
	{
		printf("\nLIST EMPTY.\nNO DELETION IS POSSIBLE.\n");
		return;
	}
	struct info *temp,*temp1,*temp2;
	int i,j;
	printf("Enter the position at which the node is to be deleted.\n");
	scanf("%d",&i);
	if(i==1)
	{
		deletefirst();
		return;
	}
	if(i>count())
	{
		printf("\nINVALID POSITION.\n");
		return;
	}
	temp=head;
	for(j=1;j<=i-2;j++)
	{
		temp=temp->next;
	}
	temp1=temp->next;
	temp2=temp1->next;
	temp->next=temp2;
	printf("\nThe entry deleted is -\n");
	printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp1->name,temp1->roll,temp1->cgpa);
	free(temp1);
}

void search(int i)
{
	struct info *temp;
	float b;
	char a[20];
	temp=head;
	int j,k=0;
	switch(i)
	{
		case 1:
			printf("Enter Name to be searched.\n");
			scanf("%s",a);
			while(temp->next!=head)
			{
				k++;
				j=compare(a,temp->name);
				if(j==0)
				{
					printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
					printf("Found at position = %d\n",k);
					return;
				}
				temp=temp->next;
			}
			k++;
			j=compare(a,temp->name);
			if(j==0)
			{
				printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
				printf("Found at position = %d\n",k);
				return;
			}
			printf("\nGiven name not found.\n");
			break;
			
			case 2:
			printf("Enter ROLL NUMBER to be searched.\n");
			scanf("%s",a);
			while(temp->next!=head)
			{
				k++;
				j=compare(a,temp->roll);
				if(j==0)
				{
					printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
					printf("Found at position = %d\n",k);
					return;
				}
				temp=temp->next;
			}
			k++;
			j=compare(a,temp->roll);
			if(j==0)
			{
				printf("\nNAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
				printf("Found at position = %d\n",k);
				return;
			}
			printf("\nGiven roll number not found.\n");
			break;	
			
			case 3:
			printf("Enter CGPA to be searched.\n");
			scanf("%f",&b);
			while(temp->next!=head)
			{
				k++;
				if(b==temp->cgpa)
				{
					printf("NAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
					printf("Found at position = %d\n",k);
					return;
				}
				temp=temp->next;
			}
			k++;
			if(b==temp->cgpa)
			{
				printf("NAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n",temp->name,temp->roll,temp->cgpa);
				printf("Found at position = %d\n",k);
				return;
			}
			printf("\nGiven CGPA not found.\n");
			break;
	}
}

int compare(char a[],char b[])
{
	int i,m;
	for(i=0;(a[i]!='\0')&&(b[i]!='\0');i++)
	{
		m=a[i]-b[i];
		if(m!=0)
		{
			return m;
		}
	}
	if((a[i]=='\0')&&(b[i]=='\0'))
	{
		return 0;
	}
	else
	{
		m=a[i]-b[i];
		return m;
	}
}

void display(void)
{
	if(head==NULL)
	{
		printf("LIST EMPTY.\n");
		return;	
	}	
	struct info *temp=head;
	printf("The list is -\n");
	while(temp->next!=head)
	{
		printf("NAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n\n",temp->name,temp->roll,temp->cgpa);
        temp=temp->next;
	}
	printf("NAME       : %s\nROLL NUMBER: %s\nCGPA       : %.2f\n\n",temp->name,temp->roll,temp->cgpa);
} 

int count(void)
{
	if(head==NULL)
	{
		return 0;
	}
	struct info *temp;
	int i=0;
	temp=head;
	while(temp->next!=head)
	{
		i++;
		temp=temp->next;
	}
	i++;
	return i;
}
