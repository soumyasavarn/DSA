#ifndef BST_H
#define BST_H


struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};
TreeNode* createNode(int item);
TreeNode* insertNode(TreeNode* node, int value);
TreeNode* deleteNode(TreeNode* node, int key);
void searchNode(TreeNode* node, int value);



#endif

