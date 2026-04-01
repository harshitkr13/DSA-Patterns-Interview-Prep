# 🟠 Fixed Size Sliding Window

## 🧠 Pattern

Window size is constant.

---

## 🎯 When to Use

* Fixed size subarray problems

---

## 💡 Key Idea

Just slide the window.

---

## 🧩 Template

```cpp
for(int i = k; i < n; i++){
    add(arr[i]);
    remove(arr[i - k]);
}
```

---

## 📌 Problems

* Maximum Points You Can Obtain from Cards
