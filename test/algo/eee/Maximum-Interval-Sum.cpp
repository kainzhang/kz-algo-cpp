//
// Created by LOKKA on 2020/6/3.
//

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n, t, res = 0;
    cin >> n;
    vector<LL> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> t;
        dp[i] = max(t, dp[i - 1] + t);
        if (dp[i] > dp[res]) {
            res = i;
        }
    }
    cout << dp[res];
}

