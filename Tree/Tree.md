# 🌳 Tree Data Structure — Complete Theory Guide

## Table of Contents

- [What is a Tree?](#what-is-a-tree)
- [Key Terminology](#key-terminology)
- [Properties of Trees](#properties-of-trees)
- [Types of Trees](#types-of-trees)
- [Tree Traversals](#tree-traversals)
- [Common Operations & Time Complexity](#common-operations--time-complexity)
- [Binary Search Tree (BST)](#binary-search-tree-bst)
- [Balanced Trees](#balanced-trees)
- [Heap](#heap)
- [Trie (Prefix Tree)](#trie-prefix-tree)
- [Real-World Applications](#real-world-applications)

---

## What is a Tree?

A **Tree** is a non-linear, hierarchical data structure consisting of **nodes** connected by **edges**. It is a special case of a graph with no cycles.

```
          [1]          ← Root
         /   \
       [2]   [3]       ← Children of Root
      /   \     \
    [4]   [5]   [6]    ← Leaf nodes
```

Every tree with `n` nodes has exactly `n - 1` edges.

---

## Key Terminology

| Term | Definition |
|------|-----------|
| **Node** | Basic unit containing data |
| **Root** | Topmost node with no parent |
| **Edge** | Link connecting two nodes |
| **Parent** | Node with a child below it |
| **Child** | Node directly below a parent |
| **Leaf** | Node with no children |
| **Sibling** | Nodes sharing the same parent |
| **Subtree** | A node and all its descendants |
| **Depth** | Distance from root to a node (root = 0) |
| **Height** | Distance from a node to its deepest leaf |
| **Level** | Set of all nodes at the same depth |
| **Degree** | Number of children a node has |
| **Forest** | Collection of disjoint trees |

### Height vs Depth

```
         [A]    ← depth=0, height=2
        /   \
      [B]   [C] ← depth=1, height=1 / height=0
      /
    [D]          ← depth=2, height=0 (leaf)
```

---

## Properties of Trees

1. There is exactly **one path** between any two nodes.
2. A tree with `n` nodes has `n - 1` edges.
3. Every node except the root has **exactly one parent**.
4. Trees are **acyclic** — no node is visited twice.
5. Adding any edge to a tree creates a **cycle**.
6. Removing any edge from a tree creates a **forest**.

---

## Types of Trees

### 1. General Tree
Each node can have any number of children.

### 2. Binary Tree
Each node has **at most 2 children** (left and right).

```
      [10]
     /    \
   [5]    [20]
  /   \
[3]   [7]
```

**Variants:**

- **Full Binary Tree** — Every node has 0 or 2 children.
- **Complete Binary Tree** — All levels filled except possibly the last, filled left to right.
- **Perfect Binary Tree** — All internal nodes have 2 children; all leaves at same level.
- **Degenerate (Pathological) Tree** — Every node has only one child (essentially a linked list).
- **Balanced Binary Tree** — Height is O(log n); difference in left/right subtree heights ≤ 1.

### 3. Binary Search Tree (BST)
Binary tree where `left < root < right` for every node.

### 4. AVL Tree
Self-balancing BST. Balance factor (height difference) is always −1, 0, or +1.

### 5. Red-Black Tree
Self-balancing BST with color properties ensuring O(log n) operations.

### 6. B-Tree / B+ Tree
Multi-way self-balancing tree used in databases and file systems.

### 7. Heap
Complete binary tree satisfying the heap property (min-heap or max-heap).

### 8. Trie
Tree used for efficient string storage and prefix searching.

### 9. Segment Tree
Tree used for range queries and point updates on arrays.

### 10. Fenwick Tree (Binary Indexed Tree)
Efficient data structure for prefix sum queries and updates.

---

## Tree Traversals

Traversal is the process of visiting every node exactly once.

### Depth-First Search (DFS)

#### In-order (Left → Root → Right)
Produces sorted output for a BST.

```
Tree:         [4]
             /   \
           [2]   [6]
          /   \
        [1]   [3]

In-order: 1 → 2 → 3 → 4 → 6
```

```python
def inorder(node):
    if node:
        inorder(node.left)
        print(node.val)
        inorder(node.right)
```

#### Pre-order (Root → Left → Right)
Useful for copying or serializing a tree.

```
Pre-order: 4 → 2 → 1 → 3 → 6
```

```python
def preorder(node):
    if node:
        print(node.val)
        preorder(node.left)
        preorder(node.right)
```

#### Post-order (Left → Right → Root)
Useful for deleting a tree or evaluating expression trees.

```
Post-order: 1 → 3 → 2 → 6 → 4
```

```python
def postorder(node):
    if node:
        postorder(node.left)
        postorder(node.right)
        print(node.val)
```

### Breadth-First Search (BFS) / Level-order

Visits nodes level by level using a queue.

```
Level-order: 4 → 2 → 6 → 1 → 3
```

```python
from collections import deque

def level_order(root):
    queue = deque([root])
    while queue:
        node = queue.popleft()
        print(node.val)
        if node.left:  queue.append(node.left)
        if node.right: queue.append(node.right)
```

### Traversal Summary

| Traversal | Order | Use Case |
|-----------|-------|----------|
| In-order | L → Root → R | BST sorted output |
| Pre-order | Root → L → R | Serialize/clone tree |
| Post-order | L → R → Root | Delete tree, expression eval |
| Level-order | Level by level | Shortest path, BFS problems |

---

## Common Operations & Time Complexity

### Binary Tree

| Operation | Average | Worst Case |
|-----------|---------|------------|
| Access | O(n) | O(n) |
| Search | O(n) | O(n) |
| Insert | O(n) | O(n) |
| Delete | O(n) | O(n) |

### Binary Search Tree (BST)

| Operation | Average | Worst Case |
|-----------|---------|------------|
| Access | O(log n) | O(n) |
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |

> ⚠️ Worst case O(n) occurs when the BST is degenerate (unbalanced).

### Balanced BST (AVL / Red-Black)

| Operation | Average | Worst Case |
|-----------|---------|------------|
| Access | O(log n) | O(log n) |
| Search | O(log n) | O(log n) |
| Insert | O(log n) | O(log n) |
| Delete | O(log n) | O(log n) |

---

## Binary Search Tree (BST)

### Property
For every node `N`:
- All values in the **left subtree** < `N.val`
- All values in the **right subtree** > `N.val`

### Search

```python
def search(node, target):
    if not node or node.val == target:
        return node
    if target < node.val:
        return search(node.left, target)
    return search(node.right, target)
```

### Insert

```python
def insert(node, val):
    if not node:
        return TreeNode(val)
    if val < node.val:
        node.left = insert(node.left, val)
    elif val > node.val:
        node.right = insert(node.right, val)
    return node
```

### Delete

Three cases:
1. **Node is a leaf** → simply remove it.
2. **Node has one child** → replace node with its child.
3. **Node has two children** → replace with **in-order successor** (smallest in right subtree).

```python
def delete(node, val):
    if not node:
        return None
    if val < node.val:
        node.left = delete(node.left, val)
    elif val > node.val:
        node.right = delete(node.right, val)
    else:
        if not node.left:
            return node.right
        elif not node.right:
            return node.left
        # Find in-order successor (min of right subtree)
        successor = node.right
        while successor.left:
            successor = successor.left
        node.val = successor.val
        node.right = delete(node.right, successor.val)
    return node
```

---

## Balanced Trees

### AVL Tree

Maintains **balance factor** = `height(left) - height(right)` ∈ {-1, 0, 1}.

On insert/delete, rotations are used to restore balance:

- **Left Rotation (LL)**
- **Right Rotation (RR)**
- **Left-Right Rotation (LR)**
- **Right-Left Rotation (RL)**

```
Right Rotation Example:
    z                 y
   / \              /   \
  y   T4    →     x     z
 / \            /  \   / \
x   T3         T1  T2 T3  T4
```

### Red-Black Tree

A BST where every node is colored **Red** or **Black**, with these rules:

1. Every node is Red or Black.
2. The root is always Black.
3. Every leaf (null) is Black.
4. A Red node's children must be Black (no two consecutive reds).
5. All paths from a node to its descendant leaves have the same number of Black nodes.

These rules ensure the tree height is at most **2 log(n+1)**.

---

## Heap

A **Complete Binary Tree** satisfying the **heap property**:

- **Max-Heap**: Parent ≥ Children (root is the maximum)
- **Min-Heap**: Parent ≤ Children (root is the minimum)

```
Max-Heap:
         [90]
        /    \
      [70]  [80]
     /   \
   [50]  [60]
```

Heaps are typically stored as **arrays**:

```
Index:  0    1    2    3    4
Array: [90, 70, 80, 50, 60]

Parent of i  → (i - 1) // 2
Left child   → 2i + 1
Right child  → 2i + 2
```

### Key Operations

| Operation | Time |
|-----------|------|
| Get min/max | O(1) |
| Insert (heapify up) | O(log n) |
| Delete min/max (heapify down) | O(log n) |
| Build heap from array | O(n) |

### Use Cases
- Priority queues
- Heap sort
- Dijkstra's and Prim's algorithms
- Scheduling algorithms

---

## Trie (Prefix Tree)

A tree where each **path from root to a node** represents a **prefix** of stored strings.

```
Words: ["cat", "car", "card", "care", "dog"]

         root
        /    \
       c      d
       |      |
       a      o
      / \     |
     t   r    g*
     *  / \
       d   e
       *   *
(* = end of word)
```

### Time Complexity

| Operation | Time |
|-----------|------|
| Insert | O(L) — L = word length |
| Search | O(L) |
| Prefix search | O(L) |
| Delete | O(L) |

### Use Cases
- Autocomplete / search suggestions
- Spell checkers
- IP routing tables
- Word games (Boggle, Scrabble)

---

## Real-World Applications

| Tree Type | Application |
|-----------|------------|
| Binary Tree | Expression parsing, Huffman encoding |
| BST | Symbol tables in compilers |
| AVL / Red-Black | Java's `TreeMap`, C++ STL `map`/`set` |
| B-Tree / B+ Tree | Database indexes (MySQL, PostgreSQL) |
| Heap | OS process scheduling, Dijkstra's algorithm |
| Trie | Search engine autocomplete, DNS lookup |
| Segment Tree | Range min/max/sum queries in competitive programming |
| Decision Tree | Machine learning classification |
| DOM Tree | Browser rendering of HTML |
| File System | Directory structures (Linux, NTFS) |

---

## Quick Reference Cheat Sheet

```
Tree Facts
──────────────────────────────────────────
n nodes → n-1 edges
Binary tree max nodes at level l → 2^l
Perfect binary tree of height h → 2^(h+1) - 1 nodes
BST in-order → sorted sequence
Heap stored as array → parent=(i-1)//2

Time Complexities
──────────────────────────────────────────
BST (balanced):   Search/Insert/Delete → O(log n)
BST (worst case): all ops             → O(n)
Heap:             peek                → O(1)
                  insert/delete       → O(log n)
Trie:             insert/search       → O(L)
```

---

*Feel free to contribute improvements or additional examples via a pull request.*