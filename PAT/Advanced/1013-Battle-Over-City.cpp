//
// Created by LOKKA on 2020/7/5.
//

#include <bits/stdc++.h>
using namespace std;

const int mxN = 1005;
vector<int> G[mxN];  // 无向图
vector<bool> ok(mxN);  // 城市连通状态

/**
 *  BFS DFS 均可, 二选一
 *  还可用并查集
 */

void bfs(int now, int lost) {
    queue<int> que;
    que.push(now);
    while(!que.empty()) {
        now = que.front();
        que.pop();
        for (int i = 0; i < G[now].size(); i++) {
            if (G[now][i] != lost && !ok[G[now][i]]) {
                // 非被攻陷且有公路的城市，修改状态为连通
                ok[G[now][i]] = true;
                que.push(G[now][i]);
            }
        }
    }
}

void dfs(int now, int lost) {
    for (int i = 0; i < G[now].size(); i++) {
        if (G[now][i] != lost && !ok[G[now][i]]) {
            ok[G[now][i]] = true;
            dfs(G[now][i], lost);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;

    // 构建无向图
    for (int i = 0; i < M; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        G[c1].push_back(c2);
        G[c2].push_back(c1);
    }

    for (int i = 0; i < K; i++) {
        int lost, cnt = 0;
        cin >> lost;
        fill(ok.begin() + 1, ok.begin() + N + 1, false);
        for (int j = 1; j <= N; j++) {

            // 不搜索被攻占的城市
            if (j == lost) continue;

            // 搜索未连通的城市
            if (!ok[j]) {
                // bfs(j, lost);
                dfs(j, lost);
                cnt++;  // 连通分量计数
            }
        }
        cout << cnt - 1 << endl;  // 减去第一个
    }
}
