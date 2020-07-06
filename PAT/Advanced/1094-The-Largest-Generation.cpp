//
// Created by LOKKA on 2020/7/6.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 105;

vector<int> G[mxN];
map<int, int> gen;
int ans_lv, ans_num = 0;

void dfs(int r, int lv) {
    gen[lv]++;
    if (gen[lv] > ans_num) {
        ans_num = gen[lv];
        ans_lv = lv;
    }
    int len = G[r].size();
    for (int i = 0; i < len; i++) {
        dfs(G[r][i], lv + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int pid, cid, K;
        cin >> pid >> K;
        for (int j = 0; j < K; j++) {
            cin >> cid;
            G[pid].push_back(cid);
        }
    }
    dfs(1, 1);
    cout << ans_num << " " << ans_lv << endl;
}
