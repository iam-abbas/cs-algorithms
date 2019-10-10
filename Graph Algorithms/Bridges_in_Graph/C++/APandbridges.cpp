//this code can be used to find Articulation points(APs) and bridges in a Graph
#include <bits/stdc++.h>
using namespace std;

int timee;// a variable to keep track of the time at which a particular vertex is encounterd
vector<int> graph[10001];//adjacency list for the graph (10000 is the max number of vertices.. you can change as per your needs)
bool visited[10001] , AP[10001];
//visited - bool array used in DFS to know whether the node is visited or not
//AP - bool array to tell whether ith vertex is a AP or NOT

int disc[10001] , low[10001] , parent[10001];
//disc - discovery time of a vertex
//low - exit time of a source
//parent - array to tell the parent of ith vertex

//function to find APs and Bridges
void printAP2(int source , vector<int> &Ap , vector<pair<int , int> > &bridges){
	visited[source] = true;
	disc[source] = timee++;
	low[source] = disc[source];
	int child = 0;
	for(auto i : graph[source]){
		if(!visited[i]){
			child++;
			parent[i] = source;
			printAP2(i , Ap , bridges);
			low[source] = min(low[i] , low[source]);
			
			if(parent[source] == source){
				if(child > 1)	Ap.push_back(source);
			}
			else{
				if(low[i] >= disc[source])	Ap.push_back(source); // IMP
			}
			
			if(low[i] > disc[source]){
				pair<int , int> temp;
				temp.first = source;
				temp.second = i;
				bridges.push_back(temp);
			}
		}
		else if(i != parent[source])	low[source] = min(low[source] , disc[i]);
	}
}

void printAP(int n , int source){
	vector<int> Ap;
	vector<pair<int , int> > bridges; //contains edges which are bridges
	parent[source] = source;
	printAP2(source , Ap , bridges);
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]){
			parent[i] = i;
			printAP2(i , Ap , bridges);
		}
	}
	//print number of APs and Bridges
	//printing the APS and Bridges
	sort(Ap.begin() , Ap.end());
	sort(bridges.begin() , bridges.end());
	cout << Ap.size() << endl;
	for(int i = 0 ; i < Ap.size() ; i++){
		cout << Ap[i] << " ";
	}
	cout << endl;
	
	cout << bridges.size() << endl;
	for(int i = 0 ; i < bridges.size() ; i++){
		cout << bridges[i].first << " " << bridges[i].second << endl;
	}
}

int main(){
	//n - no. of vertices , e - no. of edges
	int n , e , u , v;
	cin >> n >> e;
	//inputting e edges
	for(int i = 0 ; i < e ; i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	printAP(n , 0);	
}
