# 🚀 Prefix Sum Pattern

Prefix Sum is a powerful technique used to optimize range queries from **O(n)** to **O(1)**.

---

## 🧠 What is Prefix Sum?

Prefix sum stores cumulative sum up to index `i`.

```cpp
prefix[i] = arr[0] + arr[1] + ... + arr[i]
```

---

## 🎯 When to Use?

* Range sum queries
* Subarray sum problems
* When repeated summation is required
* Optimization of brute force

---

# 📌 1. Prefix Sum on 1D Array

---

## ⚙️ Construction

```cpp
vector<int> prefix(n);
prefix[0] = arr[0];

for(int i = 1; i < n; i++){
    prefix[i] = prefix[i-1] + arr[i];
}
```

---

## 📊 Range Sum Query

```cpp
sum(l, r) = prefix[r] - prefix[l-1]
```

👉 Edge case:

```cpp
if(l == 0) return prefix[r];
```

---

## 💡 Key Idea

> Precompute once → Answer queries in O(1)

---

## 🧩 Example

Array: `[2, 4, 6, 8]`

Prefix: `[2, 6, 12, 20]`

Query sum(1,3) → `20 - 2 = 18`

---

# 📌 2. Prefix Sum on 2D Array

---

## ⚙️ Construction

```cpp
vector<vector<int>> prefix(n, vector<int>(m, 0));

for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        prefix[i][j] = arr[i][j];

        if(i > 0) prefix[i][j] += prefix[i-1][j];
        if(j > 0) prefix[i][j] += prefix[i][j-1];
        if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
    }
}
```

---

## 📊 Submatrix Sum Query

```cpp
sum(r1,c1,r2,c2) = 
prefix[r2][c2]
- prefix[r1-1][c2]
- prefix[r2][c1-1]
+ prefix[r1-1][c1-1]
```

👉 Handle boundaries carefully.

---

## 💡 Key Idea

> Convert matrix queries → constant time using inclusion-exclusion

---

## 🧩 Example

Matrix:

```
1 2
3 4
```

Prefix:

```
1 3
4 10
```

---

# ⚠️ Common Mistakes

* Forgetting edge cases (`l = 0`)
* Wrong subtraction in 2D prefix
* Index out of bounds
* Not using long long (overflow)

---

# 🔥 Applications

* Subarray sum = K
* Range sum queries
* 2D matrix sum queries
* Difference array problems

---

# 🧠 Final Intuition

```
Repeated sum? → Use Prefix Sum
```

---

# 🎯 Goal

> Reduce time complexity from O(n²) → O(n) or O(1)
