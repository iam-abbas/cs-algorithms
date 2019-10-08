 //Program to implement DFS using Adjacency Matrix
 #include<stdio.h>
 int visit[100];
 void creategraph();
 void dfs(int);
 int a[100][100],n;
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

  void dfs(int v)
  {
    int w;
    visit[v]=1;
    printf("%d ",v);
   
    for(w=1;w<=n;w++)
    {
      if((a[v][w]==1)&&(visit[w]==0))
         dfs(w);
    }
  }


  void creategraph()
  {
    int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((i==0)&&(j==0))
           break;
        a[i][j]=1;
     }
  }