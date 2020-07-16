//
// Created by LOKKA on 2020/7/14.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> in, pre;
map<int, int> mp;
int M, N, u, v, inU, inV;

// inL 为中序的左边界, preCur 为先序中的游标，即当前选中的根结点
void LCA(int inL, int preCur) {
    // 获取当前根结点在中序中的下标
    int inRoot = mp[pre[preCur]];

    if ((inU < inRoot && inV > inRoot) || (inU > inRoot && inV < inRoot)) {
        cout << "LCA of " << u << " and " << v << " is " << in[inRoot] << "." << endl;
    } else if (inU < inRoot && inV < inRoot) {  // U, V 在当前根结点的左子树
        LCA(inL, preCur + 1);
    } else if (inU > inRoot && inV > inRoot) {  // U, V 在当前根结点的右子树
        LCA(inRoot + 1, preCur + (inRoot - inL) + 1);
    } else if (inU == inRoot) {  // U 为根结点
        cout << u << " is an ancestor of " << v << "." << endl;
    } else if (inV == inRoot) {  // V 为根结点
        cout << v << " is an ancestor of " << u << "." << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> M >> N;
    in.resize(N + 1), pre.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> in[i];
        mp[in[i]] = i;  // 保存结点的中序下标
    }
    for (int i = 1; i <= N; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        if (!mp[u] && !mp[v]) {
            cout << "ERROR: " << u << " and " << v << " are not found." << endl;
        } else if (!mp[u] || !mp[v]) {
            cout << "ERROR: " << (!mp[u] ? u : v) << " is not found." << endl;
        } else {
            inU = mp[u], inV = mp[v];  // 获取 U, V 在中序中的下标
            LCA(1, 1);
        }
    }
}