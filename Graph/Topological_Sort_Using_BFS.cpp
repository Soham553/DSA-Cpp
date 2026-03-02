#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class Graph{
    int v;
    list<int> *l;

public:
    Graph(int v){
        this -> v = v;
        l = new list<int> [v];
    }

    void AddEdge(int u, int v){
        l[u].push_back(v);
    }

    void PrintAdjlist(){
        for(int i=0; i<v; i++){
            cout<< i << ": ";
            for(auto j: l[i]){
                cout<< j << " ";
            }
            cout<<endl;
        }
    }

    void BFS(){
        // unordered_map<int, bool> visited;
        queue<int> Q;
        vector<int> ans;
        vector<int> indegree(v, 0);
        for(int i=0; i<v;i++){
            cout<<i<<endl;
            for(auto j: l[i]){
                indegree[j]++;
            }
        }

        for(int i=0; i<v; i++){
            if(indegree[i]==0){
                Q.push(i);
            }
        }

        while(!Q.empty()){
            int front = Q.front();
            Q.pop();
            // visited[front] = true; Not need of visited here indegree prvents repetation
            ans.push_back(front);
            for(auto j: l[front]){
                indegree[j]--;
                if(indegree[j]==0){
                    Q.push(j);
                }
            }
        }

        for(auto i: ans){
            cout<<i<<" ";
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
    p.BFS();

}