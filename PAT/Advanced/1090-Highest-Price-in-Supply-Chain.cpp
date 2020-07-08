//
// Created by LOKKA on 2020/7/8.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 5;

vector<int> G[mxN];

int mxL = 0, cnt = 0;

void dfs(int root, int lyr) {
    int len = G[root].size();
    if (!len) {
        if (lyr > mxL) {
            mxL = lyr;
            cnt = 1;
        } else if (lyr == mxL) {
            cnt++;
        }
        return;
    }
    for (int i = 0; i < len; i++) {
        dfs(G[root][i], lyr + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, root;
    double P, r;
    cin >> N >> P >> r;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == -1) {
            root = i;
        } else {
            G[tmp].push_back(i);
        }
    }
    dfs(root, 0);
    printf("%.2f %d\n", P * pow((1 + r / 100), mxL), cnt);
}
