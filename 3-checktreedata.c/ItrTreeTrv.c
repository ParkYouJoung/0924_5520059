#include <stdio.h>
#include <stdlib.h>
#include "ItrTreeTrv.h"
#include "stack.h"


TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//방향 따라 노드 배치 함수
void PlaceNode(TreeNode* node, int direction, int data) {
    TreeNode* newNode = createNode(data);
    if (direction == 0) {
        node->left = newNode;
    }
    else {
        node->right = newNode;
    }
}

void GenerateLinkTree(TreeNode* root) {
    PlaceNode(root, 0, 2);
    PlaceNode(root, 1, 9);
    PlaceNode(root->left, 0, 3);
    PlaceNode(root->left, 1, 5);
    PlaceNode(root->right, 0, 10);
    PlaceNode(root->right, 1, 13);
    PlaceNode(root->left->left, 0, 4);
    PlaceNode(root->left->left, 1, 6);
    PlaceNode(root->left->right, 0, 7);
    PlaceNode(root->left->right, 1, 8);
    PlaceNode(root->right->left, 0, 11);
    PlaceNode(root->right->left, 1, 12);
    PlaceNode(root->right->right, 0, 14);
    PlaceNode(root->right->right, 1, 15);
}

// 트리값 더하기
int getSumOfNodes(TreeNode* node) {
    int sum = 0;
    if (!node) return sum;

    Stack* stack = createStack(100);
    TreeNode* current = node;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        sum += current->data;
        current = current->right;
    }

    freeStack(stack);
    return sum;
}

// 트리의 전체 노드 갯수
int getNumberOfNodes(TreeNode* node) {
    int count = 0;
    if (!node) return count;

    Stack* stack = createStack(100);
    TreeNode* current = node;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        count++;
        current = current->right;
    }

    freeStack(stack);
    return count;
}

// 트리 높이
int getHeightOfTree(TreeNode* node) {
    if (!node) return 0;

    Stack* stack = createStack(100);
    TreeNode* current = node;
    int height = 0;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        if (current) {
            height++;
            current = current->right;
        }
    }

    freeStack(stack);
    return height;
}

// 단말 노드수
int getNumberOfLeafNodes(TreeNode* node) {
    int count = 0;
    if (!node) return count;

    Stack* stack = createStack(100);
    TreeNode* current = node;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        if (!current->left && !current->right) {
            count++;
        }
        current = current->right;
    }

    freeStack(stack);
    return count;
}
