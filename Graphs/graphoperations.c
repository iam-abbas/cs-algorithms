#include<iostream>
int a[50][50];
int v;
void createGraph()
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("Enter a[%d][%d] edge:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void insertEdge()
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
            if(i==v-1||j==v-1)
			{
				printf("Enter a[%d][%d] edge:",i,j);
				scanf("%d",&a[i][j]);
			}
		}
	}
}
void insertVertex()
{
	int i,j;
	v=v+1;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(i==v-1||j==v-1)
			{
				a[i][j]=0;
			}
		}
	}
}
void deleteEdge()
{
	int i,j,v1,v2;
	printf("Enter two vertices v1 and v2:");
	scanf("%d %d",&v1,&v2);
	a[v1][v2]=a[v2][v1]=0;
	printf("Edge Deleted\n");
}
void deleteVertex()
{
	int i,j,d;
	printf("Enter vertex to be deleted:");
	scanf("%d",&d);
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(i==d||j==d)
			{
				a[i][j]=0;
			}
		}
	}
	printf("Vertex Deleted\n");
}
void display()
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(a[i][j]!=0)
			{
				printf("The Edge from V%d to V%d is %d\n",i,j,a[i][j]);
			}
		}
	}
}
int main()
{
	int choice;
	printf("Enter no of vertices:");
	scanf("%d",&v);
	while(1) {
		printf("****MENU****\n1.CreateGraph \n2.Insert Vertex\n3.Insert Edge\n4.Delete vertex\n5.Delete Edge\n6.Display\n7.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice) {
			case 1: createGraph();
                    break;
			case 2: insertvertex();
                    printf("\nVertex Inserted\n");
				    break;
			case 3: insertedge();
				    break;
			case 4: deletevertex();
				    break;
			case 5: deleteedge();
				    break;
			case 6: display();
				    break;
			case 7: exit(0);
			default:printf("Invalid Selection.");
		}
	}
	return 0;
}
