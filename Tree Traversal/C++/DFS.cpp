#include <iostream>
using namespace std;

bool adj_matrix[101][101]={0};
bool visited[101]={0};
int n;

void DFS(int s)
{
	visited[s]=1;
	cout<<s<<" ";
	for(int i=1;i<=n;i++)
		if(adj_matrix[s][i]==1 && !visited[i])
			DFS(i);
}

int main() 
{
	cout<<"Enter number of nodes: ";
	cin>>n;
	int m;
    cout<<"Enter number of edges: ";
	cin>>m;
	cout<<"Enter edges starting from source node:\n";
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj_matrix[x][y]=1;
		
	}
	int s;
	cout<<"Re-enter source node";
	cin>>s;
	cout<<"DFS with Source "<<s<<"\n";
	DFS(s);
	return 0;
}
