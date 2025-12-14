# 🚚 Delivery Management System (C++)

A **console-based Delivery Management System** built using **C++ and linked list data structures**.
This project manages delivery orders efficiently by allowing users to add, cancel, reschedule, and display deliveries using a **menu-driven interface**.

---

## 🚀 Features

* ➕ Add new delivery orders with **unique Order IDs**
* ❌ Cancel delivery using **Order ID**
* 🔁 Reschedule deliveries using **Order ID–based repositioning**
* 📋 Display all pending deliveries
* 🧭 Menu-driven interface with safe input handling
* 🛑 Prevents crashes on invalid or duplicate inputs

---

## 🛠️ Tech Stack

* **Language:** C++
* **Data Structure:** Singly Linked List
* **Paradigm:** Procedural + Object-Oriented
* **Compiler:** GCC / MinGW / Clang
* **Platform:** Console / Terminal

---

## 🧠 Concepts Used

* Linked List (Node insertion, deletion, traversal)
* Pointer manipulation
* Dynamic memory allocation (`new` / `delete`)
* Input validation using `cin.fail()`
* Menu-driven program design
* Edge-case handling (empty list, duplicate IDs, invalid rescheduling)

---

## 📂 Project Structure

```
Delivery-Management-System/
│
├── src/main.cpp          # Source code
├── .gitignore
└── README.md             # Project documentation
```

*(File names may vary depending on implementation)*

---

## ▶️ How to Run

1. **Clone the repository**

```bash
git clone https://github.com/DragonC-der/Delivery-Management-System.git
```

2. **Navigate to the project folder**

```bash
cd Delivery-Management-System
```

3. **Compile the code**

```bash
g++ main.cpp -o delivery
```

4. **Run the program**

```bash
./delivery
```

---

## 🧪 Test Case (Dry Run)

### Input Scenario

Add **4 delivery orders**:

| SN | Order ID | Customer Name | Address  |
| -- | -------- | ------------- | -------- |
| 1  | A101     | a1            | a        |
| 2  | A102     | b1            | b        |
| 3  | A103     | c1            | c        |
| 4  | A104     | d1            | d        |

### Operations Performed

1. Cancel order with **Order ID A102**
2. Reschedule **A101** to come after **A103**
3. Display records after each operation

### Expected Behavior

✔ Order A102 is removed
✔ A101 is repositioned correctly
✔ Linked list order remains consistent
✔ No memory leaks or invalid access

---

## 📌 Sample Menu Output

```
1. Add order
2. Cancel order
3. Show deliveries
4. Reschedule delivery (by Order ID)
5. Exit
Choose:
```

---

⭐ If you find this project helpful, consider **starring the repository**!

---