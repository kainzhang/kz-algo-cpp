//
// Created by LOKKA on 2020/7/11.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> G[105], res(105);
int mxL = -1;

void dfs(int root, int lyr) {
    int len = G[root].size();
    if (!len) {
        res[lyr]++;
        mxL = max(mxL, lyr);
        return;
    }
    for (auto &i : G[root]) {
        dfs(i, lyr + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    while (M--) {
        int id, K;
        cin >> id >> K;
        while (K--) {
            int sid;
            cin >> sid;
            G[id].push_back(sid);
        }
    }
    dfs(1, 0);
    for (int i = 0; i <= mxL; i++) {
        if (i) cout << " ";
        cout << res[i];
    }
}
