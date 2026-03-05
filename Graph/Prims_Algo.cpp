#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
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
        pair<int, int> p = make_pair(v, weigh);
        Adj[u].push_back(p);
         pair<int, int> p2 = make_pair(u, weigh);
        Adj[v].push_back(p2);
    }

    void PrintAdj(){
        for(int i=0; i<v; i++){
            cout<< i << ": ";
            for(auto j: Adj[i]){
                cout<< "["<<j.first<<","<< j.second<<"]"<<" ";
            }
            cout<<endl;
        }
    }

    void PrimsAlgo(int src){
        vector<bool> MST(v, false);
        vector<int> Parent(v);
        vector<int> key(v, INT_MAX);

        key[src] = 0;
        Parent[src] = -1;

        for(int i=0; i<v; i++){
            int min = INT_MAX;
            int u;
            for(int i=0; i<v; i++){
                if(key[i] < min && MST[i] == false){
                    u = i;
                    min = key[i];
                }
            }
            MST[u] = true;

            for(auto j: Adj[u]){
                int v = j.first;
                int w = j.second;
                if(MST[v] == false && w < key[v]){
                    Parent[v] = u;
                    key[v] = w;
                }
            }
        }

         for(int k=0; k<v; k++){
            cout<<Parent[k]<< "--> "<<k<<":"<<key[k]<<endl;
        }
    }

};


int main(){

    Graph g(9);
    g.AddEdge(0, 1, 4);
    g.AddEdge(0, 7, 8);
    g.AddEdge(7, 6, 1);
    g.AddEdge(4, 5, 10);
    g.AddEdge(5, 6, 2);
    g.AddEdge(3, 4, 9);
    g.AddEdge(3, 2, 7);
    g.AddEdge(1, 2, 8);
    g.AddEdge(2, 8, 2);
    g.AddEdge(8, 6, 6);
    g.AddEdge(7, 8, 7);
    g.AddEdge(7, 1, 11);
    g.AddEdge(2, 5, 4);
    g.AddEdge(3, 5, 14);
    g.PrintAdj();
    g.PrimsAlgo(0);









  

}