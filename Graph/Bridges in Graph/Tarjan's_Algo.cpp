#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph{
    
    int v;
    unordered_map<int, list<int>> Adj;

public:
    Graph(int v){
        this -> v = v;
    }

    void AddEdges(int u, int v){
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    void PrintAdj(){
        for(int i=0; i<v; i++){
            cout<<i<<": ";
            for(auto j: Adj[i]){
                cout<< j << " ";
            }
            cout<<endl;
        }
    }

    void dfs(int node, int parent, int &time, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis){
        vis[node] = true;
        disc[node] = low[node] = time++;
        for(auto nbr: adj[node]){
            if(nbr == parent){
                continue;
            }
            if(!vis[nbr]){
                dfs(nbr, parent, time, disc, low. result, adj, vis);
                low[node] = min(low[node], low[nbr]);
                if(low[nbr] > disc[node]){
                    vector<int> and;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(as);
                }
            }else{
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }


};

int main(){

    Graph g(6);
    g.AddEdges(2, 0);
    g.AddEdges(2, 1);
    g.AddEdges(1, 0);
    g.AddEdges(4, 0);
    g.AddEdges(4, 3);
    g.AddEdges(4, 5);
    g.AddEdges(3, 5);
    g.printAdj();


}