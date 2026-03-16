# Dijkstras Algorithm

   - It is a greedy algorithm that finds the shortest path from a single source node to all other nodes in a weighted graph with non-negative edge weights.

   - It maintains a set of visited nodes and a priority queue to iteratively select the unvisited node with the smallest tentative distance, updating neighbors' distances (relaxation) until all nodes are processed, typically in time.


# Key Aspects of Dijkstra's Algorithm

    1. Purpose: Solves the single-source shortest path problem for graphs with non-negative edge weights.

    2. Mechanism: Uses a greedy approach, always choosing the closest unvisited node to explore next.

    3. Data Structures: A priority queue (min-heap) is used to efficiently pick the minimum distance vertex.

    4. Complexity: With a binary heap priority queue, the time complexity is 

    5. Limitations: It does not work with negative edge weights, which can cause it to produce incorrect results.

# Step-by-Step Execution

    1. Initialize: Set the distance to the source node to 0 and all other nodes to infinity.

    2. Queue: Add the source node to a priority queue.
    Explore: While the queue is not empty, extract the node with the smallest distance.

    3. Relax: For each neighbor v of u, calculate the distance through u. If this distance is smaller than the current known distance to v update v's distance and add it to the queue.

    4. Finish: Mark u as visited; a visited node's shortest distance is finalized.

# Application:
   
    - Network Routing: Finding the fastest path for data packets, such as in OSPF (Open Shortest Path First).

    - Mapping Applications: Computing driving directions between locations in GPS systems.

    - Geography: Solving problems in geographic information systems
    