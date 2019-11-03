//This is BFS and DFS graph traversal in Java using both adjacency list and matrix

package graph;
import java.util.*;

//making a class node having fields data and the next node to which the current will be adjacent to
class node
{
	int data;
	node next;
	
	public node(int d)
	{
		data=d;
		next=null;
	}
};

class graphcreation
{
	node head[]=new node[20];; // an array to maintain head node for each adjacent node
	int adjmatrix[][]=new int[15][15];  //creating an adjacent matrix for all nodes 
	int n;
	int e;
	Scanner sc= new Scanner(System.in);
	
	//accepting the details into a matrix like strating vertex, ending vertex between an edge
	void create_graphmatrix()
	{
		int i,v,u,j;
		System.out.println("\n\t Enter the number of vertices: ");
		n=sc.nextInt();
		System.out.println("\n\t Enter the number of edges: ");
		e=sc.nextInt();
		head=null;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				adjmatrix[i][j]=0;
			}
		}
		
		for(i=0;i<e;i++)
		{
			System.out.println("\n\t Enter the vertices between which an edge exits: ");
			System.out.println("\n\t Enter the starting vertex: ");
			u=sc.nextInt();
			System.out.println("\n\t Enter the end vertex: ");
			v=sc.nextInt();
			adjmatrix[u][v]=1;
			adjmatrix[v][u]=1;
		}
		//displaying the adjacent matrix
		
		System.out.println("\n\t The adjacency matrix for the graph is: ");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				System.out.print("\t"+adjmatrix[i][j]);
			}
			System.out.println(" ");
		}
	}
    
		// function to add the adjacent node corresponding to the current node in the adjacency list and marking it as 1  
	void insert(int x,int t)
	{
		node y;
		int d,i = 0;
      
	         	y= new node(t);
				if(head[x]==null)
				{
					head[x]=y;
				}
				else
				{
					node p=head[x];
					while(p.next!=null)
					{
						p=p.next;
			     	}
					p.next=y;
			}	
		}
	
	//accepting the details into a linked list like strating vertex, ending vertex between an edge
	void create_graphlist()
	{
		int n;
		int e,i,s,t;
		System.out.println("\n\t Enter the number of vertices: ");
		n=sc.nextInt();
		System.out.println("\n\t Enter the number of edges: ");
		e=sc.nextInt();
		for(i=1;i<=e;i++)
		{
			System.out.println("\n\t Enter the vertices between which an edge exits: ");
			System.out.println("\n\t Enter the starting vertex: ");
			s=sc.nextInt();
			System.out.println("\n\t Enter the end vertex: ");
			t=sc.nextInt();
			insert(s,t);  //like if node 3 is adjacnet to node 7 then 7 is added to adjacency list of 3
			insert(t,s);  //vice-versa 3 is added to adjacency list of 7
		}
		
		//displaying adjacency list of each node
		for(i=1;i<=n;i++)
		{
			node ptr=head[i];
			System.out.print("\n\t Adjacency list of vertex "+i+": ");
			while(ptr!=null)
			{
				System.out.print(" \t "+ptr.data);
				ptr=ptr.next;
			}
			System.out.println(" \n ");
		}
	}
  
  //in BFS we add all the adjacent of the current nodes first and when no more adjacent left 
  //we repeat the process for the first adjacent node added
  // whilst in DFS we add only one of adjacent nodes and repeat the process for it
  
	public void BFS_matrix()
	{
		int i=1,j;
		int p;
		int visited[]=new int[15];
		Queue<Integer> q=new LinkedList<Integer>();
		//checking if the vertex has already been visited or not
		for(i=1;i<=n;i++)
		{
			visited[i]=0;
		}
		//adding the first vertex
		q.add(1);
		visited[1]=1; //marking it as visited and it becomes the source node
		while(q.isEmpty()==false)
		{
			p=q.remove(); //removing head/source node from the queue if no adjacent found
			System.out.print("\t "+p); //printing the head node
		for(i=1;i<=n;i++)
		{
			if(adjmatrix[p][i]==1 && visited[i]==0) 
			{
				q.add(i);  //adding adjacent node to the queue
				visited[i]=1;  //marking it as visited
			}
		}
	}
}
	public void BFS_list()
	{
		int i=1;
		node p;
		node ptr;
		int visited[]=new int[15]; 
		int flag=0;
		Queue<node> q=new LinkedList<node>();
		for(i=1;i<=n;i++)
		{
			visited[i]=0;
		}
		q.add(head[i]);
		System.out.print("\t "+i);
		visited[i]=1;
		ptr=head[i]; //marking it as visited and it becomes the source node
		//first vertex among all vertices
		while(q.isEmpty()==false)
		{
			
			while(ptr!=null)
			{
				if(visited[ptr.data]==0)
				{
				//adding adjacent node to the queue
				//marking it as visited
					q.add(ptr);
					System.out.print("\t "+ptr.data);	
					
					visited[ptr.data]=1;
					
				
				}
				ptr=ptr.next;
				
				
			}q.remove(); //if no more adjacent then remove current front node 
			ptr=q.peek();
			if(ptr!=null) 
			ptr=head[ptr.data]; //removed node becomes head node and repeat the process
			else
				break;
		}
	}
		
	public void DFS_list()
	{
		int i=1;
		node p;
		node ptr;
		int visited[]=new int[15]; 
		int flag=0;
		Stack<node> s=new Stack<node>();
		//checking if the vertex has already been visited or not
		for(i=1;i<=n;i++)
		{
			visited[i]=0;
		}
		s.push(head[i]);
		System.out.print("\t "+i);
		visited[i]=1;
		ptr=head[i];//first vertex among all vertices
		while(s.isEmpty()==false)
		{
			flag=0;
			while(ptr!=null)
			{
			//push any one of the adjacent nodes of current head node to the stack
				if(visited[ptr.data]==0) //if adjacent and not visited yet
				{
					s.push(ptr);
					System.out.print("\t "+ptr.data);
					visited[ptr.data]=1; //mark as visited
					flag=1;
					break;
				}
				ptr=ptr.next; 
				
			}
			if(flag==1)
			{
				ptr=head[ptr.data];  //repeat process for the node just inserted as it becomes the new head node
				                     // and check for any one of its adjacent nodes
			}
			else
			{
					s.pop(); //if no adjacent remove till current node has any adjacent whilst printing the removed nodes
				if(s.empty()==false)
				{
					ptr=s.firstElement();
				}
				
				
			}
		}
	}
	public void DFS_matrix()
	{
		int i=1,j;
		
		int visited[]=new int[15]; 
		int flag=0;
		Stack<Integer> s=new Stack<Integer>();
		//checking if the vertex has already been visited or not
		for(int p=1;p<=n;p++)
		{
			visited[p]=0;
		}
		s.push(i);
		System.out.print("\t "+i);
		visited[i]=1;
	
		while(s.isEmpty()==false)
		{
		
			flag=0;
			for(j=1;j<=n;j++)
			{
				
				if(visited[j]==0&&adjmatrix[i][j]==1)
				{
					s.push(j); //push any one of the adjacent nodes of current head node to the stack
					System.out.print("\t "+j);
					visited[j]=1;
					flag=1;
					break;
					
				}
			
				
			}
			if(flag==1)
			{
				i=j; //repeat process for the node just inserted as it becomes the new head node
				                     // and check for any one of its adjacent nodes
			}
			else
			{
				s.pop();   //if no adjacent remove till current node has any adjacent whilst printing the removed nodes
				if(s.empty()==false)
				{
					i=s.peek();
				}
				
				
			}
		
			}
	}
}

public class graph
{
	public static void main(String args[])
	{
		Scanner sc= new Scanner(System.in);
		graphcreation g1= new graphcreation();
		graphcreation g2=new graphcreation();
		graphcreation g3= new graphcreation();
		graphcreation g4=new graphcreation();
		
		int ch;
		do{
		System.out.println("\n\t MENU: ");
		System.out.print("\n\t 1.BFS list traversal \n\t 3.DFS list traversal \n\t 4.DFS matrix traversal \n\t 4.BFS matrix traversal ");
		System.out.println("\n\t Enter your choice: ");
		ch=sc.nextInt();
		
		switch(ch)
		{
		case 1:
			System.out.println("\n\t To create the adjacency matrix");
			g1.create_graphmatrix();
			System.out.println("\n\t The BFS traversal using adjacency matrix: ");
			g1.BFS();
			break;
			
		case 2:
			System.out.println("\n\t To create the adjacency list: ");
			g2.create_graphlist();
			
			System.out.println("\n\t The DFS traversal using adjacency list: ");
			g2.DFS_list();
			break;
		case 3:
			System.out.println("\n\t To create the adjacency matrix: ");
			g3.create_graphmatrix();
			
			System.out.println("\n\t The DFS traversal using adjancey matrix: ");
			g3.DFS_matrix();
			break;
		case 4:
			System.out.println("\n\t To create the adjacency list: ");
			g4.create_graphlist();
			System.out.println("\n\t The BFS traversal using adjacency list: ");
			g4.BFS_list();
			break;
		}		
	
	}while(ch<5);

}
}

/*
OUTPUT:

MENU: 

1.BFS traversal 
2.DFS list traversal
3.DFS matrix traversal 
Enter your choice: 
1

To create the adjacency matrix

Enter the number of vertices: 
8

Enter the number of edges: 
9

Enter the vertices between which an edge exits: 

Enter the starting vertex: 
1

Enter the end vertex: 
2

Enter the vertices between which an edge exits: 

Enter the starting vertex: 
2

Enter the end vertex: 
5

Enter the vertices between which an edge exits: 

Enter the starting vertex: 
1

Enter the end vertex: 
6

Enter the vertices between which an edge exits: 

Enter the starting vertex: 
6

Enter the end vertex: 
3

Enter the vertices between which an edge exits: 

Enter the starting vertex: 
3

Enter the end vertex: 
7

Enter the vertices between which an edge exits: 

Enter the starting vertex: 
6

Enter the end vertex: 
7

Enter the vertices between which an edge exits: 

Enter the starting vertex: 
3

Enter the end vertex: 
4

Enter the vertices between which an edge exits: 

Enter the starting vertex: 
4

Enter the end vertex: 
8

Enter the vertices between which an edge exits: 

Enter the starting vertex: 
7

Enter the end vertex: 
8

The adjacency matrix for the graph is: 
0	1	0	0	0	1	0	0 
1	0	0	0	1	0	0	0 
0	0	0	1	0	1	1	0 
0	0	1	0	0	0	0	1 
0	1	0	0	0	0	0	0 
1	0	1	0	0	0	1	0 
0	0	1	0	0	1	0	1 
0	0	0	1	0	0	1	0 

The BFS traversal using adjacency matrix: 
1	 2	 6	 5	 3	 7	 4	 8
MENU: 

1.BFS traversal 
2.DFS list traversal 
3.DFS matrix traversal
Enter your choice: 
2

 To create the adjacency list: 

	 Enter the number of vertices: 
8

	 Enter the number of edges: 
10

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
1

	 Enter the end vertex: 
2

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
2

	 Enter the end vertex: 
7

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
7

	 Enter the end vertex: 
1

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
7

	 Enter the end vertex: 
6

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
6

	 Enter the end vertex: 
5

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
5

	 Enter the end vertex: 
4

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
4

	 Enter the end vertex: 
3

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
3

	 Enter the end vertex: 
8

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
4

	 Enter the end vertex: 
8

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
6

	 Enter the end vertex: 
4

	 Adjacency list of vertex 1:  	 2 	 7 
 

	 Adjacency list of vertex 2:  	 1 	 7 
 

	 Adjacency list of vertex 3:  	 4 	 8 
 

	 Adjacency list of vertex 4:  	 5 	 3 	 8 	 6 
 

	 Adjacency list of vertex 5:  	 6 	 4 
 

	 Adjacency list of vertex 6:  	 7 	 5 	 4 
 

	 Adjacency list of vertex 7:  	 2 	 1 	 6 
 

	 Adjacency list of vertex 8:  	 3 	 4 
 

	 The DFS traversal using adjacency list: 
	 1	 2	 7	 6	 5	 4	 3	 8
	 MENU: 

	 1.BFS traversal 
	 2.DFS list traversal 
	 3.DFS matrix traversal
	 Enter your choice: 3
	 
	
	 To create the adjacency matrix: 

	 Enter the number of vertices: 
8

	 Enter the number of edges: 
10

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
1

	 Enter the end vertex: 
2

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
1

	 Enter the end vertex: 
3

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
1

	 Enter the end vertex: 
4

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
1

	 Enter the end vertex: 
5

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
2

	 Enter the end vertex: 
6

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
3

	 Enter the end vertex: 
6

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
6

	 Enter the end vertex: 
8

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
4

	 Enter the end vertex: 
7

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
5

	 Enter the end vertex: 
7

	 Enter the vertices between which an edge exits: 

	 Enter the starting vertex: 
7

	 Enter the end vertex: 
8

	 The adjacency matrix for the graph is: 
	0	1	1	1	1	0	0	0 
	1	0	0	0	0	1	0	0 
	1	0	0	0	0	1	0	0 
	1	0	0	0	0	0	1	0 
	1	0	0	0	0	0	1	0 
	0	1	1	0	0	0	0	1 
	0	0	0	1	1	0	0	1 
	0	0	0	0	0	1	1	0 

	 The DFS traversal using adjacency matrix: 
	 1	 2	 6	 3	 8	 7	 4	 5
	 MENU: 

	 1.BFS traversal 
	 2.DFS traversal 
	 Enter your choice: 


*/