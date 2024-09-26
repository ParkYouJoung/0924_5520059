#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->nodes = (TreeNode**)malloc(stack->capacity * sizeof(TreeNode*));
    return stack;
}


void push(Stack* stack, TreeNode* node) {
    if (stack->top < stack->capacity - 1) {
        stack->nodes[++stack->top] = node;
    }
}


TreeNode* pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->nodes[stack->top--];
    }
    return NULL;
}


int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 스택 메모리 해제
void freeStack(Stack* stack) {
    free(stack->nodes);
    free(stack);
}
