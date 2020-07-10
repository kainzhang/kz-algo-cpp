//
// Created by LOKKA on 2020/7/9.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e3 + 5;

vector<int> G[mxN], in(mxN, 0);

/*
 * 拓扑序列每个结点入度为 0
 * 访问过的结点删除所有出度
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        in[b]++;  // 统计入度
    }
    int K, cnt = 0;
    cin >> K;
    for (int i = 0; i < K; i++) {
        bool istopo = 1;
        vector<int> inv(in.begin(), in.end());
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            if (inv[num] > 0) {
                istopo = 0;
            }
            for (auto &k : G[num]) {
                inv[k]--;
            }
        }
        if (!istopo) {
            if (cnt) cout << " ";
            cout << i;
            cnt++;
        }
    }
}
