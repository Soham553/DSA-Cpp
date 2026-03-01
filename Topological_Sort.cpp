#include <iostream>
#include <stack>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class graph{

public: 
    int v;
    unordered_map<int, list<int>> Edges;

    graph(int v){
        this -> v = v;
    }

    void addEdge(int u, int v){
        Edges[u].push_back(v);
    }

    void printAdjList(){
        for(auto &i: Edges){
            cout<<i.first<< ": ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

    void DFSTraversal(int node, unordered_map<int, bool> &visited, stack<int> &s){
        visited[node] = true;
        for(auto i : Edges[node]){
            if(!visited[i]){
                DFSTraversal(i, visited, s);
            }
        }
        s.push(node);
    }
    

    void dfs(){
        unordered_map<int, bool> visited;
        stack<int> s;
        for(int i = 1; i < v; i++){
            if(!visited[i]){
                DFSTraversal(i, visited, s);
            }
        }

       while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }

    }

    void BfsTraversal(int i, queue<int> &Q, unordered_map<int, bool> &visited, vector<int> &indegree){
        for(int i=0; i<v; i++){
            if(indegree[i] == 0){
                Q.push(i);
            }
        }
        
        vector <int> ans;
        while(!Q.empty()){
            int front = Q.front();
            Q.pop();
            ans.push_back(front);
            for(auto i: Edges[front]){
                indegree[i]--;
                if(indegree[i] == 0){
                    Q.push(i);
                }
            }
        }

        for(int i=0;i<v; i++){
            cout<<"TOPLOGI SORT USING BFS"<<endl;
            cout<<ans[i]<<" ";
        }
        

    }



    void BFS(){

        vector<int> indegree;
        for(int i=0; i<v; i++){
            for(auto j: Edges[i]){
                indegree[j]++;
            }
        }

        queue<int> Q;
        unordered_map<int, bool> visited;
        for(int i=0; i<v; i++){
            if(!visited[i]){
                BfsTraversal(i, Q, visited, indegree);
            }
        }
    }


};


int main(){
    graph p(6);
    p.addEdge(1, 2);
    p.addEdge(1, 3);
    p.addEdge(3, 4);
    p.addEdge(2, 4);
    p.addEdge(5, 6);
    p.addEdge(4, 5);
    p.addEdge(4, 6);
    p.printAdjList();
    p.dfs();
    p.BFS();

}