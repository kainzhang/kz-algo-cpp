//
// Created by LOKKA on 2020/7/23.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val, lyr;
    Node *left, *right;
};

int GetHeight(Node *root) {
    if (root == NULL) return 0;
    return max(GetHeight(root->left), GetHeight(root->right)) + 1;
}

Node* L(Node *root) {
    Node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}

Node* R(Node *root) {
    Node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}

Node* Insert(Node *root, int val) {
    if (root == NULL) {
        root = new Node();
        root->val = val;
        root->left = root->right = NULL;
    } else if (val < root->val) {
        root->left = Insert(root->left, val);
        if (GetHeight(root->left) - GetHeight(root->right) == 2) {
            if (val < root->left->val) {  // LL 型
                root = R(root);
            } else {  // LR 型
                root->left = L(root->left);
                root = R(root);
            }
        }
    } else {
        root->right = Insert(root->right, val);
        if (GetHeight(root->left) - GetHeight(root->right) == -2) {
            if (val >= root->right->val) {  // RR 型
                root = L(root);
            } else {  // RL 型
                root->right = R(root->right);
                root = L(root);
            }
        }
    }
    return root;
}

bool is_complete = true;
void LayerOrder(Node *root) {
    queue<Node*> que;
    root->lyr = 0;
    que.push(root);
    bool flag = false, sign = false;
    while (!que.empty()) {
        root = que.front();
        que.pop();
        if (flag) cout << " " << root->val;
        else {
            cout << root->val;
            flag = true;
        }
        int flagL = 0, flagR = 0;
        if (root->left != NULL) {
            que.push(root->left);
            if (sign) is_complete = false;  // 层次遍历前面一个结点无儿子，当前结点有儿子
        } else {
            sign = true;  // 出现第一个无儿子结点时标记
        }
        if (root->right != NULL) {
            que.push(root->right);
            if (sign) is_complete = false;
        } else {
            sign = true;
        }
    }
    cout << endl;
}

int main() {
    int N, val;
    cin >> N;
    Node *root = NULL;
    for (int i = 0; i < N; i++) {
        cin >> val;
        root = Insert(root, val);
    }
    LayerOrder(root);
    cout << (is_complete ? "YES" : "NO") << endl;
}