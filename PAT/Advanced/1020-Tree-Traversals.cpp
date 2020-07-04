//
// Created by LOKKA on 2020/7/3.
//

#include <bits/stdc++.h>
using namespace std;

const int mxN = 35;
int post[mxN], in[mxN];

struct node {
    int data;
    node* lchild;
    node* rchild;
};

node* build_tree(int postL, int postR, int inL, int inR) {
    if (postL > postR) return NULL;
    int k = inL;

    // 在中序序列搜索根结点
    while (k <= inR) {
        if (in[k] == post[postR])
            break;
        k++;
    }

    // 左子树顶点数量
    int numleft = k - inL;
    node* n = new node;

    // 根节点赋值，后序序列末位为根节点
    n->data = post[postR];

    n->lchild = build_tree(postL, postL + numleft - 1, inL, k - 1);
    n->rchild = build_tree(postL + numleft, postR - 1, k + 1, inR);
    return n;
}

void print_level_order(node* n) {
    queue<node*> que;
    que.push(n);
    int flag = 0;
    while (!que.empty()) {
        node* t = que.front();
        que.pop();
        if (flag) cout << " ";
        cout << t->data;
        flag++;
        if (t->lchild != NULL) que.push(t->lchild);
        if (t->rchild != NULL) que.push(t->rchild);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> post[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }
    node* root = build_tree(0, N - 1, 0, N - 1);
    print_level_order(root);
}
