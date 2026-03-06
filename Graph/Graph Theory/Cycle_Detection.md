# Cycle Detection In undirected Graph

Let's get started 

What does it mean detecting a cycle
  - In simple word we have to find out weather loop is present in graph or not

     
           0-------1            1-------0
           |       |            | 
           |       |            |
           2-------3            2-------4
                                        |
                                        |
                                        3

   - As we see there is loop in Graph A and in Grap there is not close loop

We will start with logic
    - we will travers graph as we travers in BFS
    - As we know Queue data structure and visited array is neede for BFS, we have to add one for array for tracking the parents of node which we are going to add in queue

Dry Run:
    - On graph A: Start with 0
         - Add 0 in queue.
         - mark 0 and visited in visited[0] = true.
         - parent[0] = -1.
         - Apply while loop until Queue is not empty.
            - we will travel all the neighbours of 0. 0 -> 1, 2 and pop 0 from queue.
                - visited[1] is not visited.
                Add 1 to queue
                So, visited[1] = 1, parent[1] = 0 
                
                - For 2:
                visited[2] is not visited
                Add 2 to queue
                So, visite[2] = 1, patent[2] = 0

        - Queue is not empty Queue has 1 and 2.
            - We will travel all the neighbours of 1. 1 -> 0, 3
                - visited of 0 is true, we will negelate it.
                  And the parent of 1 = 0.
                  
                - For 3:
                  visited[3] != true
                  Add 3 in queue
                  So, visited[3] = 1, parent[3] = 1.
                - All the neighbours are visited of 1 pop 1 from queue.
        
        - Queue is not empty Queue has 2 and 3. 2 is front
            - we will travel all the neighbours of 2. 2 ->0, 3
                - For 0:
                  visited[0] is true 
                  And 0 is parent of 2. So, move forward.
                - For 3:
                  3 also visited but the parent of 2 is not 3 
                  So, the cycle is present.
   