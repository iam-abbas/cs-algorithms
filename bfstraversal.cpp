/*Given an undirected and connected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.*/

#include<iostream>
#include<queue>
using namespace std;


int main()
{
    int V, E;
    cin >> V >> E;

    queue<int> q;

    int** arr=new int*[V];
    for(int i=0;i<V;i++)
    {
        arr[i]=new int[V];
    }

    for(int i=0;i<E;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        arr[v1][v2]=1;
        arr[v2][v1]=1;
    }

    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }


    q.push(0);


     while(!q.empty())
    {
        int sv=q.front();
        if(visited[sv]==false)
        {
            cout<<sv<<" ";
            visited[sv]=true;



            for(int i=0;i<V;i++)
            {
                if(arr[sv][i]==1)
                {
                    q.push(i);
                }
            }
        }


        q.pop();

    }

    return 0;
}
