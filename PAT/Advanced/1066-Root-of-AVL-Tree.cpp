//
// Created by LOKKA on 2020/7/22.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

int GetHeight(Node *root) {
    if (root == NULL) return 0;
    return max(GetHeight(root->left), GetHeight(root->right)) + 1;
}

Node* RotateLeft(Node *root) {
    Node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}

Node* RotateRight(Node *root) {
    Node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}

Node* RotateLeftRight(Node *root) {
    root->left = RotateLeft(root->left);
    return RotateRight(root);
}

Node* RotateRightLeft(Node *root) {
    root->right = RotateRight(root->right);
    return RotateLeft(root);
}

Node* Insert(Node *root, int val) {
    if (root == NULL) {
        root = new Node();
        root->val = val;
        root->left = root->right = NULL;
    } else if (val < root->val) {
        root->left = Insert(root->left, val);
        if (GetHeight(root->left) - GetHeight(root->right) == 2)
            root = val < root->left->val ? RotateRight(root) : RotateLeftRight(root);
    } else {
        root->right = Insert(root->right, val);
        if (GetHeight(root->left) - GetHeight(root->right) == -2)
            root = val > root->right->val ? RotateLeft(root) : RotateRightLeft(root);
    }
    return root;
}

int main() {
    int N, val;
    cin >> N;
    Node *root = NULL;
    for (int i = 0; i < N; i++) {
        cin >> val;
        root = Insert(root, val);
    }
    cout << root->val;
}