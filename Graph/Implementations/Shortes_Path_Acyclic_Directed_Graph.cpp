#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <climits>
using namespace std;

class Graph{
    int v;
    unordered_map<int, list<pair<int, int>>> Adj;

public:
    Graph(int v){
        this -> v = v;
    }

    void AddEdge(int u, int v, int weigh){
        Adj[u].push_back({v, weigh});
    }

    void PrintAdj(){
        for(int i=0; i<v; i++){
            cout<< i << ": ";
            for(auto j: Adj[i]){
                cout<< '[' << j.first << ',' << j.second << ']'<< ' ';
            }
            cout<<endl;
        }
    }

    void DfsTraversla(int i, unordered_map<int, bool>& visited, stack<int>& tp){
        visited[i] = true;
        for(auto j: Adj[i]){
            if(!visited[j.first]){
                DfsTraversla(j.first, visited, tp);
            }
        }
        tp.push(i);
    }

    void ShortestPathInDAG(int src){
        unordered_map<int, bool> visited;
        stack<int> tp;

        for(int i=0; i<v; i++){
            if(!visited[i]){
                DfsTraversla(i, visited, tp);
            }
        }

        // while(!tp.empty()){
        //     cout<<tp.top()<< ' ';
        //     tp.pop();
        // }

        vector<int> dis(v, INT_MAX);
        dis[src] = 0;

        while(!tp.empty()){
            int top = tp.top();
            tp.pop();
            if(dis[top] != INT_MAX){
                for(auto j: Adj[top]){
                    int temp = dis[top] + j.second;
                    if(temp < dis[j.first]){
                        dis[j.first] = temp;
                    }
                }
            }
        }

        for(int i=0; i<v; i++){
            cout<<dis[i]<< ' ';
        }

    }

};


int main(){

    Graph g(6);
    g.AddEdge(0, 1, 5);
    g.AddEdge(0, 2, 3);
    g.AddEdge(1, 2, 2);
    g.AddEdge(1, 3, 6);
    g.AddEdge(2, 3, 7);
    g.AddEdge(2, 4, 4);
    g.AddEdge(2, 5, 2);
    g.AddEdge(3, 4, -1);
    g.AddEdge(4, 5, -2);
    g.PrintAdj();
    g.ShortestPathInDAG(1);

}