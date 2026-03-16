#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

void makeset(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findeparent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }

    return parent[node] = findeparent(parent, parent[node]);
}

void unionset(int u, int v, vector<int> &parent, vector<int> &rank){
    int k = findeparent(parent, u);
    int l = findeparent(parent, v);
    if(rank[k] < rank[l]){
        parent[k] = l;
    }else if(rank[l] < rank[k]){
        parent[l] = k;
    }else{
        parent[l] = k;
        rank[k]++;
    }
}

int minimumspanningtree(vector<vector<int>> &edges, int n){
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent, rank, n);
    int minwight = 0;
    for(int i=0; i<edges.size(); i++){
        int u = findeparent(parent, edges[i][0]);
        int v = findeparent(parent, edges[i][1]);
        int wt = edges[i][2];
        if(u != v){
            minwight += wt;
            unionset(u, v, parent, rank); 
        }
    }
    return minwight;
}

int main(){
    vector<vector<int>> edges = { 
        {1,4,1},
        {1,2,2},
        {2,3,3},
        {2,4,3},
        {1,5,4},
        {4,3,5},
        {2,6,7},
        {3,6,8},
        {5,4,9}
    };
    cout<<minimumspanningtree(edges, 7);
}