#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int stack1[MAX];
    int stack2[MAX];
    int top1;
    int top2;
} MyQueue;

// Initialize queue
MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

// Push element to queue
void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++obj->top1] = x;
}

// Helper function to transfer elements
void transfer(MyQueue* obj) {
    while (obj->top1 != -1) {
        obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
    }
}

// Pop element from queue
int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        transfer(obj);
    }
    return obj->stack2[obj->top2--];
}

// Peek front element
int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        transfer(obj);
    }
    return obj->stack2[obj->top2];
}

// Check if queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

// Free memory
void myQueueFree(MyQueue* obj) {
    free(obj);
}


