#include <stdio.h>
#include <stdio.h>

// Aggressively unrolled and optimized version.
// Compile with -O3 for maximum effect.
static inline int __attribute__((always_inline)) minOperations(const int* nums, int n) {
    const int k = 3;
    int op = 0, flip = 0;
    // Use dedicated diff variables for the cyclic window.
    int diff0 = 0, diff1 = 0, diff2 = 0;
    int i = 0;

    // Process in blocks of 3 iterations.
    for (; i <= n - 3; i += 3) {
        // First iteration (i)
        if (i >= 3) {
            // At i (which is a multiple of 3), remove effect from diff0.
            flip -= diff0;
        }
        int effective0 = nums[i] ^ (flip & 1);
        if (__builtin_expect(effective0 == 0, 0)) {
            // Not enough elements remaining check (should almost never trigger in unrolled blocks)
            if (__builtin_expect(i > n - k, 0)) return -1;
            op++;
            flip++;
            diff0 = 1;
        } else {
            diff0 = 0;
        }

        // Second iteration (i+1)
        // Always true for i+1 >= 3 when i >= 2.
        flip -= diff1;  // Use diff1 for second position.
        int effective1 = nums[i + 1] ^ (flip & 1);
        if (__builtin_expect(effective1 == 0, 0)) {
            if (__builtin_expect(i + 1 > n - k, 0)) return -1;
            op++;
            flip++;
            diff1 = 1;
        } else {
            diff1 = 0;
        }

        // Third iteration (i+2)
        flip -= diff2;  // Use diff2 for third position.
        int effective2 = nums[i + 2] ^ (flip & 1);
        if (__builtin_expect(effective2 == 0, 0)) {
            if (__builtin_expect(i + 2 > n - k, 0)) return -1;
            op++;
            flip++;
            diff2 = 1;
        } else {
            diff2 = 0;
        }
    }

    // Process any remaining elements.
    for (; i < n; i++) {
        int mod = i % 3;
        if (i >= 3) {
            if (mod == 0)
                flip -= diff0;
            else if (mod == 1)
                flip -= diff1;
            else
                flip -= diff2;
        }
        int effective = nums[i] ^ (flip & 1);
        if (effective == 0) {
            if (i > n - k)
                return -1;
            op++;
            flip++;
            if (mod == 0)
                diff0 = 1;
            else if (mod == 1)
                diff1 = 1;
            else
                diff2 = 1;
        } else {
            if (mod == 0)
                diff0 = 0;
            else if (mod == 1)
                diff1 = 0;
            else
                diff2 = 0;
        }
    }
    return op;
}

int app_main(void) {
    int arr1[] = {0, 1, 1, 1, 0, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int res1 = minOperations(arr1, n1);
    printf("Test Case 1: Output = %d (Expected: 3)\n", res1);

    int arr2[] = {0, 1, 1, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int res2 = minOperations(arr2, n2);
    printf("Test Case 2: Output = %d (Expected: -1)\n", res2);

    return 0;
}
