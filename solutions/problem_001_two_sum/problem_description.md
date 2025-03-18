# Problem: Two Sum

## **Difficulty**
Easy

---

## **Description**
Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to the target.

You may assume that:
- Each input would have exactly one solution.
- You may not use the same element twice.

The answer can be returned in any order.

---

## **Examples**

### Example 1:
**Input**:  
`nums = [2, 7, 11, 15]`  
`target = 9`  

**Output**:  
`[0, 1]`  

**Explanation**:  
`nums[0] + nums[1] == 9`. Therefore, return `[0, 1]`.

---

### Example 2:
**Input**:  
`nums = [3, 2, 4]`  
`target = 6`  

**Output**:  
`[1, 2]`

---

### Example 3:
**Input**:  
`nums = [3, 3]`  
`target = 6`  

**Output**:  
`[0, 1]`

---

## **Constraints**
- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Only one valid answer exists.

---

## **Follow-Up Challenge**
Can you come up with an algorithm that has a time complexity less than O(n²)?
