#include <iostream>
#include <limits.h>
using namespace std;
#define black 0
#define grey 1
#define white 2
struct adjlistnode
{
	int data;
	struct adjlistnode *next;
};
struct adjlist
{
	struct adjlistnode *head;
};
struct graph
{
	int vertices;
	struct adjlist* array;
	int *color;
};
struct adjlistnode* c_node(int v)
{
	struct adjlistnode* node=new struct adjlistnode;
	node->data=v;
	node->next=NULL;
	return node;
}
struct graph* creategraph(int numv)
{
	struct graph* g= new graph;
	g->vertices=numv;
	g->array=new struct adjlist[(numv)*sizeof(adjlist)];
	g->color=new int[numv*sizeof(int)];
	for(int i=0;i<numv;i++)
	{
		g->array[i].head=NULL;
		g->color[i]=white;
	}
	return g;
}
void addedge(struct graph* g,int v1,int v2)
{
	 struct adjlistnode* temp=c_node(v1);
	 temp->next=g->array[v2].head;
	 g->array[v2].head=temp;
	 temp=c_node(v2);
	 temp->next=g->array[v1].head;
	 g->array[v1].head=temp;
}
void print(struct graph* g,int v)
{
	int i;
	for(i=1;i<=v;i++)
	{
		struct adjlistnode *q=(struct adjlistnode*)malloc(sizeof(struct adjlistnode));
		q=g->array[i].head;
		cout<<"for node"<<i<<endl;
		while(q)
		{
			cout<<q->data;
			q=q->next;
		}
		cout<<endl;
	}
}
struct stack
{
	int top;
	int len;
	int *array;
};
struct stack* createstack(int numv)
{
	struct stack* s=new struct stack;
	s->top=-1;
	s->len=numv;
	s->array = new int[numv*sizeof(int)]; 
	return s;
}
int isEmpty(struct stack* stack) //checks if the stack is empty
{ 
    return stack->top == -1; 
} 
int pop(struct stack* stack) //pops and removes the top element
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 
int peek(struct stack* stack) /* fucntion returns the top without removing it*/
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 
void push(struct stack* stack, int item) // pushes the item at the top
{ 
    stack->array[++stack->top] = item; 
} 
void dfs(struct graph* g,int startvertex,struct stack* s)
{
	push(s,startvertex);
	g->color[startvertex]=grey;
	while(!isEmpty(s))
	{
		int u=peek(s);
		struct adjlistnode* v=g->array[u].head;
		while(v)
		{
			if(g->color[v->data]==white)
				dfs(g,v->data,s);
			else if(g->color[v->data]==grey && v->data!=u)
			{
				pop(s);
				g->color[u]=black;
				cout<<"cycle detected"<<endl;
				return;
			}
			v=v->next;
		}
		pop(s);
	}
}
int main()
{
	struct graph* graph = creategraph(7);
	struct stack* s=createstack(7);
    addedge(graph, 1, 2);
    addedge(graph, 1, 5);
    addedge(graph, 2, 3);
    addedge(graph, 2, 6);
    addedge(graph, 3, 7);
    addedge(graph, 3, 4);
    addedge(graph, 5, 6);
    addedge(graph, 6, 7);
    print(graph,7);
 	dfs(graph, 1,s);

}