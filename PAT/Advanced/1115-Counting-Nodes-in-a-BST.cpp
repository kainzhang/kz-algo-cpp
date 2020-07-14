//
// Created by LOKKA on 2020/7/13.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *lchild, *rchild;
};

Node* build_tree(Node *root, int num) {
    if (root == NULL) {
        root = new Node();
        root->data = num;
        root->lchild = root->rchild = NULL;
    } else if (num <= root->data) {
        root->lchild = build_tree(root->lchild, num);
    } else {
        root->rchild = build_tree(root->rchild, num);
    }
    return root;
}

int L[2010], mxL = -1;
void dfs(Node *root, int lyr) {
    if (root == NULL) return;
    L[lyr]++;
    mxL = max(mxL, lyr);
    dfs(root->lchild, lyr + 1);
    dfs(root->rchild, lyr + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    Node *root = NULL;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        root = build_tree(root, num);
    }
    dfs(root, 0);
    cout << L[mxL] << " + " << L[mxL - 1] << " = " << L[mxL] + L[mxL - 1];
}
