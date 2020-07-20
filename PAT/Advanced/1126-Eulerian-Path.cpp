//
// Created by LOKKA on 2020/7/20.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> G[505], vis(505);

void dfs(int idx) {
    vis[idx]++;
    int len = G[idx].size();
    for (int i = 0; i < len; i++) {
        if (!vis[G[idx][i]]) dfs(G[idx][i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    int flag = 0, v_odd = 0;
    for (int i = 1; i <= N; i++) {
        if (flag++) cout << " ";
        cout << G[i].size();
        if (G[i].size() & 1) v_odd++;
        if (!vis[i]) v_odd = 3;
    }
    cout << endl;
    if (v_odd == 0) {
        cout << "Eulerian" << endl;
    } else if (v_odd == 2) {
        cout << "Semi-Eulerian" << endl;
    } else {
        cout << "Non-Eulerian" << endl;
    }
}

