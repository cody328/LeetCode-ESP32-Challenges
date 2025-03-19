#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the function as always_inline to encourage the compiler to inline it
static inline bool isPalindrome(int x) __attribute__((always_inline));

static inline bool isPalindrome(int x) {
    // Negative numbers, or positive numbers ending in 0 (except 0 itself), are not palindromic.
    if (x < 0 || (x != 0 && x % 10 == 0)) {
        return false;
    }
    
    int rev = 0;
    // Reverse half of the number.
    // The loop stops when the original number is less than or equal to the reversed half.
    while (x > rev) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    
    // If the number has even digits, x should equal rev.
    // If it has odd digits, disregarding the middle digit (by dividing rev by 10) should make them equal.
    return (x == rev || x == rev / 10);
}


int app_main() {
    int testCases[] = {121, -121, 10, 12321, 0};
    int nCases = sizeof(testCases) / sizeof(testCases[0]);
    for (int i = 0; i < nCases; i++) {
        printf("isPalindrome(%d) = %s\n", testCases[i], isPalindrome(testCases[i]) ? "true" : "false");
    }
    return 0;
}
