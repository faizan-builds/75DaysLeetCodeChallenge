#include <stdio.h>
#include <string.h>

int characterReplacement(char* s, int k) {
    int freq[26] = {0};
    int left = 0, maxCount = 0, maxLength = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        // Update frequency
        freq[s[right] - 'A']++;

        // Track most frequent character in window
        if (freq[s[right] - 'A'] > maxCount)
            maxCount = freq[s[right] - 'A'];

        // If replacements needed > k, shrink window
        while ((right - left + 1) - maxCount > k) {
            freq[s[left] - 'A']--;
            left++;
        }

        // Update max length
        int windowSize = right - left + 1;
        if (windowSize > maxLength)
            maxLength = windowSize;
    }

    return maxLength;
}