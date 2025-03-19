# 3191. Minimum Operations to Make Binary Array Elements Equal to One I

**Status:** Solved  
**Difficulty:** Medium  
**Topics:** Array, Simulation, Greedy  
**Acceptance:** (Not provided)

---

## Problem Statement

You are given a binary array `nums`.

You can perform the following operation on the array any number of times (possibly zero):

- **Operation:** Choose any 3 consecutive elements from the array and flip all of them.  
  Flipping an element changes its value from `0` to `1` and from `1` to `0`.

Return the minimum number of operations required to make all elements of `nums` equal to `1`.  
If it is impossible to achieve this, return `-1`.

---

## Examples

### Example 1

**Input:**  
```
nums = [0,1,1,1,0,0]
```

**Output:**  
```
3
```

**Explanation:**  
- Operation 1: Flip elements at indices 0,1,2 → `nums = [1,0,0,1,0,0]`
- Operation 2: Flip elements at indices 1,2,3 → `nums = [1,1,1,0,0,0]`
- Operation 3: Flip elements at indices 3,4,5 → `nums = [1,1,1,1,1,1]`

### Example 2

**Input:**  
```
nums = [0,1,1,1]
```

**Output:**  
```
-1
```

**Explanation:**  
It is impossible to flip to all ones because at least one operation would overlap out-of-bound indices.

---

## Constraints

- `3 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.

---

## Test Cases

- **Test Case 1:**  
  - **Input:** `nums = [0,1,1,1,0,0]`  
  - **Expected Output:** `3`

- **Test Case 2:**  
  - **Input:** `nums = [0,1,1,1]`  
  - **Expected Output:** `-1`

---

## Test Results

The solution was tested locally with the above cases and produced the following outputs:

- For `[0,1,1,1,0,0]`: **Output: 3**
- For `[0,1,1,1]`: **Output: -1**

These results match the expected outputs, confirming the correctness and efficiency of the solution.
