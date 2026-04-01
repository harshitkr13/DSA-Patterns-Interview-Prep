# 🟡 Variable Size Sliding Window ⭐

## 🧠 Pattern

Window expands and shrinks dynamically.

---

## 🎯 When to Use

* Longest substring / subarray
* At most / exactly K type problems

---

## ⚙️ Core Logic

| Action       | Meaning               |
| ------------ | --------------------- |
| Expand (R++) | Try to improve answer |
| Shrink (L++) | Fix invalid window    |

---

## 💡 Key Idea

Expand when valid, shrink when invalid.

---

## 🧩 Template

```cpp
int left = 0;

for(int right = 0; right < n; right++){
    add(arr[right]);

    while(invalid_condition){
        remove(arr[left]);
        left++;
    }

    update_answer;
}
```

---

## 📌 Problems

* Longest Substring Without Repeating Characters
* Longest Substring with K Distinct
* Fruit Into Baskets
* Max Consecutive Ones III
* Longest Repeating Character Replacement
