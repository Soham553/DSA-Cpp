#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{

    int v;
    list<int> *l; 
public:

    Graph(int v){
        this->v = v;
        l = new list<int> [v];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList(){
        for(int i=0; i<v; i++){
            cout << i << " : ";
            for(int neigh : l[i]){
                cout << neigh << " ";
            }
            cout << endl;    
        }
    }

    void bfs(){
        queue<int> Q;
        vector<bool> vis(v, false);

        Q.push(0);
        vis[0] = true;

        while(Q.size() > 0){
            int u = Q.front();
            Q.pop();

            cout << u << " ";

            for(int v : l[u]){
                if(!vis[v]){
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }
};

int main() {

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.printAdjList();
    g.bfs();
}