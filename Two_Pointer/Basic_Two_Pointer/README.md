# 🟢 Basic Two Pointer

## 🧠 Pattern

Use two pointers without maintaining a window.

## 🎯 When to Use

* Sorted arrays
* Pair problems
* Partitioning problems

---

## 💡 Key Idea

Move pointers based on condition.

---

## 🧩 Template

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

## 📌 Problems

* Two Sum (Sorted Array)
* Sort 0s 1s 2s (Dutch National Flag)
