#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph{
    int v;
    vector<vector<int>> adj;

public:
    Graph(int v){
        this -> v = v;
        adj.resize(v);
    }

    void AddEdge(int u, int v, bool direction){
        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }
    }

    void PrintAdjList(){
        for(int i=0; i<v; i++){
            cout<< i << ": ";
            for(auto& j: adj[i]){
                cout<< j << " ";
            }
            cout<<endl;
        }
    }

    bool CycleDetection(int src){
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        queue<int> Q;
        Q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while(!Q.empty()){
            int front = Q.front();
            Q.pop();
            for(auto& j: adj[front]){
                if(visited[j]==true && parent[front] != j){
                    return true;
                }else if(!visited[j]){
                    Q.push(j);
                    visited[j] = 1;
                    parent[j] = front;
                }
            }
        }
        return false;

    }



};

int main(){

    int src = 0;
    Graph p(6);
    p.AddEdge(0, 1, 0);
    p.AddEdge(0, 3, 0);
    p.AddEdge(1, 4, 0);
    p.AddEdge(4, 5, 0);
    p.AddEdge(3, 4, 0);
    p.AddEdge(3, 2, 0);
    p.PrintAdjList();
    cout<< p.CycleDetection(src);


}