//
// Created by LOKKA on 2020/7/9.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 25;

struct Node {
    string data;
    int lchild, rchild;
};

vector<Node> vec(mxN);
vector<int> vis(mxN);
int root = 1;

void get_infix(int r) {
    if (r == -1) return;
    if (r != root && (vec[r].lchild != -1 || vec[r].rchild != -1))
        cout << "(";
    get_infix(vec[r].lchild);
    cout << vec[r].data;
    get_infix(vec[r].rchild);
    if (r != root && (vec[r].lchild != -1 || vec[r].rchild != -1))
        cout << ")";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> vec[i].data >> vec[i].lchild >> vec[i].rchild;
        if (vec[i].lchild != -1) vis[vec[i].lchild]++;
        if (vec[i].rchild != -1) vis[vec[i].rchild]++;
    }
    while (vis[root]) root++;
    get_infix(root);
}
