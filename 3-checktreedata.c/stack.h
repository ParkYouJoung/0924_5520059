#pragma once

#include "ItrTreeTrv.h"

typedef struct Stack {
    TreeNode** nodes;
    int top;
    int capacity;
} Stack;

extern Stack* createStack(int capacity);
extern void push(Stack* stack, TreeNode* node);
extern TreeNode* pop(Stack* stack);
extern int isEmpty(Stack* stack);
extern void freeStack(Stack* stack);

