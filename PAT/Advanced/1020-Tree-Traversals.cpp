//
// Created by LOKKA on 2020/7/3.
//

/*
 *  Version 1 邻接矩阵
 */

#include <bits/stdc++.h>
using namespace std;
const int mxN = 35;

int G[mxN][3], post[mxN], in[mxN];

int build_tree(int postL, int postR, int inL, int inR) {
    if (postL > postR) return -1;
    int k = inL;
    while (k <= inR) {
        if (in[k] == post[postR]) break;
        k++;
    }
    int numleft = k - inL;  // 左子树结点数量
    G[post[postR]][0] = build_tree(postL, postL + numleft - 1, inL, k - 1);
    G[post[postR]][1] = build_tree(postL + numleft, postR - 1, k + 1, inR);

    return post[postR];
}

void print_level_order(int r) {
    queue<int> que;
    que.push(r);
    int flag = 0;
    while (!que.empty()) {
        r = que.front();
        que.pop();
        if (flag) cout << " ";
        cout << r;
        flag++;
        if (G[r][0] != -1) que.push(G[r][0]);
        if (G[r][1] != -1) que.push(G[r][1]);
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
    int root = build_tree(0, N - 1, 0, N - 1);
    print_level_order(root);
}


/*
 *  Version 2 链表
 */

//#include <bits/stdc++.h>
//using namespace std;
//
//const int mxN = 35;
//int post[mxN], in[mxN];
//
//struct node {
//    int data;
//    node* lchild;
//    node* rchild;
//};
//
//node* build_tree(int postL, int postR, int inL, int inR) {
//    if (postL > postR) return NULL;
//    int k = inL;
//
//    // 在中序序列搜索根结点
//    while (k <= inR) {
//        if (in[k] == post[postR])
//            break;
//        k++;
//    }
//
//    // 左子树结点数量
//    int numleft = k - inL;
//    node* n = new node;
//
//    // 根节点赋值，后序序列末位为根结点
//    n->data = post[postR];
//
//    n->lchild = build_tree(postL, postL + numleft - 1, inL, k - 1);
//    n->rchild = build_tree(postL + numleft, postR - 1, k + 1, inR);
//    return n;
//}
//
//void print_level_order(node* n) {
//    queue<node*> que;
//    que.push(n);
//    int flag = 0;
//    while (!que.empty()) {
//        node* t = que.front();
//        que.pop();
//        if (flag) cout << " ";
//        cout << t->data;
//        flag++;
//        if (t->lchild != NULL) que.push(t->lchild);
//        if (t->rchild != NULL) que.push(t->rchild);
//    }
//}
//
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    int N;
//    cin >> N;
//    for (int i = 0; i < N; i++) {
//        cin >> post[i];
//    }
//    for (int i = 0; i < N; i++) {
//        cin >> in[i];
//    }
//    node* root = build_tree(0, N - 1, 0, N - 1);
//    print_level_order(root);
//}
