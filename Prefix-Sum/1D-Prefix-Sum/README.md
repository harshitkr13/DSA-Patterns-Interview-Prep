# 🚀 1D Prefix Sum Pattern

Prefix Sum is a powerful technique used to optimize range queries and subarray problems.

---

## 🧠 What is Prefix Sum?

Prefix Sum stores cumulative sum up to index `i`.

👉 Formula:

prefix[i] = arr[0] + arr[1] + ... + arr[i]

---

## ⚡ Why Use Prefix Sum?

✔ Convert **O(n²) → O(n)**  
✔ Fast range sum queries  
✔ Avoid recomputation  

---

## 🧩 Basic Idea

Once prefix array is built:

👉 Sum of subarray `[L, R]` =  prefix[R] - prefix[L - 1]


---

## 📌 1. Build Prefix Sum Array

### 🧩 Template Code:

```cpp
vector<int> buildPrefix(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);

    prefix[0] = arr[0];

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    return prefix;
}

```
🧩 Template Code:
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;

    int sum = 0, count = 0;

    for(int x : nums) {
        sum += x;

        if(mp.find(sum - k) != mp.end()) {
            count += mp[sum - k];
        }

        mp[sum]++;
    }

    return count;
}
```
