#include <bits/stdc++.h>
using namespace std;

#define maxi 100000
#define pb push_back
#define mp make_pair

typedef pair<int , int> pii;
typedef pair<pii , int> tuple;

class compareweight{
	public:
	bool operator()(pii a , pii b){
		return a.second > b.second;
	}
};

bool spanning[maxi]; //a bool array to keep record of whether a vertex is already a part of spanning tree or not (to detect cycles)
vector<pii> graph[maxi];//stores neighbours and weights of all the edges of a graph in form of pairs

//function to find the total weight os MST 
int mst(int source){ 
	// source is the vertex from which we start calculating out MST acc. to Prim's algo
	int mincost = 0;
	priority_queue<pii , vector<pii> , compareweight > rec;
	rec.push(mp(source , 0));
	while(!rec.empty()){
		pii temp = rec.top();
		rec.pop();
		//checking for cycle(is already included in the tree)
		if(spanning[temp.first])	continue;
		
		mincost += temp.second;
		spanning[temp.first] = true;
		for(auto i : graph[temp.first]){
			if(!spanning[i.first])	rec.push(i);
		}
	}
	return mincost;
}

int main(){
	//n - no. of edges , e - no. of edges
	int n , e , u , v , w;
	cin >> n >> e;
	
	//inputting e edges
	for(int i = 0 ; i < e ; i++){
		cin >> u >> v >> w;
		graph[u].pb(mp(v , w));
		graph[v].pb(mp(u , w));
	}
	//finding MST
	int mincost = mst(1);
	cout << mincost << endl;
}

