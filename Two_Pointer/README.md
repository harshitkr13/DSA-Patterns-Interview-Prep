# 🚀 Two Pointer / Sliding Window Pattern

Master one of the most powerful DSA patterns used in interviews.

---

## 🧠 What is Two Pointer?

Two pointers (L & R) help you efficiently traverse arrays/strings while maintaining a **window**.

* `L` → Left pointer (start of window)
* `R` → Right pointer (end of window)

---

# 📌 1. Constant Window Pattern

### 🎯 Problem Type:

* Fixed window size `k`
* Example: Maximum sum of subarray of size `k`

### ⚙️ Technique:

* Build initial window of size `k`
* Slide window:

  * Remove left element
  * Add next right element

### 💡 Key Idea:

> **Fixed size → Just slide**

---

### 🧩 Template Code:

```cpp
int maxSum(vector<int>& arr, int k) {
    int n = arr.size();
    int sum = 0;

    // Step 1: initial window
    for(int i = 0; i < k; i++) {
        sum += arr[i];
    }

    int maxSum = sum;

    // Step 2: slide window
    for(int i = k; i < n; i++) {
        sum += arr[i];       // add next
        sum -= arr[i - k];   // remove left
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}
```

---

# 📌 2. Longest Subarray / Substring with Condition ⭐ (MOST IMPORTANT)

### 🎯 Problem Type:

* Longest window satisfying condition
* Example: Longest subarray with sum ≤ k

---

### ⚙️ Core Behavior:

| Action       | Meaning               |
| ------------ | --------------------- |
| Expand (R++) | Try to improve answer |
| Shrink (L++) | Fix invalid window    |

---

### 💡 Key Idea:

> **Expand when valid, shrink when invalid**

---

### 🧩 Template Code:

```cpp
int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    int l = 0, sum = 0, maxLen = 0;

    for(int r = 0; r < n; r++) {
        sum += arr[r];

        // shrink if invalid
        while(sum > k) {
            sum -= arr[l];
            l++;
        }

        // update answer
        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}
```

---

### ⏱ Complexity:

* **Time:** O(n)
* **Space:** O(1)

---

# 📌 3. Count Number of Subarrays with Condition

### 🎯 Problem Type:

* Count subarrays (not longest/shortest)
* Example: Subarrays with sum = k

---

### ⚙️ Trick Used:

Convert:

```
count(sum = k) = count(sum ≤ k) - count(sum ≤ k - 1)
```

---

### 💡 Key Idea:

> **Counting problems → Reduce to ≤ condition**

---

### 🧩 Template Code:

```cpp
int countSubarrays(vector<int>& arr, int k) {
    return helper(arr, k) - helper(arr, k - 1);
}

int helper(vector<int>& arr, int k) {
    int l = 0, sum = 0, count = 0;

    for(int r = 0; r < arr.size(); r++) {
        sum += arr[r];

        while(sum > k) {
            sum -= arr[l];
            l++;
        }

        count += (r - l + 1);
    }

    return count;
}
```

---

# 📌 4. Minimum / Shortest Window Pattern

### 🎯 Problem Type:

* Smallest window satisfying condition
* Example: Minimum window substring

---

### ⚙️ Approach:

1. Expand until valid
2. Shrink as much as possible

---

### 💡 Key Idea:

> **Once valid → shrink aggressively**

---

### 🧩 Template Code:

```cpp
int minWindow(vector<int>& arr, int k) {
    int l = 0, sum = 0;
    int minLen = INT_MAX;

    for(int r = 0; r < arr.size(); r++) {
        sum += arr[r];

        while(sum >= k) {
            minLen = min(minLen, r - l + 1);
            sum -= arr[l];
            l++;
        }
    }

    return (minLen == INT_MAX) ? -1 : minLen;
}
```

---

# 🔥 Quick Summary Table

| Pattern          | Goal       | Window Behavior              |
| ---------------- | ---------- | ---------------------------- |
| Constant Window  | Fixed size | Slide only                   |
| Longest Subarray | Max length | Expand + shrink              |
| Count Subarrays  | Count      | Derived from pattern 2       |
| Minimum Window   | Min length | Expand → shrink aggressively |

---

# 🧠 Final Intuition (Golden Rule)

```
If window invalid → shrink
If window valid → update answer
```

---

# 🚀 Practice Problems

* Maximum Sum Subarray of Size K
* Longest Substring Without Repeating Characters
* Number of Subarrays with Sum K
* Minimum Window Substring

---

# ⭐ Pro Tip

Most problems are just variations of:
👉 **Longest OR Count OR Minimum**

Once you master Pattern 2 → You unlock 70% of problems 🔓

---

Happy Coding 💻🔥
