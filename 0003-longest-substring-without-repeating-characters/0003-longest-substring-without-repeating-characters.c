#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int maxLen = 0;

    int charSet[256] = {0}; // ASCII
    int left = 0;

    for (int right = 0; right < n; right++) {
        while (charSet[(unsigned char)s[right]] == 1) {
            charSet[(unsigned char)s[left]] = 0;
            left++;
        }

        charSet[(unsigned char)s[right]] = 1;

        int currentLen = right - left + 1;
        if (currentLen > maxLen)
            maxLen = currentLen;
    }

    return maxLen;
}