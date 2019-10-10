#include <bits/stdc++.h>
using namespace std;

//graph class
template<typename T>
class Graph{
	public:
	int v; //v is the number of vertices in graph
	map<T , list<T> > l; //l is the adjacency list for the graph	
	Graph(int v){
		this->v = v;
	}	
	//adding an edge to our graph
	//bidirectional tells whether the edge is directed or undirected
	//by default bidirectional = true
	void addEdge(T u , T v , bool bidirectional = true){
		l[u].push_back(v);
		if(bidirectional)	l[v].push_back(u);
	}	
	//printing the adjacency list
	void print(){ 
		//iterate over map
		for(auto it = l.begin() ; it != l.end() ; it++){
			cout << it->first << " : ";
			for(auto it2 = it->second.begin() ; it2 != it->second.end() ; it2++){
				cout << *it2 << " ";
			}
			cout << endl;
		}
	}
};

//dfs code
template <typename T>
void dfs(Graph<T> g , T source , unordered_map<T , bool> & visited , vector<T> & order){
	visited[source] = true;
	for(auto i : g.l[source]){
		if(visited[i] == false){
			dfs(g , i , visited , order);
		}
	}
	order.insert(order.begin() , source);
	return;
}
//code for finding topological sorting of a graph
template <typename T>
vector<T> topodfs(Graph<T> g){ //wrapper function
	unordered_map<T , bool> visited;
	vector<T> order;
	for(auto i : g.l){
		if(!visited[i.first]){
			dfs(g , i.first , visited , order);
		}
	}
	return order;
}

int main(){
	//creating a grapg object with 8 vertices
	Graph <int>sample(8);
	//adding edges (all are directed , i.e. bidirectional = false)
	sample.addEdge(1 , 2 , 0);
	sample.addEdge(1 , 5 , 0);
	sample.addEdge(2 , 3 , 0);
	sample.addEdge(2 , 6 , 0);
	sample.addEdge(3 , 4 , 0);	
	sample.addEdge(4 , 5 , 0);
	sample.addEdge(6 , 7 , 0);
	
	sample.print();//printing adjacency list of graph
	
	vector<int> order = topodfs(sample); //calling function to find topo. sort
	
	//printing topological sort
	for(int i = 0 ; i < order.size() ; i++){
		cout << order[i] << " ";
	}
	cout << endl;
}
