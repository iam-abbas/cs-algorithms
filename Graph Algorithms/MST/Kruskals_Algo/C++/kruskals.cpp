#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

// edge class
class edge{
	public:
	int u , v , weight; // u and v are the end points of an edge
						// weight is the weight of the edge 
	edge(){}
	edge(int a , int b , int c){
		u = a , v = b , weight = c;
	}
};

bool compare(edge a , edge b){
	return a.weight < b.weight;
}

vector<edge> edges; //vector of all the edges of the graph
vector<edge> result; //vector that will contain the edges present in MST

//creating a DSU (DISJOINT SET UNION) - to find and detect cycles
int parent[100001] , ranks[100001];
void make_set(int v){
	parent[v] = v;
}
int find_set(int v){
	if(v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
bool check(int a , int b){
	a = find_set(a);
	b = find_set(b);
	if(a == b)	return false;
	
	if(ranks[a] < ranks[b])	swap(a , b);
	parent[b] = a;
	if(ranks[a] == ranks[b])	ranks[a]++;
	return true;
}

// function to find the MST that returns the overall weight os the MST
int calcMST(int n , int m){
	int weight = 0 , totaledges = 0;
	//sorting the edges as per their weights
	sort(edges.begin() , edges.end() , compare);
	//initializing dsu
	for(int i = 1 ; i <= n ; i++){
		make_set(i);
	}	
	//picking edges and checking
	for(auto i : edges){
		if(check(i.u , i.v)){
			result.pb(i);
			weight += i.weight;
			totaledges++;
			if(totaledges == n - 1)	break;
		}
	}
	return weight;			
}

int main(){
	//n - no. of vertices , m - no. of edges
	int n , m , u , v , weight;
	cin >> n >> m;
	//inputting m edges
	for(int i = 0 ; i < m ; i++){
		cin >> u >> v >> weight;
		edge temp(u , v , weight);
		edges.pb(temp);
	}
	int ans = calcMST(n , m);	
	cout << ans << endl;
	
	//printing all the edges present in result vector
	for(int i = 0 ; i < result.size() ; i++){
		cout << result[i].u << " " << result[i].v << " " << result[i].weight << endl;
 	}
}
