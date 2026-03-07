#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
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
            cout<< i <<": ";
            for(auto j: Adj[i]){
                cout<< j << " ";
            }
            cout<<endl;
        }
    }

    bool BFS(){
        queue<int> q;
        vector<bool> visited(v, false);
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto j: Adj[front]){
                if(!visited[j]){
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
        for(int i=0; i<v; i++){
            if(!visited[i]){
                return true;
            }
        }
        return false;
    }

    void FindBridge(){
        int Ans[v];
        for(int i=0; i<v; i++){
            for(auto j: Adj[i]){
                cout<<i<<endl;
                Adj[i].remove(j);
                Adj[j].remove(i);
                bool bridge = BFS();
                if(bridge == 1){
                    Ans[i] = j;
                }
                Adj[i].push_back(j);
                Adj[j].push_back(i);
            }
        }

        for(int i=0; i<v; i++){
           
            cout << "(" << i << "," << Ans[i] << ")" << endl;
        
        }
    }




};



int main(){

    Graph g(5);
    g.AddEdges(0, 1);
    g.AddEdges(0, 2);
    g.AddEdges(0, 3);
    g.AddEdges(4, 3);
    g.AddEdges(1, 2);
    g.PrintAdj();
    g.FindBridge();

}