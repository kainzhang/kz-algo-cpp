//
// Created by LOKKA on 2020/7/5.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e4 + 5;

vector<int> G[mxN], tmp;  // 无向图、临时解集
vector<bool> vis(mxN);

int max_h = 0;

void dfs(int idx, int h) {
    vis[idx] = true;
    if (h > max_h) {
        max_h = h;
        tmp.clear();
        tmp.push_back(idx);
    } else if (h == max_h) {
        tmp.push_back(idx);
    }

    // 遍历结点所有子结点
    for (int &i : G[idx]) {
        if (vis[i]) continue;
        dfs(i, h + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int K = 0;  // 统计连通分量个数
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfs(i, 0);
            K++;
        }
    }

    if (K > 1) {  // 连通分量个数大于 1, 非连通图, 输出错误
        cout << "Error: " << K << " components" << endl;
        return 0;
    }

    // 保存第一次深搜解集
    set<int> ans(tmp.begin(), tmp.end());

    // 第二次深搜
    fill(vis.begin(), vis.begin() + N + 1, false);
    dfs(tmp[0], 0);

    // 保存第二次深搜解集
    for (int &i : tmp) {
        ans.insert(i);
    }
    for (auto &i : ans) {
        cout << i << endl;
    }
}
