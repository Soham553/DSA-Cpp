GRAPH

What is a Graph?
A graph is a data structure that stores data. The part that stores data is called the Node in a graph. The connection between two nodes is called an Edge.
Eg.

 Node Node with Edge

Note: It is just a visual representation inside computer memory; it is completely different.
Use Case Of GRAPH:
Graphs are fundamentally used in digital mapping and navigation systems (like Google Maps) to model road networks, where intersections are nodes (vertices) and roads are edges.
These graph data structures enable algorithms to calculate the fastest, shortest, or most efficient routes by analysing, in real-time, traffic, road closures, and distance
Types Of GRAPH:

1. Cyclic Undirected Graph
2. Non-Cyclic Undirected Graph
3. Cyclic Directed Graph
4. Non-Cyclic Directed Graph

CYCLIC UNDIRECTED GRAPH:
A graph that has a cyclic loop and undirected edges is called a Cyclic Undirected Graph.

In the above figure, there is a cycle, and the edges are undirected
Non-Cyclic Undirected Graph:
A graph that does not have a cyclic loop and directed edges is called a Non-Cyclic directed Graph.

 

No cyclic loop, and edges are undirected.
Cyclic Directed Graph:
A graph that have cyclic loop and directed edges is called a Cyclic Directed Graph.

Non-Cyclic Directed Graph:
A graph that does not have a cyclic loop and has directed edges is called a Non-Cyclic Directed Graph.

Implementation Of Graph In Cpp:

Implementation Of Graph In Cpp:

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{

    int v;
    list<int> *l; // int arr* dynamic array

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

Understand Code Line By line Or block wise:
class Graph{
    int v;
    list<int> *l; // int arr* dynamic array

public:
Graph(int v){
this->v = v;
l = new list<int> [v];
}

1.  Class Graph{}:
    STL(Standard Template Library) have vector, list, and many more like that we are
    Creating our own data structure called Graph.

2.  Int v: declaring a data member to store the number of nodes

3.  List<int> \*l: Creating a l pointer that points on list of objects each list, which contains a doubly linked list.
    l -------> [list] [list] [list]
    [list] ------> |prev pointer| Data field | next pointer |

4.  Public: it is a specific reference to understand learn polymorphism concept

5.  Graph(int v){}: A constructor that creates an object of a list of v indices in heap memory.

        void addEdge(int u, int v, bool directed){
            l[u].push_back(v);
            if(!directed){
        l[v].push_back(u);
        }

    Void addEdge(int u, int v){}: it is a method to add edges inside the list.

Let’s take an example :
U = 4 and v = 0
Have to add edge between 0 and 4
We will call the addEdge(0, 4) using object from main()
For a directed graph, we have to add one condition while calling; we have to pass true if it is directed, if not, pass false as an argument.

Final view:
l[0] ---> |prev|4|next| --> |prev||5|next|
l[4] ---> |prev|0|next| --> |prev|8|next| ……… and so on

void printAdjList(){

for(int i=0; i<v; i++){
cout << i << " : ";
for(int neigh : l[i]){
cout << neigh << " ";
}
cout << endl;  
 }
}

- We are traversing through the list and printing the neighbour node of all the nodes.
- For 0 => 0: 4, 5… and so on.

BFS(Breadth First Search): It is a traversing method for a graph in which all child nodes of the parent node visited

Let us consider 0 is the source node, so it will become our current parent node, push 0 into the queue
No, mark visited 0=> true(visited) and popped the 0. Push the child nodes of zero into the queue 1, 2, 4
Now pop 1 from the queue and add a child to
