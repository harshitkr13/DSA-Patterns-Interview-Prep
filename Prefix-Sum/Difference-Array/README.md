# 🚀 Difference Array Pattern

This section focuses on solving **range update problems efficiently** using the **Difference Array technique**.

---

## 🧠 Why Difference Array?

In many problems, we need to:

* Perform **multiple range updates**
* Add a value to all elements in a range `[l, r]`

👉 Brute force → **O(n × q)**
👉 Difference Array → **O(n + q)**

---

## ⚡ Core Idea

Instead of updating all elements in a range, we mark changes at boundaries.

### 📌 Key Concept:

```cpp id="7k1m4c"
diff[l] += val
diff[r + 1] -= val
```

👉 After processing all queries, take **prefix sum of diff[]** to get final array

---

## 🔑 How It Works

### Step 1️⃣ Initialize Difference Array

```cpp id="1z9n7s"
vector<int> diff(n, 0);
```

---

### Step 2️⃣ Apply Range Updates

For each query `[l, r, val]`:

```cpp id="n5r8px"
diff[l] += val;

if(r + 1 < n) {
    diff[r + 1] -= val;
}
```

---

### Step 3️⃣ Build Final Array

```cpp id="m2q4vt"
vector<int> result(n);
result[0] = diff[0];

for(int i = 1; i < n; i++) {
    result[i] = result[i-1] + diff[i];
}
```

---

## 🧩 Problems in this Folder

| 📄 File                         | 🧩 Problem                          |
| ------------------------------- | ----------------------------------- |
| `range_addition.cpp`            | Range Addition (LC-370)             |
| `car_pooling.cpp`               | Car Pooling (LC-1094)               |
| `corporate_flight_bookings.cpp` | Corporate Flight Bookings (LC-1109) |

---

## 🎯 Pattern Recognition

| 🔍 If Problem Says             | 💡 Use            |
| ------------------------------ | ----------------- |
| Multiple range updates         | Difference Array  |
| Add value in range             | Mark boundaries   |
| Capacity / bookings            | Prefix after diff |
| Increment/decrement operations | Diff array        |

---

## 🧮 General Template (C++)

```cpp id="0y9x6d"
vector<int> diff(n, 0);

// Apply queries
for(auto &q : queries) {
    int l = q[0], r = q[1], val = q[2];

    diff[l] += val;
    if(r + 1 < n) diff[r + 1] -= val;
}

// Build final array
vector<int> result(n);
result[0] = diff[0];

for(int i = 1; i < n; i++) {
    result[i] = result[i-1] + diff[i];
}
```

---

## 🏁 Complexity

| Type     | Value        |
| -------- | ------------ |
| ⏱ Time   | **O(n + q)** |
| 🧠 Space | **O(n)**     |

---

## 🔥 Pro Tips (Striver Style)

* Difference array = **Inverse of prefix sum idea**
* Always:

  * Mark start (`+val`)
  * Mark end+1 (`-val`)
* Final answer comes after **prefix sum**

---

## 🚀 Problem Insights

### 🔹 Range Addition (LC-370)

* Direct application of difference array

---

### 🔹 Car Pooling (LC-1094)

* Treat trips as range updates
* Check if capacity exceeds

---

### 🔹 Corporate Flight Bookings (LC-1109)

* Booking ranges → apply diff
* Build final passenger count


💡 Master this pattern = You can solve **range update problems in O(n)** instead of brute force
