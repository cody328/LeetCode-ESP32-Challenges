# 2. Add Two Numbers

## Problem Statement

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Constraints:**
- The number of nodes in each linked list is in the range \([1, 100]\).
- \(0 \leq \text{Node.val} \leq 9\)
- The lists represent a number that does not contain any leading zeros.

---

## Example Cases

### **Case 1**

- **Input:**
  - \(l1 = [2, 4, 3]\)
  - \(l2 = [5, 6, 4]\)

- **Explanation:**
  - These linked lists represent the numbers 342 and 465 (remember, the digits are stored in reverse order).
  - Their sum is \(342 + 465 = 807\).
  - Storing 807 in reverse gives \([7, 0, 8]\).

- **Output:**
  - \([7, 0, 8]\)

---

### **Case 2**

- **Input:**
  - \(l1 = [0]\)
  - \(l2 = [0]\)

- **Explanation:**
  - Both linked lists represent the number 0.
  - The sum is \(0 + 0 = 0\).

- **Output:**
  - \([0]\)

---

### **Case 3**

- **Input:**
  - \(l1 = [9, 9, 9, 9, 9, 9, 9]\)
  - \(l2 = [9, 9, 9, 9]\)

- **Explanation:**
  - The first list represents \(9,999,999\) and the second represents \(9,999\).
  - Their sum is \(9,999,999 + 9,999 = 10,009,998\).
  - In reverse order, this is represented as \([8, 9, 9, 9, 0, 0, 0, 1]\).

- **Output:**
  - \([8, 9, 9, 9, 0, 0, 0, 1]\)

---

## Detailed Explanation

The key idea in solving this problem is to simulate columnar addition, digit by digit, while handling the carry:

1. **Initialize Carry to Zero:**
   - Start from the head of both linked lists.
   
2. **Traverse Both Lists Simultaneously:**
   - For each node, calculate the **sum** of the corresponding digits and the **carry** from the previous addition.
   - For example, in **Case 1**:
     - **First Digit:** \(2 + 5 = 7\), with no carry → Node value: **7**.
     - **Second Digit:** \(4 + 6 = 10\). Write the digit \(0\) (i.e., \(10 \mod 10\)) and carry \(1\).
     - **Third Digit:** \(3 + 4 + 1 = 8\) → Write \(8\).
     
3. **Handle Unequal Lengths:**
   - If one list is longer than the other, treat missing nodes as \(0\).

4. **Add Final Carry if Necessary:**
   - After processing both lists, if there is a remaining carry, add an extra node with that value.
