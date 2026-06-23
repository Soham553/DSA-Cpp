# Arrays

Alright, so let's talk about Arrays — one of the most fundamental data structures you'll use basically everywhere, whether it's MERN stack, DevOps scripting, or eventually ML pipelines. Under the hood, it's pretty clean to understand once you get the actual idea of what's happening in memory.

---

## What is an Array?

An array is just a **collection of elements stored in contiguous memory locations**. That's the key — contiguous. All elements are placed one after another in memory, which is exactly why accessing any element is O(1). You know the start address, you know the size of each element, so you just do the math and jump directly to it. No traversal, no nonsense.

Think of it like this: imagine a row of lockers, all numbered. You don't walk locker by locker searching — you just say "locker 5" and go straight there. That's what's happening under the hood when you do `arr[4]`.

---

## How Arrays Work in Memory

When you declare an array, the system:
1. Allocates a **fixed block of contiguous memory**
2. Assigns a **base address** (the address of the first element)
3. Every element sits right next to the previous one

So if `arr[0]` is at memory address `1000` and each integer takes 4 bytes, then:
- `arr[1]` → 1004
- `arr[2]` → 1008
- `arr[3]` → 1012

The formula is: `address of arr[i] = base_address + (i × size_of_element)`

This is the real reason why **random access is O(1)** — it's pure arithmetic.

---

## Static vs Dynamic Arrays

**Static Arrays** — fixed size, declared upfront. Once you say "I need 10 slots," that's it. You get exactly that block of memory. Fast, but inflexible.

**Dynamic Arrays** (like JavaScript arrays or Python lists) — these resize automatically. But here's what's actually happening when they resize: the system allocates a **new, bigger block of memory**, copies all the old elements over, and then frees the old block. That's why resizing is O(n) in the worst case — it's copying everything.

Most dynamic array implementations (like `ArrayList` in Java or `vector` in C++) use **amortized doubling** — they double the capacity each time they resize, so the average cost of insertion is still O(1) even though occasional resizes are expensive.

---

## Time Complexity

| Operation        | Time Complexity | Why |
|-----------------|----------------|-----|
| Access `arr[i]` | O(1)           | Direct address calculation |
| Search (unsorted)| O(n)          | Might have to check every element |
| Search (sorted) | O(log n)       | Binary search |
| Insert at end   | O(1) amortized | Dynamic resize handles it |
| Insert at middle| O(n)           | Need to shift elements right |
| Delete at end   | O(1)           | Just move the pointer |
| Delete at middle| O(n)           | Need to shift elements left |

---

## Types of Arrays

**1D Array** — the classic. Just a straight line of elements.
```js
const arr = [10, 20, 30, 40, 50];
```

**2D Array (Matrix)** — an array of arrays. Used everywhere in ML (think matrices, image pixel grids, etc.).
```js
const matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
];
```

**Jagged Arrays** — rows can have different lengths. Unlike a proper 2D matrix where every row is the same size.

---

## Common Operations (with code)

```js
// Traversal — O(n)
for (let i = 0; i < arr.length; i++) {
  console.log(arr[i]);
}

// Insert at end — O(1) amortized
arr.push(60);

// Insert at specific index — O(n)
arr.splice(2, 0, 99); // inserts 99 at index 2, shifts rest right

// Delete at specific index — O(n)
arr.splice(2, 1); // removes element at index 2

// Reverse — O(n)
arr.reverse();

// Sort — O(n log n)
arr.sort((a, b) => a - b);
```

---

## Where Arrays are Used in the Real World

- **MERN Stack** — storing lists of users, posts, products; basically any collection of data coming from MongoDB comes back as an array.
- **DevOps** — shell scripts, reading config values, processing batches of servers or logs.
- **AI/ML** — this is where arrays get serious. Everything in ML is built on arrays. Tensors (what PyTorch and TensorFlow use) are basically multi-dimensional arrays. Image data, weights of a neural network, input features — all stored as arrays (or matrices/tensors). NumPy arrays are the backbone of the entire Python ML ecosystem.

---

## Key Takeaways

- Arrays = contiguous memory → random access is O(1), that's the real superpower
- Insertion/deletion in the middle is expensive because of shifting
- Dynamic arrays resize by doubling — amortized O(1) for append
- In ML/AI, you'll live and breathe multi-dimensional arrays (tensors). Understanding the basics here is 100% foundational for that path.

The data structure itself is simple, but understanding *why* it works the way it does — that's the engineering mindset that matters when you go deeper.