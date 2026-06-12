<div align="center">

```
██████╗ ███████╗ █████╗     ██╗      █████╗ ██████╗
██╔══██╗██╔════╝██╔══██╗   ██║     ██╔══██╗██╔══██╗
██║  ██║███████╗███████║   ██║     ███████║██████╔╝
██║  ██║╚════██║██╔══██║   ██║     ██╔══██║██╔══██╗
██████╔╝███████║██║  ██║   ███████╗██║  ██║██████╔╝
╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚══════╝╚═╝  ╚═╝╚═════╝
```

# 🧠 DSA Lab — C++ Edition

**A comprehensive collection of Data Structures, Algorithms, and curated solutions to problems from LeetCode, HackerRank, and beyond.**

[![Language](https://img.shields.io/badge/Language-C++17-00599C?style=flat-square&logo=c%2B%2B)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-green?style=flat-square)](LICENSE)
[![LeetCode](https://img.shields.io/badge/LeetCode-Solutions-FFA116?style=flat-square&logo=leetcode&logoColor=white)](https://leetcode.com/)
[![HackerRank](https://img.shields.io/badge/HackerRank-Solutions-00EA64?style=flat-square&logo=hackerrank&logoColor=white)](https://www.hackerrank.com/)
[![PRs Welcome](https://img.shields.io/badge/PRs-Welcome-blueviolet?style=flat-square)](CONTRIBUTING.md)

</div>

---

## 📌 About This Repository

This repository is a structured, well-documented reference for everything related to **Data Structures & Algorithms in C++**. Whether you're grinding competitive programming, preparing for technical interviews, or just deeply curious about how data structures work under the hood — this is your playground.

> *"The secret to getting ahead is getting started."* — Mark Twain

Every implementation is written from scratch with clarity in mind: no black boxes, no copy-pasted STL wrappers — just clean, readable C++ that you can actually learn from.

---

## 🗂️ Repository Structure

```
DSA-Lab-CPP/
│
├── 📁 data-structures/
│   ├── 📁 sequential/
│   │   ├── array/
│   │   ├── linked-list/
│   │   ├── stack/
│   │   ├── queue/
│   │   └── deque/
│   │
│   └── 📁 dynamic/
│       ├── dynamic-array/
│       ├── hash-table/
│       ├── heap/
│       ├── trie/
│       ├── tree/
│       │   ├── binary-tree/
│       │   ├── binary-search-tree/
│       │   ├── avl-tree/
│       │   └── segment-tree/
│       └── graph/
│
├── 📁 algorithms/
│   ├── sorting/
│   ├── searching/
│   ├── recursion/
│   ├── dynamic-programming/
│   └── graph-algorithms/
│
├── 📁 problems/
│   ├── leetcode/
│   └── hackerrank/
│
└── 📁 utils/
    └── helpers.hpp
```

---

## 🏗️ Data Structures

### 🔗 Sequential Structures

These are the building blocks — linear structures where elements are stored and accessed in a sequence.

| Structure | Description | Time Complexity |
|-----------|-------------|-----------------|
| **Array** | Fixed-size contiguous memory | Access O(1), Insert O(n) |
| **Singly Linked List** | Chain of nodes with next pointer | Insert O(1), Search O(n) |
| **Doubly Linked List** | Bi-directional node chain | Insert O(1), Search O(n) |
| **Circular Linked List** | Last node links back to head | Insert O(1), Search O(n) |
| **Stack** | LIFO — Last In, First Out | Push/Pop O(1) |
| **Queue** | FIFO — First In, First Out | Enqueue/Dequeue O(1) |
| **Deque** | Double-ended queue | Insert/Delete O(1) both ends |

### 🌳 Dynamic / Non-Linear Structures

Structures that grow, shrink, and reshape based on the data they hold.

| Structure | Description | Notes |
|-----------|-------------|-------|
| **Dynamic Array** | Resizable array with amortized O(1) push | Like `std::vector`, but built from scratch |
| **Binary Tree** | Hierarchical structure with at most 2 children | DFS, BFS traversals included |
| **Binary Search Tree** | Sorted binary tree for efficient lookups | Insert, Delete, Search O(log n) avg |
| **AVL Tree** | Self-balancing BST | Height stays O(log n) always |
| **Segment Tree** | Range query & update structure | Range sum, min, max in O(log n) |
| **Heap (Min/Max)** | Complete binary tree satisfying heap property | Used in priority queues, Dijkstra's |
| **Hash Table** | Key-value store with O(1) avg lookup | Separate chaining & open addressing |
| **Trie** | Prefix tree for string operations | Autocomplete, spell-check, IP routing |
| **Graph** | Nodes and edges (directed/undirected) | Adjacency list & matrix representations |

---

## ⚙️ Algorithms

### 🔀 Sorting

| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | ❌ |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | ✅ |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | ❌ |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | ❌ |
| Counting Sort | O(n+k) | O(n+k) | O(n+k) | O(k) | ✅ |
| Radix Sort | O(nk) | O(nk) | O(nk) | O(n+k) | ✅ |

### 🔍 Searching

- Linear Search — O(n)
- Binary Search — O(log n)
- Ternary Search — O(log₃ n)
- Exponential Search — O(log n)

### 🌐 Graph Algorithms

- **BFS** — Breadth-First Search
- **DFS** — Depth-First Search
- **Dijkstra's** — Single Source Shortest Path
- **Bellman-Ford** — Handles negative weights
- **Floyd-Warshall** — All Pairs Shortest Path
- **Kruskal's / Prim's** — Minimum Spanning Tree
- **Topological Sort** — DAG ordering
- **Tarjan's SCC** — Strongly Connected Components

### 💡 Dynamic Programming

- Fibonacci (Top-Down & Bottom-Up)
- Longest Common Subsequence (LCS)
- Longest Increasing Subsequence (LIS)
- 0/1 Knapsack
- Coin Change
- Matrix Chain Multiplication
- Edit Distance

---

## 🧩 Problem Solutions

### 🟡 LeetCode

Solutions are categorized by topic and difficulty, each with:
- Problem link
- Approach explanation
- Time & space complexity
- Clean C++ implementation

| # | Problem | Difficulty | Topic |
|---|---------|-----------|-------|
| 1 | Two Sum | 🟢 Easy | Arrays, Hash Map |
| 2 | Add Two Numbers | 🟡 Medium | Linked List |
| 20 | Valid Parentheses | 🟢 Easy | Stack |
| 21 | Merge Two Sorted Lists | 🟢 Easy | Linked List |
| 53 | Maximum Subarray | 🟡 Medium | Dynamic Programming |
| 102 | Binary Tree Level Order Traversal | 🟡 Medium | Tree, BFS |
| 200 | Number of Islands | 🟡 Medium | Graph, DFS/BFS |
| 207 | Course Schedule | 🟡 Medium | Graph, Topological Sort |
| 322 | Coin Change | 🟡 Medium | Dynamic Programming |
| 295 | Find Median from Data Stream | 🔴 Hard | Heap |
| 42 | Trapping Rain Water | 🔴 Hard | Two Pointers / Stack |
| 23 | Merge K Sorted Lists | 🔴 Hard | Heap, Linked List |

> More solutions added regularly. Check the [`/problems/leetcode`](problems/leetcode/) directory.

### 🟢 HackerRank

Covering challenges from the **Data Structures**, **Algorithms**, and **Interview Preparation Kit** sections.

| Problem | Domain | Difficulty |
|---------|--------|-----------|
| Arrays — DS | Data Structures | Easy |
| Balanced Brackets | Data Structures | Medium |
| Queue using Two Stacks | Data Structures | Medium |
| Jesse and Cookies | Data Structures | Easy |
| Contacts | Data Structures | Medium |
| Swap Nodes [Algo] | Data Structures | Medium |
| Roads and Libraries | Graphs | Medium |
| Dijkstra: Shortest Reach | Graphs | Medium |

---

## 🚀 Getting Started

### Prerequisites

- C++17 or later
- A C++ compiler: `g++`, `clang++`, or MSVC
- Optional: CMake 3.15+ for build automation

### Clone the Repository

```bash
git clone https://github.com/yourusername/dsa-lab-cpp.git
cd dsa-lab-cpp
```

### Compile & Run

Each file is self-contained and can be compiled independently:

```bash
# Compile a single file
g++ -std=c++17 -O2 -o output data-structures/sequential/linked-list/singly_linked_list.cpp
./output

# Or use the Makefile (if present)
make run FILE=data-structures/sequential/stack/stack.cpp
```

### Run All Tests (if using CMake)

```bash
mkdir build && cd build
cmake ..
make
ctest --verbose
```

---

## 🎯 Goals of This Project

- [x] Implement all major sequential data structures from scratch
- [x] Implement all major dynamic/non-linear data structures
- [x] Cover core sorting and searching algorithms
- [x] Add LeetCode solutions with explanations
- [x] Add HackerRank solutions with explanations
- [ ] Add unit tests for all implementations
- [ ] Add visualizations using ASCII art or DOT graphs
- [ ] Add benchmarking scripts
- [ ] Expand to competitive programming templates (Codeforces, AtCoder)

---

## 🤝 Contributing

Contributions are warmly welcome! If you'd like to:

- Add a new data structure or algorithm implementation
- Add a solution to a new problem
- Improve documentation or add comments
- Fix a bug or optimize existing code

Please read [CONTRIBUTING.md](CONTRIBUTING.md) and open a pull request. All skill levels are welcome — beginners included!

---

## 📚 Resources & References

- 📘 *Introduction to Algorithms* — CLRS (Cormen et al.)
- 📗 *Data Structures and Algorithm Analysis in C++* — Mark Weiss
- 📙 *Competitive Programmer's Handbook* — Antti Laaksonen (free PDF)
- 🌐 [CP-Algorithms](https://cp-algorithms.com/) — Excellent algorithmic reference
- 🌐 [GeeksforGeeks DSA](https://www.geeksforgeeks.org/data-structures/)
- 🌐 [LeetCode Explore](https://leetcode.com/explore/)

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.

---

<div align="center">

Made with ❤️ and a lot of `cout << "debug\n";`

*If this repo helped you crack an interview or ace a contest, consider leaving a ⭐ — it means a lot!*

</div>
