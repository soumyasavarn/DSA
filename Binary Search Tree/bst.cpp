#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <string>

#include <climits>
#include <vector>
#include <cmath>

#include "time.h"
#include "parser.h"


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

TreeNode* createNode(int item) {
    TreeNode* temp = new TreeNode;
    temp->val = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout<<root->val<<" ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        cout<<root->val<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->val<<" ";
    }
}

TreeNode* insertNode(TreeNode* node, int value) {
    if (node == NULL)
        return createNode(value);

    if (value < node->val)
        node->left = insertNode(node->left, value);
    else
        node->right = insertNode(node->right, value);

    return node;
}

void searchNode(TreeNode* node, int value) {
    if (node == NULL)
        cout<<"Not Found !!"<<endl;
    else if (node->val==value) cout<<"Found !!"<<endl;
    else if (value < node->val) searchNode(node->left, value);
    else searchNode(node->right, value);
}


TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL)
        return root;

    if (root->val > key) {
        root->left = deleteNode(root->left, key);
        return root;
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
        return root;
    }

    if (root->left == NULL) {
        TreeNode* temp = root->right;
        delete root;
        return temp;
    } else if (root->right == NULL) {
        TreeNode* temp = root->left;
        delete root;
        return temp;
    } else {
        TreeNode* succParent = root;
        TreeNode* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->val = succ->val;

        delete succ;
        return root;
    }
}

int main() {
    TreeNode* root = NULL;
    
    cout<<"Binary Search Tree Implementation: "<<endl;
    cout<<"-----------------------------------"<<endl;
    
    while(1)
    {
    

    cout<<"1. Insert"<<endl;
    cout<<"2. Delete"<<endl;
    cout<<"3. Search"<<endl;
    cout<<"4. Preorder"<<endl;
    cout<<"5. Inorder"<<endl;
    cout<<"6. Postorder"<<endl;
    cout<<"7. Exit"<<endl;


    int choose;
    cin>>choose;

    if (choose==1)
    {
        cout<<"Enter value: ";
        int x;cin>>x;
       root = insertNode(root, x);
    }

    else if (choose==2)
    {
       cout<<"Enter value: ";
       int x;cin>>x;
       root = deleteNode(root, x);
    }

    else if (choose==3)
    {
        cout<<"Enter value: ";
       int x;cin>>x;
       searchNode(root, x);

    }

    else if (choose==4)
    {
        preorderTraversal(root);
        cout<<endl;
    }

    else if (choose==5)
    {
        inorderTraversal(root);
        cout<<endl;
    }
    else if (choose==6)
    {
        postorderTraversal(root);
        cout<<endl;
    }
    else if (choose==7)
    {
        break;

    }
    
    }
    
    //Memory clear
    free(root);
    
    while(1){
        //Expression Evaluation
        cout<<"Welcome to Expression Parser program:"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<endl;
        cout<<"Enter your expression (LHS) without spaces containing single digits, + , * , / , - : "<<endl;
        string str;
        cin>>str;
        int n;
        
        cout<<"Enter RHS: ";
        cin>>n;
        int kk=evaluateExpression(str);
        if (n==kk) cout<<"Correct !!"<<endl;
        else cout<<"Not correct !!"<<endl<<"Correct value is: "<<kk<<endl;
        
        cout<<"Do you wish to continue: (Y/N) ";
        char cb;
        cin>>cb;
        if (cb=='N') break;
    }


    
    cout<<"Perform Efficiency comparision? (Y/N)"<<endl;
    char x;
    cin>>x;
     if (x=='Y') time_analysis();

    cout<<endl;
    cout<<"THANK YOU!"<<endl;

    return 0;
}
