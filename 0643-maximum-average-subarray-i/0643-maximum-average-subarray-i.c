#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    int window_sum = 0;

    // Sum of first k elements
    for (int i = 0; i < k; i++) {
        window_sum += nums[i];
    }

    int max_sum = window_sum;

    // Slide the window
    for (int i = k; i < numsSize; i++) {
        window_sum += nums[i] - nums[i - k];
        if (window_sum > max_sum) {
            max_sum = window_sum;
        }
    }

    // Return average
    return (double)max_sum / k;
}