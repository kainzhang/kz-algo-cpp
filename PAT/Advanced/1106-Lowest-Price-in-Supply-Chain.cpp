//
// Created by LOKKA on 2020/7/8.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 5;

vector<int> G[mxN];

int N, cnt = 0;
double P, r, mnP = 1e10 + 5;

void dfs(int root, int lyr) {
    int len = G[root].size();
    if (!len) {
        double prs = P * pow(1 + r / 100, lyr);
        if (prs < mnP) {
            mnP = prs;
            cnt = 1;
        } else if (prs == mnP) {
            cnt++;
        }
    }
    for (auto &i : G[root]) {
        dfs(i, lyr + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> P >> r;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        while (K--) {
            int id;
            cin >> id;
            G[i].push_back(id);
        }
    }
    dfs(0, 0);
    printf("%.4f %d\n", mnP, cnt);
}
