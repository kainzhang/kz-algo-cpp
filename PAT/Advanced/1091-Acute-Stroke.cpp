//
// Created by LOKKA on 2020/7/18.
//

#include <bits/stdc++.h>
using namespace std;

int M, N, L, T, G[65][1300][130];
int dh[] = {1, 0, 0, 0, 0, -1}, dx[] = {0, -1, 0, 1, 0, 0}, dy[] = {0, 0, 1, 0, -1, 0};

struct Node {
    int x, y, h;
};

int bfs(int h, int x, int y) {
    queue<Node> que;
    que.push(Node{x, y, h});
    int cnt = 0;
    while (!que.empty()) {
        Node node = que.front();
        que.pop();
        cnt++;
        for (int i = 0; i < 6; i++) {
            int nh = node.h + dh[i];
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            if (nh < 0 || nh >= L || nx < 0 || nx >= M || ny < 0 || ny >= N || G[nh][nx][ny] == 0) continue;
            G[nh][nx][ny] = 0;
            que.push(Node{nx, ny, nh});
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d %d %d", &M, &N, &L, &T);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                scanf("%d", &G[i][j][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                if (G[i][j][k] == 1) {
                    G[i][j][k] = 0;
                    int tmp = bfs(i, j, k);
                    if (tmp >= T) ans += tmp;
                }
            }
        }
    }
    cout << ans;
}
