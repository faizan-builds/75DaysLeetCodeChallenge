#include <stdlib.h>

// Structure for heap
typedef struct {
    int num;
    int freq;
} Node;

// Min heapify
void heapify(Node* heap, int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].freq < heap[smallest].freq)
        smallest = left;

    if (right < size && heap[right].freq < heap[smallest].freq)
        smallest = right;

    if (smallest != i) {
        Node temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, size, smallest);
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int offset = 10000;
    int freq[20001] = {0};

    // Step 1: Count frequency
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + offset]++;
    }

    // Step 2: Min heap of size k
    Node* heap = (Node*)malloc(k * sizeof(Node));
    int heapSize = 0;

    for (int i = 0; i < 20001; i++) {
        if (freq[i] > 0) {
            Node node = {i - offset, freq[i]};

            if (heapSize < k) {
                heap[heapSize++] = node;
                for (int j = heapSize/2 - 1; j >= 0; j--) {
                    heapify(heap, heapSize, j);
                }
            } else if (node.freq > heap[0].freq) {
                heap[0] = node;
                heapify(heap, heapSize, 0);
            }
        }
    }

    // Step 3: Extract result
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = heap[i].num;
    }

    *returnSize = k;
    return result;
}