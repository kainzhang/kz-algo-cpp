//
// Created by LOKKA on 2020/7/23.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

Node* BuildTree(Node *root, int val) {
    if (root == NULL) {
        root = new Node;
        root->val = val;
        root->left = root->right = NULL;
    } else if (abs(val) < abs(root->val)) {
        root->left = BuildTree(root->left, val);
    } else {
        root->right = BuildTree(root->right, val);
    }
    return root;
}

/**
 * check if all red nodes hv 2 black children nodes
 */
bool Red2Black(Node *root) {
    if (root == NULL) return true;
    if (root->val < 0) {
        if (root->left != NULL && root->left->val < 0) return false;
        if (root->right != NULL && root->right->val < 0) return false;
    }
    return Red2Black(root->left) && Red2Black(root->right);
}

int GetNum(Node *root) {
    if (root == NULL) return 0;
    int l = GetNum(root->left);
    int r = GetNum(root->right);
    return root->val > 0 ? max(l, r) + 1 : max(l, r);
}

/**
 * check if all simple paths from the node to descendant leaves
 * contain the same number of black nodes
 */
bool SameBlackNum(Node *root) {
    if (root == NULL) return true;
    int l = GetNum(root->left);
    int r = GetNum(root->right);
    if (l != r) return false;
    return SameBlackNum(root->left) && SameBlackNum(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K;
    cin >> K;
    while (K--) {
        int N;
        cin >> N;
        vector<int> pre(N);
        Node *root = NULL;
        for (int i = 0; i < N; i++) {
            cin >> pre[i];
            root = BuildTree(root, pre[i]);
        }
        // root is black
        if (pre[0] > 0 && Red2Black(root) && SameBlackNum(root)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}