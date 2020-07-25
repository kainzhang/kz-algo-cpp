//
// Created by LOKKA on 2020/7/15.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 505;

int C, N, S, M, G[mxN][mxN], w[mxN], d[mxN];
vector<int> pre[mxN], path, tmp_path;
bool vis[mxN];

void dijkstra(int s) {
    fill(d, d + mxN, INT_MAX);
    d[s] = 0;
    for (int i = 0; i <= N; i++) {
        int u = -1, mnD = INT_MAX;
        for (int j = 0; j <= N; j++) {
            if (!vis[j] && d[j] < mnD) {
                mnD = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v <= N; v++) {
            if (!vis[v] && G[u][v] != INT_MAX) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int min_bk = INT_MAX, min_sd = INT_MAX;
void dfs(int v) {
    tmp_path.push_back(v);
    if (v == 0) {  // 路径结束，计算需要派送和带回的数量
        int len = tmp_path.size(), bk = 0, sd = 0;
        for (int i = len - 2; i >= 0; i--) {  // 去掉出发点
            int num = w[tmp_path[i]] - C / 2;  // 当前车站的数量情况
            if (num < 0) {  // 缺车
                if (-num > bk) {
                    sd += -num - bk;
                    bk = 0;
                } else {
                    bk += num;
                }
            } else if (num > 0) {  // 多车
                bk += num;
            }
        }
        if (sd < min_sd) {
            min_sd = sd;
            min_bk = bk;
            path = tmp_path;
        } else if (sd == min_sd && bk < min_bk) {
            min_bk = bk;
            path = tmp_path;
        }
    }
    int len = pre[v].size();
    for (int i = 0; i < len; i++) {
        dfs(pre[v][i]);
    }
    tmp_path.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill (G[0], G[0] + mxN * mxN, INT_MAX);
    cin >> C >> N >> S >> M;
    for (int i = 1; i <= N; i++) {
        cin >> w[i]; // 单车数量
    }
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        G[a][b] = G[b][a] = t;
    }
    dijkstra(0);
    dfs(S);
    cout << min_sd << " ";
    int len = path.size();
    for (int i = len - 1; i >= 0; i--) {
        if (i < len - 1) cout << "->";
        cout << path[i];
    }
    cout << " " << min_bk << endl;
}
