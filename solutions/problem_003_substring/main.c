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
    printf("Example 1:\nInput: \"abcabcbb\"\nExpected output: 3\nActual output: %d\n\n",
        lengthOfLongestSubstring("abcabcbb"));
 
    printf("Example 2:\nInput: \"bbbbb\"\nExpected output: 1\nActual output: %d\n\n",
            lengthOfLongestSubstring("bbbbb"));
    
    printf("Example 3:\nInput: \"pwwkew\"\nExpected output: 3\nActual output: %d\n\n",
            lengthOfLongestSubstring("pwwkew"));
    
    printf("Edge case 1:\nInput: \"\"\nExpected output: 0\nActual output: %d\n\n",
            lengthOfLongestSubstring(""));
    
    printf("Edge case 2:\nInput: \"a\"\nExpected output: 1\nActual output: %d\n\n",
            lengthOfLongestSubstring("a"));
    
    return 0;
}
