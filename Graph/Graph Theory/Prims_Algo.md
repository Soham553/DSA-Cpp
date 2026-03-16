# Prim's algorithm:

    - Is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a weighted, undirected graph

    - It works by starting with an arbitrary vertex, then iteratively adding the cheapest edge that connects a vertex in the MST to a vertex outside the MST.

    - Key Aspects of Prim's Algorithm:
    
        1. Greedy Approach: It always chooses the smallest edge weight, aiming for a global minimum.

        2. Initialization: Start with any vertex, treating it as the initial MST.

        3. Iteration: From the current tree, find all edges connecting to unvisited vertices and select the one with the smallest weight.

        4. Completion: The process stops when all vertices are included in the MST.

        5. Complexity: Using a binary heap and adjacency list, the time complexity is 



# Steps to Implement Prim's Algorithm:

   1. Maintain two sets: Vertices already in the MST and vertices not yet included.
   
   2. Initialize: Create a Min-Priority Queue to store edges and a visited array (or boolean set) to track vertices in the MST.
   
   3. Start: Select an arbitrary starting node and mark it as visited.
   
   4. Loop: While there are unvisited vertices:

        i. Find the minimum weight edge that connects a vertex in the visited set to a vertex in the unvisited set.

       ii. Add this edge to the MST and the new vertex to the visited set.
   
   5. Result: The algorithm finishes when all vertices are added.


# Applications:
   
    1. Network Design: Creating minimum-cost, connected networks (e.g., telephone lines, electrical grids).

    2. Infrastructure: Optimizing road, cable, or pipeline connections.