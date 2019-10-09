#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int INF = 1000000;
using ii = pair<int, int>;
int main(){
    vector<ii> node[10000];
    vector<int> dis(10000,INF);
    vector<bool> visited(10000,false);
    priority_queue<ii, vector<ii>, greater<ii> > PQ;
    node[0].push_back({10,2});
    node[0].push_back({2,3});
    node[3].push_back({3,2});
    node[1].push_back({10,4});
    int start = 0; int final = 2; dis[start] = 0;
    PQ.push({dis[start], start});
    while(!PQ.empty()){
        int d = PQ.top().first;
        int n = PQ.top().second;
        PQ.pop();
        if(visited[n]) continue;
        visited[n] = true;
        if(n == final) {
            cout << dis[n];
            break;
        }
        for(auto el : node[n]) {
            int u = el.first;
            int v = el.second;
            if(!visited[v] && dis[n] + u < dis[v]){
                dis[v] = dis[n] + u;
                PQ.push({dis[v], v});
            }
        }
    }
}
