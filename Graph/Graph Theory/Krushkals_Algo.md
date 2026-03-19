# Krushkal's Minimum Spanning Tree Algorithm

   - Kruskal's algorithm is a popular, greedy graph algorithm used to find the Minimum Spanning Tree (MST) of a connected, weighted undirected graph

   - It works by sorting all edges by weight and adding them one by one to the MST if they do not create a cycle, using a Union-Find data structure. 

# Key Aspects Of Krushkal's Algorithm

   1. Goal: Finds a subset of edges that connects all vertices together without cycles and with the minimum total edge weight.

   2. Mechanism: Sorts all edges from lowest to highest weight and iterates through them.

   3. Cycle Prevention: It uses the Disjoint Set Union (DSU) or Union-Find data structure to efficiently check if adding an edge forms a cycle.

   4. Complexity: The time complexity is dominated by sorting the edges, resulting in O(E log E) or O(E log V) time, where E is the number of edges and v is the number of vertices.


# Steps Of Krushkal's Algorithm

   1. Sort: Sort all graph edges in non-decreasing order of their weight.

   2. Initialize: Create a forest (a set of trees) where each vertex is   initially a separate, isolated node.

   3. Iterate: For each sorted edge:

        1. If the edge connects two different trees (i.e., does not form a cycle), add it to the spanning tree.

        2. If the vertices are already connected, discard the edge.

   4. Terminate: Stop when all vertices are connected, resulting in a single tree, or all edges have been processed. 


# Example
  

    For a graph with 3 nodes—A, B, and C—and edges A-B (weight 1), B-C (weight 5), and A-C (weight 3):

        1. Sort edges: A-B (1), A-C (3), B-C (5).
        2. Add A-B (1).
        3. Add A-C (3).
        4. Skip B-C (5) because C is already connected to B through A (forms a cycle).
        5. MST consists of edges A-B and A-C with a total weight of 1 + 3 = 4.


# Application
  
    - Network Design: Laying cables, designing telecommunication, or building water pipe networks, where the goal is to connect all nodes with minimal cost.
      Cluster Analysis: Finding clusters in data.

    - Approximation Algorithm: Used to solve the Traveling Salesperson Problem. 
