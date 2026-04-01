# 🔵 Count Subarrays Pattern

## 🧠 Pattern

Derived from sliding window.

---

## 🎯 When to Use

* Counting subarrays / substrings

---

## ⚙️ Trick Used

count(k) = count(≤k) - count(≤k-1)

---

## 💡 Key Idea

Convert exact → at most.

---

## 🧩 Template

```cpp
count += (right - left + 1);
```

---

## 📌 Problems

* Binary Subarrays With Sum
* Count Number of Nice Subarrays
* Substrings with All Three Characters
* Subarrays with K Distinct
