# 9. Palindrome Number

## Problem Statement

Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.

A **palindrome** number is a number that reads the same backward as forward. For instance, `121` is a palindrome because it remains the same when its digits are reversed.

**Follow-Up:**  
Could you solve it without converting the integer to a string?

---

## Constraints

- `-2^31 <= x <= 2^31 - 1`

---

## Example 1

**Input:**  
`x = 121`

**Output:**  
`true`

**Explanation:**  
`121` reads as `121` from left to right and from right to left.

---

## Example 2

**Input:**  
`x = -121`

**Output:**  
`false`

**Explanation:**  
From left to right, it reads `-121`. Reversed, it becomes `121-`, which is not the same. Therefore, it is not a palindrome.

---

## Example 3

**Input:**  
`x = 10`

**Output:**  
`false`

**Explanation:**  
Reading `10` backward gives `01`. Since `01` is not equal to `10`, it is not a palindrome.

## Test Cases

**Test Case 1:**  
- **Input:** `121`  
- **Expected Output:** `true`

**Test Case 2:**  
- **Input:** `-121`  
- **Expected Output:** `false`

**Test Case 3:**  
- **Input:** `10`  
- **Expected Output:** `false`
