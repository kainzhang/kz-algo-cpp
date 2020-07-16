//
// Created by LOKKA on 2020/7/15.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> G[1005];
int N, L, K;
bool vis[1005];

struct Node {
    int id, lv;
};

void bfs(int id) {
    queue<Node> que;
    que.push(Node{id, 0});
    while (!que.empty()) {
        Node now = que.front();
        que.pop();
        if (now.lv < L) {
            for (int &i : G[now.id]) {
                if (!vis[i]) {
                    vis[i] = true;
                    que.push(Node{i, now.lv + 1});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        int M, id;
        cin >> M;
        for (int j = 0; j < M; j++) {
            cin >> id;
            G[id].push_back(i);
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        fill(vis + 1, vis + N + 1, false);
        int id;
        cin >> id;
        vis[id] = true;
        bfs(id);
        cout << count(vis, vis + N + 1, true) - 1 << endl;
    }
}
