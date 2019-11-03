#include <iostream>
#include <list>

using namespace std;


class Graph{

private:
	int num_vertices;
    list<int> *adj;
public:
	Graph(int V);
	bool is_Elulerian();
	void DFS(int g,bool visited[]);
	bool connected();
	void add_edge(int x,int w);
	



  friend int minimum_cut(Graph g);

};

Graph::Graph(int V){

    this->num_vertices=V;
    this->adj=new list<int>[V];
}
void Graph::DFS(int g,bool visited[]){

       visited[g]=true;

       list<int>::iterator i;
       for (i=adj[g].begin();i!=adj[g].end();i++){
       	     if ( visited[*i] != true){
       	     	   DFS(*i,visited);
       	     }
       }

}
bool Graph::connected(){

    bool visited[num_vertices];
    for (int i=0;i<num_vertices;i++){
    	visited[i]=false;
    }
    int k=0;
    for (k=0;k<num_vertices;k++){
    	if (adj[k].size()!=0){
    		break;
    	}
    }
    DFS(k,visited);
     for (k=0;k<num_vertices;k++){
    	if (adj[k].size()!=0){
    		if (!visited[k]){
    			return false;
    		}
    	}
    }
    return true;
    

}
bool Graph::is_Elulerian(){


    if (!connected()){
    	return false;
    } 
     int odd=0;
     for(int i=0;i<num_vertices;i++){
     	if(adj[i].size() & 1){
     		odd++;
     	}
     }
     if (odd>2){

     	return false;
     }
     return true;



}

void Graph::add_edge(int x,int w){

   adj[x].push_back(w);
   adj[w].push_back(x);

}

int minimum_cut(Graph g){

list<int> j=g.adj[0];
j.unique();
int i=0;
list<int>::iterator km=g.adj[0].begin();
while(j.size()!=1){
    for ( list<int>::iterator l=g.adj[0].begin();l!=g.adj[0].end();l++){
             cout<<*l<<" ";
    }


    int k=*(km++);
    list<int>::iterator kl;
    for(kl=g.adj[k].begin();kl!=g.adj[k].end();kl++){
      g.adj[0].push_back(*kl);
    }
    g.adj[0].remove(k);
    g.adj[0].remove(0);
    j=g.adj[0];
    j.unique();
    i++;

}

return g.adj[0].size();

}

int main(){

// checking 
Graph g(3);
g.add_edge(0,1);
g.add_edge(0,2);
g.add_edge(1,2);
//minimum_cut function
cout<<minimum_cut(g);


}
