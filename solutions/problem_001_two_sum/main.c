#include <stdlib.h>
#include <stdio.h>

// Define a struct for the hash map
typedef struct {
    int key;    // Number
    int value;  // Index
} HashNode;

// Hash function
int hash(int key, int size) {
    return (key % size + size) % size;  // Handle negative keys
}

// Two Sum implementation
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int capacity = numsSize * 2; // Hash table size
    HashNode* hashMap = (HashNode*)calloc(capacity, sizeof(HashNode));
    int* result = (int*)malloc(2 * sizeof(int));

    // Initialize hash table
    for (int i = 0; i < capacity; i++) {
        hashMap[i].key = 0x7FFFFFFF;  // Sentinel value for unused slot
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = hash(complement, capacity);

        // Linear probing to find the complement
        while (hashMap[index].key != 0x7FFFFFFF) {
            if (hashMap[index].key == complement) {
                result[0] = hashMap[index].value;
                result[1] = i;
                *returnSize = 2;
                free(hashMap);
                return result;
            }
            index = (index + 1) % capacity;
        }

        // Insert the current number into the hash table
        index = hash(nums[i], capacity);
        while (hashMap[index].key != 0x7FFFFFFF) {
            index = (index + 1) % capacity;
        }
        hashMap[index].key = nums[i];
        hashMap[index].value = i;
    }

    free(hashMap);
    *returnSize = 0;
    return NULL;  // No solution found
}
