# 🚀 2D Prefix Sum Pattern

This section focuses on solving **matrix (2D array) problems efficiently** using **2D Prefix Sum**.

---

## 🧠 Why 2D Prefix Sum?

In matrix problems, we often need:

* Sum of a submatrix
* Multiple range queries
* Optimized rectangle-based computations

👉 Brute force → **O(n² * m²)**
👉 Using 2D Prefix Sum → **O(1) per query**

---

## ⚡ Core Idea

We preprocess the matrix such that each cell stores:

```cpp
prefix[i][j] = sum of all elements from (0,0) to (i,j)
```

---

## 🔑 Key Formula

### 📌 Submatrix Sum (Important)

To find sum of rectangle:

```
(x1, y1) → top-left  
(x2, y2) → bottom-right
```

```cpp id="k3df91"
sum = prefix[x2][y2] 
    - prefix[x1-1][y2] 
    - prefix[x2][y1-1] 
    + prefix[x1-1][y1-1]
```

👉 This is **Inclusion-Exclusion Principle**

---

## 🧩 Problems in this Folder

| 📄 File                            | 🧩 Problem                             |
| ---------------------------------- | -------------------------------------- |
| `range_sum_query_2D.cpp`           | Range Sum Query 2D (LC-304)            |
| `matrix_block_sum.cpp`             | Matrix Block Sum (LC-1314)             |
| `count_submatrices_with_sum_k.cpp` | Count Submatrices with Sum K (LC-1074) |
| `max_sum_rectangle.cpp`            | Maximum Sum Rectangle (GFG)            |

---

## 🎯 Pattern Recognition

| 🔍 If Problem Says   | 💡 Use                             |
| -------------------- | ---------------------------------- |
| Sum of submatrix     | 2D Prefix Sum                      |
| Multiple queries     | Precompute prefix                  |
| Fixed size block sum | Sliding + prefix                   |
| Submatrix with sum K | Prefix + Hashing (row compression) |
| Max rectangle sum    | Kadane + Prefix                    |

---

## 🧮 How to Build 2D Prefix Sum

```cpp id="y8sk21"
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        prefix[i][j] = matrix[i][j];

        if(i > 0) prefix[i][j] += prefix[i-1][j];
        if(j > 0) prefix[i][j] += prefix[i][j-1];
        if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
    }
}
```

---

## 🧮 Query in O(1)

```cpp id="j3p0sd"
int getSum(int x1, int y1, int x2, int y2) {
    int sum = prefix[x2][y2];

    if(x1 > 0) sum -= prefix[x1-1][y2];
    if(y1 > 0) sum -= prefix[x2][y1-1];
    if(x1 > 0 && y1 > 0) sum += prefix[x1-1][y1-1];

    return sum;
}
```

---

## 🏁 Complexity

| Type            | Value        |
| --------------- | ------------ |
| ⏱ Preprocessing | **O(n × m)** |
| ⚡ Query Time    | **O(1)**     |
| 🧠 Space        | **O(n × m)** |

---

## 🔥 Pro Tips (Striver Style)

* 2D Prefix = Extension of 1D Prefix
* Always remember **inclusion-exclusion**
* Watch out for **boundary conditions (i-1, j-1)**
* Use **0-based vs 1-based indexing carefully**

---

## 🚀 Advanced Insight

💡 Some problems combine:

* **2D Prefix + Hashing** (LC-1074)
* **2D Prefix + Kadane** (Max rectangle sum)

👉 These are **interview favorites**


💡 Master this = You unlock **matrix + grid based problems in interviews**
