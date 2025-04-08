/* Lecture-04082025.cpp */

/* Absolutely! Let’s review **decision trees** — they’re an important concept in both **data structures** and **algorithms**, often used in **decision-making problems**, **search**, and **machine learning**.

---

## ✅ What is a Decision Tree?

A **decision tree** is a **binary tree** (usually) where:
- Each **internal node** represents a **decision or condition**.
- Each **branch** represents the **outcome** of a decision.
- Each **leaf node** represents a **final result or action**.

---

### 📘 Example: Yes/No Decision Tree

Suppose you're classifying whether an animal is a cat:

```
             [Has whiskers?]
              /          \
           Yes            No
         /                  \
   [Meows?]              [Dog]
     /    \
  Yes     No
[Cat]   [Lynx]
```

---

### 🔧 How to Use a Decision Tree (in CS Problems):

Let’s say you’re asked to solve a **decision problem** like this:

> You need to find the minimum number of comparisons required to find the **maximum** of `n` elements.

You can use a **decision tree** to visualize **all possible comparisons** and **outcomes**, where each comparison is a decision.

---

## 🧠 Key Concepts

| Concept                | Explanation                                                                 |
|------------------------|-----------------------------------------------------------------------------|
| **Height** of Tree     | Longest path from root to a leaf (relates to worst-case decisions).        |
| **Leaf nodes**         | Total possible outcomes (solutions).                                       |
| **Internal nodes**     | Each decision (e.g., comparison) made.                                     |
| **Depth**              | Number of decisions to reach a solution.                                   |
| **Minimum height**     | Related to \(\log_2(n!)\) in comparison-based sorting — optimal comparison tree. |

---

### 📐 Real Use in Data Structures:

1. **Searching and Sorting**:  
   - Binary search decision tree has height \(\log_2(n)\)
   - Sorting lower bound: \(\log_2(n!)\) comparisons required

2. **Huffman Encoding**:  
   - Decision trees are used to encode characters based on frequency.

3. **Expression Trees**:  
   - Used to evaluate expressions like `(3 + 5) * (2 - 4)`


## 🧠 **What is Counting Sort?**

**Counting Sort** is a **non-comparison-based** sorting algorithm.  
Instead of comparing elements like in bubble sort or quicksort, it **counts** how many times each value occurs and uses that to figure out where to place them in the sorted output.

---

### 🟢 **When to Use Counting Sort**
- When the input is **integers only**
- And the **range of input values is small** (like 0 to 100, not 0 to 10^9)
- It’s **linear time**, i.e. \( O(n + k) \) where:
  - \( n \) = number of elements
  - \( k \) = range of input values

---

### 📊 **How It Works (Step-by-Step)**

Given:  
`A = [4, 2, 2, 8, 3, 3, 1]`

1. **Find the range**  
   - max = 8 ⇒ so we make a count array of size 9 (index 0–8)

2. **Count occurrences**

| Index (value) | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---------------|---|---|---|---|---|---|---|---|---|
| Count         | 0 | 1 | 2 | 2 | 1 | 0 | 0 | 0 | 1 |

3. **Modify count array to store positions**

Running total:

| Index         | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---------------|---|---|---|---|---|---|---|---|---|
| Position      | 0 | 1 | 2 | 4 | 6 | 7 | 7 | 7 | 7 |

4. **Build output array (stable sort)**  
   For each element in the original array, place it in the right position based on the `count` array, then increment count.

Final sorted array:  
`[1, 2, 2, 3, 3, 4, 8]`

---

### 🧩 **Key Notes**
- **Stable**: preserves the order of duplicates.
- **Not comparison-based**: works in \( O(n + k) \), so can be faster than \( O(n \log n) \) sorts.
- Not suitable for large ranges (like sorting zip codes from 0 to 99999 with just 10 values).

---

### 📦 Time & Space Complexity

| Aspect     | Complexity        |
|------------|-------------------|
| Time       | \(O(n + k)\)      |
| Space      | \(O(k + n)\)      |
| Stable?    | ✅ Yes            |

---

Want to try a quick practice example together? Or want to see how it compares with radix sort or bucket sort next?

  */

let C[0..k] be a new array
  for i = 0 to k
    C[i] = 0
  for j = 1 to A.length
    C[A[j]] = C[A[j]] + 1
// C[i] now contains the number of elements equal to i
  for i = 1 ot k
    C[i] = C[i] + C[i - 1]
// C[i] now contains the number of elements elements less than or equal to i
for j = A.length downnt 1
  B[C[A[j]]] = A[j]
  C[A[j]] = C[A[j]] - 1
/*
what is [A[j]]? it is the value that is 2
  B[C[A[j]]] => A[j] = 2, A of J is 2
  what is C[2]? = 5
So we put a 2 at the index 5 of the B array

Yes! Let’s **simplify** what your pseudocode is doing — **step-by-step and conceptually** — so it’s easier to digest and apply. Counting Sort can *look* complex because of the index juggling, but it’s really just:

> Count → Accumulate → Place

#### **1. Count how many times each number appears**
```pseudo
for i = 0 to k:
    C[i] = 0
for j = 1 to A.length:
    C[A[j]] = C[A[j]] + 1
```

👉 This part builds the **frequency count** of each number.  
If `A = [4, 2, 2, 8, 3, 3, 1]`, then `C[2] = 2`, `C[3] = 2`, etc.

---

#### **2. Transform the count array to show *positions***
```pseudo
for i = 1 to k:
    C[i] = C[i] + C[i - 1]
```

👉 Now, `C[i]` tells us **how many elements are ≤ i**, so we know where to place each value in the sorted array.

---

#### **3. Place each element in its correct position (backward for stability)**
```pseudo
for j = A.length down to 1:
    B[C[A[j]]] = A[j]
    C[A[j]] = C[A[j]] - 1
```

👉 For each number in A:
- Use the `C` array to **know where it goes** in the output array `B`.
- After placing it, **decrement the count** so the next same number gets placed before it.

---

### 🎯 Think of it like this:

| Step        | You’re doing...                         |
|-------------|------------------------------------------|
| `C[i]++`    | Tallying how many times each number appears |
| `C[i] += C[i-1]` | Figuring out where each number should go |
| `B[...] = A[j]` | Putting numbers into the right spot     |

---

### ✅ Simplified Flow (Mental Model):

1. **Count** how many of each number → `C[i]`
2. **Figure out positions** → cumulative counts
3. **Place values** into the output array `B[]` using positions

---

### Want even more intuition?

Imagine you're lining up **kids by age**:
- Step 1: Count how many kids are age 5, 6, etc.
- Step 2: Say: “If 3 kids are younger than age 7, a kid who is 7 goes in slot 4.”
- Step 3: Place each kid in order, updating the count so the next one doesn't overwrite.

---

Let me know if you want to step through a **full example** together — or if you're ready to compare it with **Radix Sort** next!

*/
