//
// Created by LOKKA on 2020/7/13.
//

#include <bits/stdc++.h>
using namespace std;

int G[105][2], mxL = -1;
vector<int> nod(105), LYR[105];

void build_tree(int root, int lyr, int& idx) {
    mxL = max(mxL, lyr);
    if (G[root][0] != -1) build_tree(G[root][0], lyr + 1, idx);
    LYR[lyr].push_back(nod[idx++]);
    if (G[root][1] != -1) build_tree(G[root][1], lyr + 1, idx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, l, r;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> l >> r;
        G[i][0] = l, G[i][1] = r;
    }
    for (int i = 0; i < N; i++) {
        cin >> nod[i];
    }
    sort(nod.begin(), nod.begin() + N);
    int idx = 0, flag = 0;
    build_tree(0, 0, idx);
    for (int i = 0; i <= mxL; i++) {
        int len = LYR[i].size();
        for (int j = 0; j < len; j++) {
            if (flag++) cout << " ";
            cout << LYR[i][j];
        }
    }
}
