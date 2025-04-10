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

Ah! Your professor is right in pointing out that **Dynamic Programming (DP)** can be implemented **iteratively** — and this is often preferred because it avoids the function call overhead and stack overflow risks of recursion.

So let’s go over both side-by-side, focusing on **Iterative (Bottom-Up DP)**, which is what your professor wants you to know.

---

## 🧠 Big Picture:

- **Recursive Top-Down (with memoization)**: What you already did.
- **Iterative Bottom-Up**: Build the solution from the bottom by solving smaller subproblems first.

---

## ✅ Iterative (Bottom-Up DP) Version of Fibonacci

```cpp
int fibo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int dp[50];         // Or vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
```
---

### 🚀 Even More Optimized (Space Optimization)

Since Fibonacci only ever needs the last **two values**, we don’t need a whole array:

```cpp
int fibo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, result;
    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}
```
---

### 🧠 Summary Table:

| Approach                 | Time | Space | Notes                      |
|--------------------------|------|-------|----------------------------|
| Recursive (no memo)      | O(2ⁿ) | O(n)  | Very slow, exponential     |
| Top-Down with Memoization| O(n)  | O(n)  | Fast but uses stack space  |
| Bottom-Up (Iterative)    | O(n)  | O(n)  | Preferred for DP problems  |
| Bottom-Up + Space Opt    | O(n)  | O(1)  | Most efficient for Fibonacci|

---

Let me know if you want to apply this to a different DP problem like coin change, knapsack, or longest common subsequence!

  Perfect! Now you’re stepping into classic **Dynamic Programming territory** — and the **Knapsack Problem** is a foundational example used to illustrate how DP works.

Let’s break this down clearly, just like your professor might.

---

## 🎒 **0/1 Knapsack Problem – Overview**

You are given:
- A set of **n items**
- Each item has:
  - a **weight** `w[i]`
  - a **value** `v[i]`
- A **knapsack** that can carry at most **W** total weight

### ❓ Goal:
Maximize the **total value** you can put in the knapsack **without exceeding its weight capacity**. You either **take an item or don’t** (0/1 — not fractional).

---

## 🧠 **Dynamic Programming Approach (Bottom-Up)**

The idea:
> Break the problem into subproblems — the best value achievable with a given weight and item list — and build it up in a table.

### ✅ DP Table Definition:

Let `dp[i][w]` = maximum value we can get using the **first i items** with a max weight limit of **w**.

---

## 📋 Step-by-Step Algorithm

```cpp
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i-1] <= w) {
                // Option 1: Include this item
                int include = values[i-1] + dp[i-1][w - weights[i-1]];
                // Option 2: Don't include this item
                int exclude = dp[i-1][w];
                dp[i][w] = max(include, exclude);
            } else {
                // Cannot include item
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][W]; // Max value with n items and weight limit W
}
```

---

### 📊 Example:

```cpp
weights = [1, 3, 4, 5]
values  = [1, 4, 5, 7]
W = 7
```

Output: **9** (pick items 2 and 4: 4 + 5 = 9)

---

## 🧠 Key Concepts Your Prof Might Test:

| Concept | Explanation |
|--------|-------------|
| **Overlapping Subproblems** | Sub-solutions (like best value for weight 3) are reused |
| **Optimal Substructure** | The optimal solution is made from optimal solutions of subproblems |
| **Table-building** | Use bottom-up iteration to fill a table from small to large problems |
| **Choices** | At each step, choose to include the item or skip it |

---

## ⏱️ Time & Space Complexity

- **Time:** \( O(nW) \)  
- **Space:** \( O(nW) \) → can be optimized to \( O(W) \) using 1D DP

---

Let me know if you want to try a problem or go over the **space-optimized version**!

  -Dynamic Programming uses mathematical induction, the function OPT(), in this problem knapsack, this
function will maximize the profit it will pick a subset from all items to max profit

Absolutely — let's go **line-by-line** and **concept-by-concept** so you understand this deeply. This is a standard **bottom-up Dynamic Programming** implementation of the **0/1 Knapsack Problem**.

---

### 🔍 Function Header:

```cpp
int knapsack(int W, vector<int>& weights, vector<int>& values, int n)
```

- `W`: total **weight capacity** of the knapsack  
- `weights`: list of weights for the `n` items  
- `values`: list of values for the `n` items  
- `n`: number of items

---

### 🧠 Goal:

Build a table `dp[i][w]` where:
- `i` = number of items considered so far
- `w` = current weight capacity being tested
- `dp[i][w]` = **max value** that can be achieved with the **first `i` items** and a **weight limit `w`**

---

### 🔧 Initialization:

```cpp
vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
```

- Create a 2D DP table of size `(n+1) x (W+1)`
- All entries are initialized to 0  
- We do this so `dp[0][*]` and `dp[*][0]` are already base cases:
  - With 0 items or 0 weight, max value is 0

---

### 🔁 Loop through items and weights:

```cpp
for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
```

- `i = 1` to `n`: We're evaluating items one-by-one  
- `w = 0` to `W`: For each item, we test every possible weight capacity

---

### 🧮 Decision Logic (Core of DP):

```cpp
if (weights[i-1] <= w) {
```

Check if we **can include** the current item (item `i-1` because `weights` is 0-indexed).  
If the item's weight is **less than or equal** to the current capacity `w`, we have a choice:

#### 🅰️ **Option 1: Include the item**
```cpp
int include = values[i-1] + dp[i-1][w - weights[i-1]];
```
- Take the current item's value `values[i-1]`
- Add the best value you can get with the **remaining weight**
- Remaining weight = `w - weights[i-1]`
- We look at the row above (`i-1`) because we only use each item once (0/1)

#### 🅱️ **Option 2: Exclude the item**
```cpp
int exclude = dp[i-1][w];
```
- Don’t take the item. Just inherit the value from the row above.

#### ✅ Choose the best:
```cpp
dp[i][w] = max(include, exclude);
```

---

### ❌ If the item is too heavy:

```cpp
} else {
    dp[i][w] = dp[i-1][w];
}
```

- If the item's weight is more than the current capacity, we can't include it. So just carry over the previous best value.

---

### 🏁 Return final answer:

```cpp
return dp[n][W];
```

This is the bottom-right cell of the table:
- The best value we can get with `n` items and weight `W`

---

### 📊 Visualization (Simplified):

Suppose:
```cpp
weights = [1, 3, 4]
values  = [15, 20, 30]
W = 4
```

Then `dp` would look something like this:

| i \ w | 0 | 1 | 2 | 3 | 4 |
|-------|---|----|----|----|----|
| 0     | 0 |  0 |  0 |  0 |  0 |
| 1     | 0 | 15 | 15 | 15 | 15 |
| 2     | 0 | 15 | 15 | 20 | 35 |
| 3     | 0 | 15 | 15 | 20 | 35 |

You can trace how each value is chosen based on whether it includes the item or not.

---

### 🧠 Summary of Key Concepts:

- You're **breaking the problem** into subproblems: best value for every (item count, weight limit) combo
- You're **building solutions bottom-up**, avoiding recursion
- At each step, you're asking: *Should I include this item or not?*
- The final answer is built up in the `dp` table — no repeated calculations

---

Let me know if you want to go through this with an actual trace step-by-step with values, or implement the space-optimized 1D version!
