 //Program to implement DFS using Adjacency List
 #include<stdio.h>
 #include<stdlib.h>
 struct node
 {
 int data;
 struct node *next;
 };
 int visit[10];
 void creategraph();
  void insert(int,int);
 void dfs(int);
 int n;
 struct node *a[100];
 int main()
 {
   int i,v,k;
   
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph();
   printf("Enter the source vertex..\n");
   scanf("%d",&v);

   printf("The vertices reachable from %d using DFS are..\n",v);
   dfs(v);
 
  }

  void creategraph()
  {
    int i,j;
    for(i=1;i<=n;i++)
     a[i]=NULL;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((i==0)&&(j==0))
           break;
        insert(i,j);
        //insert(j,i);//for undirected graph
     }
  }

  void insert(int i, int j)
  {
    struct node *temp;

    //create a node

   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=j;

   temp->next=a[i];
   a[i]=temp;
  }

  void dfs(int v)
  {
    struct node *p;
    int w;
    visit[v]=1;
    printf("%d ",v);
   
    for(p=a[v];p!=NULL;p=p->next)
    {
      w=p->data;
      if(visit[w]==0)//not visited
        dfs(w);
     }
   }