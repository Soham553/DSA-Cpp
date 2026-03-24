# Breadth-First Search(BFS)

   - Afundamental graph traversal algorithm that expolres nodes layer-by-layer, visithing all neighbors at the current depth before moving to the next level.

   - Utilizing a queue (FIFO) data structure, it is ideal for finding the shortest path in unweighted graphs with a time complexity of O(V + E).


# Key Aspects Of BFS

   - Approach: starts at a root node and explores all neighboring nodes at the present depth prior to moving on to nodes at the next depth level.

   - Data Structure: Uses a queue(First-In-First-Out) to manage nodes, ensuring nodes are visited in the order they are encountered.

   - Applications:
        
        - Shortest Path: Finds the minimunm distance between two nodes in an unwighted graph.

        - Connected Components: identifies all connected components in an undirected graph.

        - Network Analysis: Find neighbour nodes in social networks or GPS systems.

    
    - Algorithm Steps:

         1. Initialize: Start at a designated node, mark it a visited, and add it to a queue.

         2. Loop: While the queue is not empty:
            
            1. Dequeue a node from the front.

            2. Check all adjacent neighbors of the current node.

            3. If a neighbour has not been visited, mark it visited and enqueue it.

            