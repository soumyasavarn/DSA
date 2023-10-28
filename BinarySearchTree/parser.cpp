#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <climits>
#include <vector>
#include <set>
#include <stack>
#include <cmath>

using namespace std;

class Node {
public:
    char value;
    Node* left;
    Node* right;
    Node* next = NULL;
    Node(char c) {
        this->value = c;
        left = NULL;
        right = NULL;
    }
    Node() {
        left = NULL;
        right = NULL;
    }
    friend class Stack;
    friend class ExpressionTree;
};

class Stack {
    Node* top = NULL;

public:
    void push(Node*);
    Node* pop();
    friend class ExpressionTree;
};

class ExpressionTree {
public:
    void inorder(Node* x) {
        if (x == NULL)
            return;
        else {
            inorder(x->left);
            cout << x->value << " ";
            inorder(x->right);
        }
    }
    
    int toInt(char s) {
        return s - '0';
    }

    int evaluate(Node* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return toInt(root->value);

        int l_val = evaluate(root->left);
        int r_val = evaluate(root->right);

        if (root->value == '+')
            return l_val + r_val;
        if (root->value == '-')
            return l_val - r_val;
        if (root->value == '*')
            return l_val * r_val;

        return l_val / r_val;
    }
};

void Stack::push(Node* x) {
    if (top == NULL) {
        top = x;
    }
    else {
        x->next = top;
        top = x;
    }
}

Node* Stack::pop() {
    Node* p = top;
    top = top->next;
    return p;
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            st.push('(');

        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while (!st.empty()
                && precedence(s[i]) <= precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int evaluateExpression(string str) {
    string postfixExpression = infixToPostfix(str);
    Stack stack;
    ExpressionTree tree;
    Node *x, *y, *z;
    int len = postfixExpression.length();

    for (int i = 0; i < len; i++) {
        if (postfixExpression[i] == '+' || postfixExpression[i] == '-' ||
            postfixExpression[i] == '*' || postfixExpression[i] == '/' ||
            postfixExpression[i] == '^') {
            z = new Node(postfixExpression[i]);
            x = stack.pop();
            y = stack.pop();
            z->left = y;
            z->right = x;
            stack.push(z);
        }
        else {
            z = new Node(postfixExpression[i]);
            stack.push(z);
        }
    }
    return tree.evaluate(z);
}
