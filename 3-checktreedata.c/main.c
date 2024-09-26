#include <stdio.h>
#include <stdlib.h>
#include "ItrTreeTrv.h"

int main() {
    TreeNode* root = createNode(1); // ��Ʈ ��� ����

    // Ʈ�� ����
    GenerateLinkTree(root); 

    
    int sum = getSumOfNodes(root);
    int numberOfNodes = getNumberOfNodes(root);
    int height = getHeightOfTree(root);
    int numberOfLeafNodes = getNumberOfLeafNodes(root);

    // ��� ���
    printf("Sum of nodes: %d\n", sum);
    printf("Number of nodes: %d\n", numberOfNodes);
    printf("Height of Tree: %d\n", height);
    printf("Number of leaf nodes: %d\n", numberOfLeafNodes);

    

    return 0;
}
