#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

class Graph{
    int v;
    list<int>* l;

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

    void ShortestPath(int src, int distination){
        unordered_map<int, bool> visited;
        unordered_map<int, int> Parent;
        queue<int> q;
        q.push(src);
        Parent[src] = -1;
        visited[src] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto j: l[front]){
                if(!visited[j]){
                    q.push(j);
                    visited[j] = true;
                    Parent[j] = front;
                }
            }
        }

        vector <int> ans;
        int currentNode = distination;
        ans.push_back(currentNode);
        while(currentNode != src){
            currentNode = Parent[currentNode];
            ans.push_back(currentNode);
        }

        reverse(ans.begin(), ans.end());
        for(auto i: ans){
            cout<<i<< "--->";
        }

    }




};

int main(){


    Graph p(9);
    p.AddEdge(1, 2);
    p.AddEdge(2, 5);
    p.AddEdge(5, 8);
    p.AddEdge(8, 7);
    p.AddEdge(3, 8);
    p.AddEdge(1, 3);
    p.AddEdge(1, 4);
    p.AddEdge(4, 6);
    p.AddEdge(6, 7);
    p.PrintAdjlist();
    p.ShortestPath(1, 6);

}