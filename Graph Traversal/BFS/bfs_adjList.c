 //Program to implement BFS using Adjacency List
 #include<stdio.h>
 #include<stdlib.h>
 int visit[10];
 void creategraph();
  void insert(int ,int);
 void bfs(int);
 void qinsert(int);
  int qdelete();
  int qisempty();
 int n,f,r;
 int q[10];
 struct node
 {
 int data;
 struct node *next;
 };

 struct node *a[100];
 int main()
 {
   int i,v,k;
   f=r=-1;
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph();
   printf("Enter the source vertex..\n");
   scanf("%d",&v);

   printf("The vertices reachable from %d using BFS are..\n",v);
   bfs(v);
 
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
     }
  }

  void insert(int i, int j)
  {
    struct node *temp,*p;

    temp=(struct node*)malloc (sizeof(struct node));
    temp->data=j;
    temp->next=a[i];
    a[i]=temp;
  }

  void qinsert(int v)
  {
    r++;
    q[r]=v;
    if(f==-1)
      f=0;
   }

  int qdelete()
  {
    int w;
    w=q[f];
    if(f==r)
     f=r=-1;
    else
     f++;
    return w;
  }
 
  int qisempty()
  {
     if(f==-1)
       return 1;
     return 0;
  }

  void bfs(int v)
  {
    struct node *p;
    int x,w;
    visit[v]=1;
    printf("%d ",v);
    qinsert(v);

   
    while(!qisempty())
    {
      x=qdelete();
      for(p=a[x];p!=NULL;p=p->next)
      {
        w=p->data;
        if(visit[w]==0)
        {
            visit[w]=1;
            printf("%d ",w);
            qinsert(w);
        }
    }
  }

  }