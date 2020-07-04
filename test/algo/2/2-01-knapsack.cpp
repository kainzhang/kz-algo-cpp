//
// Created by LOKKA on 2020/5/17.
//

#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e2;
const int mxV = 1e4;
int w[mxN], p[mxN], dp[mxN][mxV], ans[mxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V;  //n为物品数量，V为背包容量
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    for (int i = 1; i <= n; i++) {
        for (int v = V; v >= w[i]; v--) {
            dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - w[i]] + p[i]);
        }
    }
    for (int i = n, v = V; i > 0; i--) {
        if (dp[i][v] != dp[i - 1][v]) {
            ans[i] = 1;
            v -= w[i];
        }
    }
    cout << "Ans: "; //输出最优解
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl << "Max: " << dp[n][V] << endl;
}
