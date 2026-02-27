#include <iostream>
#include <list>
#include <vector>
#include <Queue>
#include <unordered_map>

using namespace std;

class graph{

public:
    int v;
    list<int> *l;

    graph(int v){
        this -> v = v;
        l = new list<int> [v];
    }

    void addEdge(int u, int v, bool direction){
        l[u].push_back(v);
        
        if(direction == 0){
            l[v].push_back(u);
        }
    }

    void printAdjList(){
        for(int i = 0; i < v; i++){
            cout<< i << " : ";
            for(int n : l[i]){
                cout<< n << " ";
            }
            cout<<endl;
        }
    }

      void depth(int node, vector<int> &ans, unordered_map<int, bool> &visited){
        ans.push_back(node);
        visited[node] = true;

        for(auto i : l[node] ){
            if(!visited[i]){
                depth(i, ans, visited);
            }
        }

    }

    void dfs(){
        vector<int> ans;
        unordered_map<int, bool> visited;
        for(int i=0; i < v; i++){
            if(!visited[i]){
                depth(i, ans, visited);
            }
        }
        for(int x : ans){
            cout << x << " ";
            cout << endl;
        }    
    }
};



int main(){

    graph p(5);
    p.addEdge(0, 1, 0);
    p.addEdge(0, 3, 0);
    p.addEdge(1, 2, 0);
    p.addEdge(2, 3, 0);
    p.addEdge(4, 3, 0);
    p.addEdge(4, 2, 0);
    p.addEdge(1, 3, 0);

    p.printAdjList();
    p.bfs();
    p.dfs();
    p.cycledetection();

}