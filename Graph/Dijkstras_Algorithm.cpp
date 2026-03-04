#include <iostream>
#include <set>
#include <unordered_map>
#include <climits>
#include <list>
#include <vector>
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
        // list<int, int> p1 = make_list(u, weigh);
        Adj[u].push_back(p);
        // Adj[v].insert(p1);
    }

    void PrintAdj(){
        for(int i=0; i<v; i++){
            cout<< i << ": ";
            for(auto j: Adj[i]){
                cout<< '['<< j.first << ","<<j.second<<']';
            }
            cout<<endl;
        }
    }

    void ShortestPathDjAlgo(int src){
        vector<int> dis(v, INT_MAX);
        set<pair<int, int>> st;
        
        dis[src] = 0;
        st.insert(make_pair(0, src));

        while(!st.empty()){
            auto top = *(st.begin());

            int nodeDistance =  top.first;
            int topNode = top.second;
            st.erase(st.begin());
            for(auto j: Adj[topNode]){
                if(nodeDistance+j.second < dis[j.first]){
                    auto record = st.find(make_pair(dis[j.first], j.first));
                    if(record != st.end()){
                        st.erase(record);
                    }
                    dis[j.first] = nodeDistance + j.second;
                    st.insert(make_pair(dis[j.first], j.first));
                }
            }

        }
        
        for(int i=0; i<v; i++){
                cout<< i<< "->"<<dis[i]<<endl;
        }

        
    }

};


int main(){

    Graph g(4);
    g.AddEdge(0, 1, 5);
    g.AddEdge(0, 2, 8);
    g.AddEdge(1, 0, 5);
    g.AddEdge(1, 3, 2);
    g.AddEdge(2, 0, 8);
    g.AddEdge(3, 1, 2);
    g.AddEdge(3, 2, 6);
    g.AddEdge(2, 3, 6);
    g.PrintAdj();
    g.ShortestPathDjAlgo(0);

}