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

int main(){

//checking purpose
Graph g(2);
g.add_edge(0,1);
//return 1 if it is ElulerianGraph(fully or semi) and 0 if it is not
cout<<g.is_Elulerian();


}
