//
// Created by LOKKA on 2020/7/13.
//

#include <bits/stdc++.h>
using namespace std;

int G[25][2], vis[25];
vector<int> T(25, -1);

void dfs(int root, int idx) {
    T[idx] = root;
    if (G[root][0] != -1) dfs(G[root][0], idx * 2);
    if (G[root][1] != -1) dfs(G[root][1], idx * 2 + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        int l = -1, r = -1;
        if (a[0] != '-') {
            l = stoi(a);
            vis[l] = 1;
        }
        if (b[0] != '-') {
            r = stoi(b);
            vis[r] = 1;
        }
        G[i][0] = l, G[i][1] = r;
    }
    int root;
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            root = i;
            break;
        }
    }
    dfs(root, 1);
    for (int i = 1; i <= N; i++) {
        if (T[i] == - 1) {
            cout << "NO" << " " << root << endl;
            return 0;
        }
    }
    cout << "YES" << " " << T[N] << endl;
}
