# Topological Sorting (DFS Based)

## 📌 Definition
Topological Sorting is a linear ordering of vertices in a **Directed Acyclic Graph (DAG)** such that for every directed edge `u → v`, node `u` comes before `v` in the ordering.

---

## ⚠️ Important Condition
- Topological sort is only possible for **DAG (Directed Acyclic Graph)**.
- If the graph contains a **cycle**, topological sorting is not valid.

---

## 🧠 Intuition
- A node should be processed **only after all its dependencies are processed**.
- This is similar to:
  - Task scheduling
  - Course prerequisite problems

---

## 🔁 DFS-Based Approach

### Steps:
1. Create a `visited` array/map.
2. Traverse all nodes using DFS.
3. For each node:
   - Mark it as visited.
   - Recursively visit all its neighbors.
   - After visiting all neighbors, **push the node into a stack**.
4. After DFS completes:
   - Pop elements from the stack → gives topological order.

---

## 💡 Why Stack Works?
- A node is pushed **after all its adjacent nodes are processed**.
- So dependencies automatically come before the node in final order.

---

## ⏱️ Time Complexity
- **O(V + E)**
  - V → number of vertices
  - E → number of edges

---

## 📦 Space Complexity
- **O(V)**
  - For visited array and stack

---

## 📊 Example

Graph:
0 → 1  
0 → 2  
1 → 3  
2 → 3  

Possible Topological Order:

0 2 1 3

OR

0 1 2 3


---

## 🚫 When It Fails
- If the graph contains a **cycle**, topological sorting is not possible.
- Cycle detection can be done using:
  - DFS (recursion stack)
  - Kahn’s Algorithm (BFS)

---

## 🔄 Applications
- Task Scheduling
- Course Prerequisite Problems
- Build Systems (compilers)
- Dependency Resolution

---

## 🔥 Key Insight
Topological Sort ensures:
> "A node appears only after all nodes pointing to it are processed."