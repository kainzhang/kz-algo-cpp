//
// Created by LOKKA on 2020/7/16.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 110;

int N, M, S;
vector<int> w(mxN), G[mxN], path;

bool cmp(const int &a, const int &b) {
    return w[a] > w[b];
}

void dfs(int r, int sum) {
    path.push_back(r);
    sum += w[r];
    int len = G[r].size();
    if (len) {
        sort(G[r].begin(), G[r].end(), cmp);
        for (int &i : G[r]) {
            dfs(i, sum);
        }
    } else if (sum == S) {
        int len = path.size();
        cout << w[path[0]];
        for (int i = 1; i < len; i++) {
            cout << " " << w[path[i]];
        }
        cout << endl;
    }
    path.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> S;
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < M; i++) {
        int id, k, t;
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            G[id].push_back(t);
        }
    }
    dfs(0, 0);
}
