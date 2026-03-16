#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph{
    int v;
    unordered_map<int, vector<int>> adj_list;

public:
    Graph(int v){
        this -> v = v;
        adj_list[v];
    }

    void addEdge(int u, int v, int direction){
        adj_list[u].push_back(v);
        if(!direction){
            adj_list[v].push_back(u);
        }
    }

    void printAdjList(){
        for(int i=0; i<v; i++){
            cout<< i <<": ";
            for(auto j: adj_list[i]){
                cout<< j << " ";
            }
            cout<<endl;
        }
    }


};


int main(){
    Graph p(5);
    p.addEdge(0, 1, 0);
    p.addEdge(0, 3, 0);
    p.addEdge(1, 2, 0);
    p.addEdge(2, 3, 0);
    p.addEdge(4, 3, 0);
    p.addEdge(4, 2, 0);
    p.addEdge(1, 3, 0);
    p.printAdjList();

}