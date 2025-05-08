#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    // Edge case: empty string
    if (!s || *s == '\0') return 0;
    
    int n = strlen(s);
    // Edge case: single character string
    if (n == 1) return 1;
    
    // Use an array to track the last position of each character
    // ASCII has 128 standard characters, but we'll use 256 to cover extended ASCII
    int lastPos[256];
    memset(lastPos, -1, sizeof(lastPos)); // Initialize all to -1 (not seen)
    
    int maxLength = 0;
    int start = 0; // Start of current substring
    
    for (int i = 0; i < n; i++) {
        // If this character was seen before and its last position is >= start
        if (lastPos[(unsigned char)s[i]] >= start) {
            // Move start to the position after the last occurrence
            start = lastPos[(unsigned char)s[i]] + 1;
        }
        
        // Update the last position of current character
        lastPos[(unsigned char)s[i]] = i;
        
        // Update max length if current substring is longer
        int currentLength = i - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }
    
    return maxLength;
}

int app_main() {
    // Test cases
    printf("Example 1: %d\n", lengthOfLongestSubstring("abcabcbb")); // Expected: 3
    printf("Example 2: %d\n", lengthOfLongestSubstring("bbbbb"));    // Expected: 1
    printf("Example 3: %d\n", lengthOfLongestSubstring("pwwkew"));   // Expected: 3
    printf("Edge case 1: %d\n", lengthOfLongestSubstring(""));       // Expected: 0
    printf("Edge case 2: %d\n", lengthOfLongestSubstring("a"));      // Expected: 1
    
    return 0;
}
