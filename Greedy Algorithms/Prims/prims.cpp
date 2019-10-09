#include<iostream>
#include<queue>
#include<vector>
using namespace std;
using ii = pair<int, int>;
int main(){
    vector<bool> visited(1000,false);
    vector<ii> node[1000];
    priority_queue<ii, vector<ii>, greater<ii> > PQ;
    int total = 0;
    int start = 0;
    node[0].push_back(make_pair(4,1));
    node[0].push_back(make_pair(6,2));
    node[0].push_back(make_pair(5,3));
    node[1].push_back(make_pair(3,2));
    node[3].push_back(make_pair(7,4));
    PQ.push({0, start});
    while(!PQ.empty()){
        int d = PQ.top().first;
        int n = PQ.top().second;
        PQ.pop();
        if(visited[n]) continue;
        visited[n] = true;
        for(auto el : node[n]) {
            int v = vw.first;
        int w = vw.second;
        if (!visited[v] && w < dist[v]) { // ปรับ edge weight ให้น้อยลง
            dist[v] = w;
            Q.push({dist[v], v}) // ถ้าปรับได้ก็ยัดใส่ queue
        }
            PQ.push(el);
        }
        total += d;
    }
    cout << total;
}