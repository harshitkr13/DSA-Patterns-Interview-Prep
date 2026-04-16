# 🚀 Prefix Sum with Hashing

This section focuses on solving **subarray problems efficiently using Prefix Sum + HashMap**.

---

## 🧠 Why Prefix Sum + Hashing?

Many subarray problems involve:

* Sum = K
* Count of subarrays
* Longest subarray
* Special conditions (equal 0s & 1s, divisible by K)

👉 Brute force takes **O(n²)**
👉 Using this pattern reduces it to **O(n)**

---

## ⚡ Core Idea

We combine:

* 📌 **Prefix Sum** → Running cumulative sum
* 📌 **HashMap (`unordered_map`)** → Store:

  * Frequency (for counting)
  * First occurrence (for longest length)

---

## 🔑 Key Observations

### 📌 1. Subarray Sum Formula

```cpp
sum(i, j) = prefix[j] - prefix[i]
```

---

### 📌 2. When Sum = K

```cpp
prefix[j] - prefix[i] = K
⇒ prefix[i] = prefix[j] - K
```

👉 Check if `(current_sum - K)` exists in map

---

### 📌 3. Divisible by K

```cpp
prefix[j] % K == prefix[i] % K
```

👉 Same remainder ⇒ valid subarray

---

### 📌 4. Longest Subarray

* Store **first occurrence** of prefix sum
* Maximize length `(j - i)`

---

### 📌 5. Count Subarrays

* Store **frequency** of prefix sum
* Add frequency when condition matches

---

## 🧩 Problems in this Folder

| 📄 File                                | 🧩 Problem                                 |
| -------------------------------------- | ------------------------------------------ |
| `subarray_sum_equals_k.cpp`            | Subarray Sum Equals K (LC-560)             |
| `longest_subarray_sum_k.cpp`           | Longest Subarray with Sum K (GFG)          |
| `count_subarrays_divisible_by_k.cpp`   | Count Subarrays Divisible by K (LC-974)    |
| `count_subarrays_with_equal_0s_1s.cpp` | Count Subarrays with Equal 0s and 1s (GFG) |
| `largest_subarray_with_0_sum.cpp`      | Largest Subarray with 0 Sum (GFG)          |

---

## 🎯 Pattern Recognition

| 🔍 If Problem Says | 💡 Use               |
| ------------------ | -------------------- |
| Count subarrays    | Frequency map        |
| Longest subarray   | First occurrence map |
| Equal 0s & 1s      | Convert `0 → -1`     |
| Divisible by K     | Modulo logic         |

---

## 🧮 General Template (C++)

```cpp
unordered_map<int, int> mp;
mp[0] = 1; // important for edge case

int sum = 0, count = 0;

for(int i = 0; i < n; i++) {
    sum += arr[i];

    // Example: sum = K
    if(mp.find(sum - k) != mp.end()) {
        count += mp[sum - k];
    }

    mp[sum]++;
}
```

---

## 🏁 Complexity

* ⏱ **Time:** O(n)
* 🧠 **Space:** O(n)

---

## 🔥 Pro Tip 

Whenever you see:

* "Subarray"
* "Sum = K"
* "Longest / Count"

👉 Immediately think:

**Prefix Sum + HashMap**


💡 Master this folder = You unlock **most medium-level array problems in interviews**
