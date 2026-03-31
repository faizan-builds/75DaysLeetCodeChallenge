#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack;
    int *minStack;
    int top;
    int capacity;
} MinStack;

// Initialize
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 30000;
    obj->stack = (int*)malloc(sizeof(int) * obj->capacity);
    obj->minStack = (int*)malloc(sizeof(int) * obj->capacity);
    obj->top = -1;
    return obj;
}

// Push
void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;

    if (obj->top == 0)
        obj->minStack[obj->top] = val;
    else {
        int currentMin = obj->minStack[obj->top - 1];
        obj->minStack[obj->top] = (val < currentMin) ? val : currentMin;
    }
}

// Pop
void minStackPop(MinStack* obj) {
    if (obj->top >= 0)
        obj->top--;
}

// Top
int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

// Get Min
int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

// Free memory
void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}
