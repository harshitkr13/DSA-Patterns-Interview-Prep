# 🟣 Minimum Window Pattern

## 🧠 Pattern

Find smallest valid window.

---

## 🎯 When to Use

* Minimum substring / subarray problems

---

## 💡 Key Idea

Once valid → shrink aggressively.

---

## 🧩 Template

```cpp
while(valid_condition){
    update_answer;
    remove(arr[left]);
    left++;
}
```

---

## 📌 Problems

* Minimum Window Substring
* Minimum Window Subsequence
