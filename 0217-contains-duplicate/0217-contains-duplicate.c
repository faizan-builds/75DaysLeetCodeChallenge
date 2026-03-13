#include <stdbool.h>
#include <stdlib.h>

#define HASH_SIZE 200003

typedef struct Node {
    int val;
    struct Node* next;
} Node;

bool containsDuplicate(int* nums, int numsSize) {
    
    Node* hash[HASH_SIZE] = {0};

    for(int i = 0; i < numsSize; i++) {
        int key = abs(nums[i]) % HASH_SIZE;

        Node* curr = hash[key];

        while(curr) {
            if(curr->val == nums[i])
                return true;
            curr = curr->next;
        }

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = nums[i];
        newNode->next = hash[key];
        hash[key] = newNode;
    }

    return false;
}