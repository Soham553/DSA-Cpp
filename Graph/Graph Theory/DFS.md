# Depth First Search(DFS)

   - DFS  is a fundamental graph traversal algorithm that explores as far as possible along each branch before backtracking

   - explores as far as possible along each branch before backtracking. It uses a stack data structure—either explicitly or implicitly through recursion—to keep track of the path.

# How DFS Works

   1. Start at an arbitrary source node (or a predefined root).

    2. Mark the current node as "visited" to avoid infinite loops in cyclic graphs.

    3. Explore an unvisited adjacent neighbor by moving to it and repeating the process recursively.

    4. Backtrack when you reach a node with no unvisited neighbors, returning to the previous node to explore other paths.

    5. Repeat until all reachable nodes from the source have been visited

# Common Applications:

    - Cycle Detection: Finding if agraph contains any loops.

    - Topological Sorting: ordering tasks with dependencies.

    - Pathfinding; Determining if a path exists between two specific nodes.


