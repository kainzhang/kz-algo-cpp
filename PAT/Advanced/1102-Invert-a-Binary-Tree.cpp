//
// Created by LOKKA on 2020/7/9.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> G[20], vis(20);

void bfs_lv(int r) {
    queue<int> que;
    que.push(r);
    int flag = 0;
    while (!que.empty()) {
        r = que.front();
        que.pop();
        if (flag) cout << " ";
        flag++;
        cout << r;
        if (G[r][1] > -1) que.push(G[r][1]);
        if (G[r][0] > -1) que.push(G[r][0]);
    }
    cout << endl;
}

int dfs_flag = 0;
void dfs_in(int r) {
    if (G[r][1] > -1) dfs_in(G[r][1]);
    if (dfs_flag) cout << " ";
    cout << r;
    dfs_flag++;
    if (G[r][0] > -1) dfs_in(G[r][0]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char a, b;
        cin >> a >> b;
        int tmp;
        if (a == '-') tmp = -1;
        else tmp = a - '0';
        G[i].push_back(tmp);
        if (tmp > -1)vis[tmp]++;

        if (b == '-') tmp = -1;
        else tmp = b - '0';
        G[i].push_back(tmp);
        if (tmp > -1)vis[tmp]++;
    }
    int root;
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            root = i;
            break;
        }
    }
    bfs_lv(root);
    dfs_in(root);
}
