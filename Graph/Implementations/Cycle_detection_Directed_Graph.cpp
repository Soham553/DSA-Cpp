#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Graph{
    int v;
    unordered_map<int, vector<int>> adj;

public:
    Graph(int v){
        this -> v = v;
        adj[v];
    }

    void AddEdge(int u, int v, bool direction){
        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }
    }

    void PrintAdjList(){
        for(int i=0; i<v; i++){
            cout << i << ": ";
            for(auto& j: adj[i]){
                cout<< j << " ";
            }
            cout << endl;
        }
    }

    bool CheckcycleDfs(int i, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsvisited){
        visited[i] = true;
        dfsvisited[i] = true;
        for(auto& j: adj[i]){
           if(!visited[j]){
             if(CheckcycleDfs(j, visited, dfsvisited))
                return true;
           }else if(dfsvisited[j]){
             return true;
           }
        }
        dfsvisited[i] = false;
        return false;

    }

    bool DFS(){
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsvisited;
        for(int i=0; i<v; i++){
            if(!visited[i]){
                bool Checkcycle = CheckcycleDfs(i, visited, dfsvisited);
                if(Checkcycle){
                    return true;
                }
            }
        }
        return false;
    }


};


int main(){

    Graph g(8);
    g.AddEdge(0, 1, 1);
    g.AddEdge(1, 2, 1);
    g.AddEdge(2, 6, 1);
    g.AddEdge(2, 7, 1);
    // g.AddEdge(7, 6, 1);
    g.AddEdge(1, 3, 1);
    g.AddEdge(3, 4, 1);
    // g.AddEdge(4, 5, 1);
    g.AddEdge(5, 3, 1);
    g.PrintAdjList();
    bool ans = g.DFS();
    cout << ans << endl;

}