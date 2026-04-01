# 🚀 Two Pointer & Sliding Window Pattern

Master one of the most important patterns for coding interviews.

---

## 🧠 What is Two Pointer / Sliding Window?

* Use two pointers (`L`, `R`) to maintain a **window**
* Helps convert **O(n²) → O(n)**

👉 Works best for:

* Arrays / Strings
* Subarrays / Substrings
* Contiguous segments

---

## 🎯 When to Use?

* Longest / shortest subarray
* Count of subarrays
* Fixed-size window problems
* Sorted arrays (two pointer)

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

> Fixed size → Just slide

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

# 📌 2. Longest Subarray / Substring ⭐ (MOST IMPORTANT)

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

> Expand when valid, shrink when invalid

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

* Time: O(n)
* Space: O(1)

---

# 📌 3. Count Number of Subarrays

### 🎯 Problem Type:

* Count subarrays (not longest/shortest)
* Example: Subarrays with sum = k

---

### ⚙️ Trick Used:

```
count(sum = k) = count(sum ≤ k) - count(sum ≤ k - 1)
```

---

### 💡 Key Idea:

> Counting problems → Reduce to ≤ condition

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

* Expand until valid
* Shrink as much as possible

---

### 💡 Key Idea:

> Once valid → shrink aggressively

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

# 📌 5. Basic Two Pointer (Sorted Array)

### 🎯 Problem Type:

* Pair problems
* Example: Two Sum (sorted array)

### 💡 Key Idea:

> Move pointer based on condition

---

### 🧩 Template:

```cpp
int left = 0, right = n - 1;

while(left < right){
    if(condition){
        left++;
    } else {
        right--;
    }
}
```

---

# 📌 6. Opposite Direction Pointer

### 🎯 Problem Type:

* Start from both ends
* Example: Container With Most Water

### 💡 Key Idea:

> Move the limiting pointer

---

### 🧩 Template:

```cpp
int left = 0, right = n - 1;

while(left < right){
    if(arr[left] < arr[right])
        left++;
    else
        right--;
}
```

---

# ⚠️ Special Cases

* Negative numbers → Sliding window may fail
* Use hashmap for duplicates
* Condition must be monotonic
* Carefully define invalid condition

---

# ❗ Common Mistakes

* Updating answer before fixing window
* Wrong shrink condition
* Infinite loop (`while` mistake)
* Confusing longest vs minimum logic

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
* Container With Most Water
* 3Sum

---

# 🎯 Goal

> Recognize pattern instantly → solve in O(n)
