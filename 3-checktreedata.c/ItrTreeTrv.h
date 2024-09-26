#pragma once

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

extern TreeNode* createNode(int data);
extern void generateLinkTree(TreeNode* root);
extern void inorderTraversal(TreeNode* root);
extern int getSumOfNodes(TreeNode* node);
extern int getNumberOfNodes(TreeNode* node);
extern int getHeightOfTree(TreeNode* node);
extern int getNumberOfLeafNodes(TreeNode* node);
