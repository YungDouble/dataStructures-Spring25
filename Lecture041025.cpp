---
  Lecture Notes | 4/10/2025
---
  Recall the fibonacci sequence, which each term is a summation of the previous two terms
  Recursion can perform badly.

  -Dynamic Programming (DP)
int dp[50];
memset(dp, -1, sizeof(dp));
int fibo(int n)
{
  if(dp[n] != -1) return dp[n];
  if(n == 0) return 0;
  if(n == 1) return 1;
  dp[n] = fibo(n -1) + fibo(n - 2);
  return dp[n];
}

---

### 🧠 What’s the problem being solved?

The function `fibo(n)` computes the **n-th Fibonacci number**, where:
- `fibo(0) = 0`
- `fibo(1) = 1`
- `fibo(n) = fibo(n-1) + fibo(n-2)` for `n ≥ 2`

---

### ⚠️ Problem with the naive recursive approach

Without memoization, this recursion recalculates the same values many times, leading to **exponential time**.

---

### ✅ Dynamic Programming Solution (Memoization)

This version stores results the first time they’re computed so that future calls can **reuse** the values instead of recalculating them.

---

### 🔍 Code Breakdown:

```cpp
int dp[50];                     // Declare a global memoization array
memset(dp, -1, sizeof(dp));    // Initialize all elements to -1 (meaning "not computed yet")
```

#### `fibo(n)` function:

```cpp
int fibo(int n)
{
  if(dp[n] != -1) return dp[n];          // If already computed, return the cached value
  if(n == 0) return 0;                   // Base case 1
  if(n == 1) return 1;                   // Base case 2

  dp[n] = fibo(n - 1) + fibo(n - 2);     // Compute and store the result
  return dp[n];                          // Return the stored result
}
```

---

### 🧠 What's happening:

If you call `fibo(6)`, here’s the **memoization tree**:

```
fibo(6)
 └── fibo(5)
      └── fibo(4)
           └── fibo(3)
                └── fibo(2)
                     └── fibo(1) -> 1
                     └── fibo(0) -> 0
                └── fibo(1) -> (memoized)
           └── fibo(2) -> (memoized)
      └── fibo(3) -> (memoized)
 └── fibo(4) -> (memoized)
```

Each value is calculated **only once**, stored in `dp`, and reused — reducing the time complexity to **O(n)**.

---

### 🧪 Example:

```cpp
fibo(5)
= fibo(4) + fibo(3)
= (fibo(3) + fibo(2)) + (fibo(2) + fibo(1))
... etc.
```

Using memoization:
- You only compute `fibo(0)` to `fibo(5)` once
- Each `fibo(i)` result is stored in `dp[i]`

---

### 🔁 Summary:

- `dp[]`: stores previously computed Fibonacci values
- `memset(dp, -1, ...)`: marks all values as uncomputed
- Reduces time complexity from **exponential O(2^n)** to **linear O(n)**

Let me know if you want to turn this into a bottom-up DP or rewrite it in Python!
