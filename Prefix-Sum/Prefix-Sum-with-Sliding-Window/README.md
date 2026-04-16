# 🚀 Prefix Sum + Sliding Window Pattern

This section focuses on solving **subarray problems using a combination of Prefix Sum logic and Sliding Window (Two Pointers)**.

---

## 🧠 Why This Pattern?

Some problems:

* Cannot be solved using only prefix sum
* Cannot be solved using only sliding window

👉 But combining both gives an optimal **O(n)** solution

---

## ⚡ Core Idea

We use:

* 📌 **Sliding Window** → To maintain valid subarrays
* 📌 **Prefix Sum Insight** → To transform problems into countable forms

---

## 🔑 Key Trick (VERY IMPORTANT)

### 🎯 Convert "EXACTLY K" → "AT MOST K"

Most problems ask:

* Count subarrays with **exactly K**

👉 Hard to compute directly

Instead use:

```
Exactly(K) = AtMost(K) - AtMost(K - 1)
```

🔥 This is the **core trick of this folder**

---

## 🧩 Problems in this Folder

| 📄 File                         | 🧩 Problem                                  |
| ------------------------------- | ------------------------------------------- |
| `binary_subarrays_with_sum.cpp` | Binary Subarrays With Sum (LC-930)          |
| `nice_subarrays.cpp`            | Count Number of Nice Subarrays (LC-1248)    |
| `subarrays_with_k_distinct.cpp` | Subarrays with K Distinct Integers (LC-992) |

---

## 🎯 Pattern Recognition

| 🔍 If Problem Says    | 💡 Approach                 |
| --------------------- | --------------------------- |
| Exactly K sum / count | Use AtMost(K) - AtMost(K-1) |
| Binary array + sum    | Sliding window              |
| Count odds / evens    | Transform array             |
| K distinct elements   | Frequency map + window      |

---

## 🧮 General Template (At Most K)

```
int atMostK(vector<int>& nums, int k) {
    int left = 0, count = 0;
    unordered_map<int, int> mp;

    for(int right = 0; right < nums.size(); right++) {
        mp[nums[right]]++;

        while(mp.size() > k) {
            mp[nums[left]]--;
            if(mp[nums[left]] == 0) mp.erase(nums[left]);
            left++;
        }

        count += (right - left + 1);
    }

    return count;
}
```

---

## 🧮 Final Answer Pattern

```
answer = atMostK(k) - atMostK(k - 1);
```

---

## 🏁 Complexity

| Type     | Value    |
| -------- | -------- |
| ⏱ Time   | **O(n)** |
| 🧠 Space | **O(n)** |

---

## 🔥 Pro Tips (Striver Style)

* Sliding window works best when:

  * Elements are **positive / constrained**
* Always think:

  * ❓ Can I convert this to **AtMost K**?

---

## 🚀 Problem Insights

### 🔹 Binary Subarrays With Sum (LC-930)

* Use prefix OR sliding window
* Binary nature makes window valid

---

### 🔹 Nice Subarrays (LC-1248)

* Convert:

```
odd → 1  
even → 0
```

* Then same as binary sum problem

---

### 🔹 Subarrays with K Distinct (LC-992)

* Use:

  * HashMap + Sliding Window
* Apply:

```
Exactly(K) = AtMost(K) - AtMost(K-1)
```

💡 Master this pattern = You unlock **advanced sliding window problems in interviews**
