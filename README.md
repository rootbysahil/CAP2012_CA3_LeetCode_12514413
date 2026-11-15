# CAP2012 – Data Structures | Continuous Assessment 3 (CA3)
### LeetCode Problem Solving using C++ and GitHub Submission

- **Student Name:** Sahil Rai
- **Registration Number:** 12514413
- **Course Code:** CAP2012
- **Course Title:** Data Structures
- **Section:** D2518
- **Language Used:** C++ (Standard C++17)

---

## 📂 Repository Structure

```text
CAP2012_CA3_LeetCode_12514413/
├── Easy/     (Problems 01 – 09)
├── Medium/   (Problems 10 – 14)
├── Hard/     (Problems 15 – 16)
└── README.md
```

---

## 📋 Problem Index & Complexity Analysis

| S.No | LC # | Problem Name | Level | Topics Covered | Unit | Time Complexity | Space Complexity |
|:---:|:---:|:---|:---:|:---|:---:|:---:|:---:|
| **01** | [1486](https://leetcode.com/problems/xor-operation-in-an-array/) | XOR Operation in an Array | Easy | Arrays, Loops, Bitwise XOR | I | $O(n)$ | $O(1)$ |
| **02** | [1572](https://leetcode.com/problems/matrix-diagonal-sum/) | Matrix Diagonal Sum | Easy | 2D Arrays, Diagonal Traversal | II | $O(n)$ | $O(1)$ |
| **03** | [217](https://leetcode.com/problems/contains-duplicate/) | Contains Duplicate | Easy | Arrays, Searching, Duplicate Detection | II | $O(n \log n)$ | $O(1)$ |
| **04** | [35](https://leetcode.com/problems/search-insert-position/) | Search Insert Position | Easy | Arrays, Binary Search | II | $O(\log n)$ | $O(1)$ |
| **05** | [876](https://leetcode.com/problems/middle-of-the-linked-list/) | Middle of the Linked List | Easy | Linked Lists, Slow & Fast Pointers | III | $O(n)$ | $O(1)$ |
| **06** | [237](https://leetcode.com/problems/delete-node-in-a-linked-list/) | Delete Node in a Linked List | Easy | Linked Lists, Pointer Manipulation | III | $O(1)$ | $O(1)$ |
| **07** | [232](https://leetcode.com/problems/implement-queue-using-stacks/) | Implement Queue using Stacks | Easy | Stacks, Queues, FIFO Operations | IV | Amortized $O(1)$ | $O(n)$ |
| **08** | [1047](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/) | Remove All Adjacent Duplicates In String | Easy | Stack, Push/Pop, String Processing | IV | $O(n)$ | $O(n)$ |
| **09** | [1700](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/) | Number of Students Unable to Eat Lunch | Easy | Queue, Simulation, FIFO | IV | $O(n)$ | $O(1)$ |
| **10** | [560](https://leetcode.com/problems/subarray-sum-equals-k/) | Subarray Sum Equals K | Medium | Arrays, Prefix Sum, Hash Map | II | $O(n)$ | $O(n)$ |
| **11** | [54](https://leetcode.com/problems/spiral-matrix/) | Spiral Matrix | Medium | 2D Arrays, Matrix Traversal | II | $O(m \times n)$ | $O(1)$ |
| **12** | [24](https://leetcode.com/problems/swap-nodes-in-pairs/) | Swap Nodes in Pairs | Medium | Linked Lists, Pointer Manipulation | III | $O(n)$ | $O(1)$ |
| **13** | [82](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) | Remove Duplicates from Sorted List II | Medium | Linked Lists, Deletion, Pointer Handling | III | $O(n)$ | $O(1)$ |
| **14** | [150](https://leetcode.com/problems/evaluate-reverse-polish-notation/) | Evaluate Reverse Polish Notation | Medium | Stack, Expression Evaluation | IV | $O(n)$ | $O(n)$ |
| **15** | [85](https://leetcode.com/problems/maximal-rectangle/) | Maximal Rectangle | Hard | Stack, Histogram, 2D Arrays | IV | $O(m \times n)$ | $O(n)$ |
| **16** | [143](https://leetcode.com/problems/reorder-list/) | Reorder List | Hard | Linked Lists, Reversal, Merging | III | $O(n)$ | $O(1)$ |

---

## 🎯 Viva Preparation Notes

### Unit I: Basic Concepts & Arrays
- **Bitwise XOR Property (LC 1486):** $X \oplus 0 = X$ and $X \oplus X = 0$. Using a single loop, we accumulate the running XOR in $O(1)$ extra space.

### Unit II: 2D Arrays & Searching
- **Matrix Diagonals (LC 1572):** Primary diagonal index is `[i][i]`; secondary diagonal index is `[i][n - 1 - i]`. The center element is shared if $n$ is odd, counted only once.
- **Binary Search (LC 35):** Avoid integer overflow using `mid = left + (right - left) / 2`. If target is not present, `left` pointer naturally points to the correct insert position.
- **Prefix Sum + Hash Map (LC 560):** A contiguous subarray from index $j$ to $i$ has sum $k$ if $PrefixSum[i] - PrefixSum[j] = k$. We use an `unordered_map` to store prefix frequencies for $O(1)$ average lookups.

### Unit III: Linked Lists
- **Slow & Fast Pointers (Tortoise & Hare - LC 876, LC 143):** Moving `slow` by 1 and `fast` by 2 finds the middle node in a single pass without knowing the list length beforehand.
- **In-place Node Deletion without Head (LC 237):** We copy the data of `node->next` into `node`, and bypass `node->next`.
- **Pairwise Swap & Duplicate Removal (LC 24, LC 82):** Using a `dummy` node before `head` eliminates edge cases when the original head needs to be swapped or removed.
- **Reorder List (LC 143):** Broken down into 3 steps: 1) Find middle using two pointers, 2) Reverse second half, 3) Merge first and second halves alternately.

### Unit IV: Stacks and Queues
- **Queue using Two Stacks (LC 232):** Inverting LIFO order twice produces FIFO order. Elements are shifted from `inputStack` to `outputStack` only when `outputStack` becomes empty, giving amortized $O(1)$ operations.
- **Adjacent Duplicates Removal (LC 1047):** Using `std::string` as a stack allows $O(1)$ push (`push_back`) and pop (`pop_back`), removing the need for an explicit stack data structure or string reversal.
- **Postfix Evaluation / RPN (LC 150):** Operands are pushed onto a stack. When an operator is encountered, the top two operands are popped (first popped is right operand, second popped is left operand), evaluated, and the result is pushed back.
- **Maximal Rectangle (LC 85):** Each row is treated as the base of a histogram of consecutive 1s. The problem is solved by computing the largest rectangle in histogram for each row using a monotonic stack.
