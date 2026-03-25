#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Edge {

public:
    int v;
    int wt;

    Edge(int v, int wt){
        this -> v = v;
        this -> wt = wt;
    }
};

void dijk(int src, vector<vector<Edge>> g, int v){
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    pq.push({0, src});

    while(pq.size() > 0){
        int u = pq.top().second;
        pq.pop();

        for(Edge e : g[u]) {
            if(dist[e.v] > dist[u] + e.wt) {
                dist[e.v] = dist[u] + e.wt;
                pq.push({dist[e.v], e.v});
            }
        }
    }

    for(int i=0; i<v; i++) {
        cout<< dist[i] << " ";
    }
    cout<< endl;
}


int main(){

    int v = 6;
    vector<vector<Edge>> g(v);

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));

    g[2].push_back(Edge(4, 3));

    g[3].push_back(Edge(5, 1));


    g[4].push_back(Edge(3, 2));
    g[4].push_back(Edge(5, 5));

    for(int i=0; i<g.size(); i++){
        cout<< i << "-> ";
        for(auto j: g[i]){
            cout<<"["<<j.v<<","<<j.wt<<"]";
        }
        cout<<endl;
    }

    dijk(0, g, v);

    return 0;
    
}