#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Graph{
    int v;
    unordered_map <int, vector<int>> Edges;

public: 
   
    Graph(int v){
        this->v = v;
        Edges[v];
    }

    void AddEdge(int u, int v){
        Edges[u].push_back(v);
    }

    void PrintAdjlist(){
        for(int i=0; i < v; i++){
            cout<< i << ": ";
            for(auto j: Edges[i]){
                cout<< j << " ";
            }
            cout<<endl;
        }
    }

    void DFSTraversal(int i, unordered_map<int, bool>& visited, stack<int>& s){
        visited[i] = true;
        for(auto j: Edges[i]){
            if(!visited[j]){
                DFSTraversal(j, visited, s);
            }
        }
         s.push(i);
    }

    void DFS(){
        unordered_map<int, bool> visited;
        stack<int> s;
        for(int i=0; i<v; i++){
            if(!visited[i]){
                DFSTraversal(i, visited, s);
            }
        }

        while(!s.empty()){
            cout<<s.top() + 1<<" ";
            s.pop();
        }

    }


};


int main(){

    Graph p(6);
    p.AddEdge(0, 1);
    p.AddEdge(0, 2);
    p.AddEdge(2, 3);
    p.AddEdge(1, 3);
    p.AddEdge(3, 4);
    p.AddEdge(4, 5);
    p.AddEdge(3, 5);
    p.PrintAdjlist();
    p.DFS();



}