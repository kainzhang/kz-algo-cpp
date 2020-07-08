//
// Created by LOKKA on 2020/7/8.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 5;

vector<int> G[mxN];
vector<double> amt(mxN);

int N;
double P, r, ans = 0;

void dfs(int root, int lyr) {
    int len = G[root].size();
    if (!len) {
        ans += P * pow((1 + r / 100), lyr) * amt[root];
        return;
    }
    for (int i = 0; i < len; i++) {
        dfs(G[root][i], lyr + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> P >> r;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        if (K) {
            while(K--) {
                int id;
                cin >> id;
                G[i].push_back(id);
            }
        } else {
            double a;
            cin >> a;
            amt[i] = a;
        }
    }
    dfs(0, 0);
    printf("%.1f\n", ans);
}
