//
// Created by LOKKA on 2020/4/15.
// 矩阵乘法 (DP

#include <iostream>

using namespace std;
typedef long long LL;

LL solve(int n, int *a, LL **dp) {
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = LONG_LONG_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j], dp[i][j]);
            }
        }
    }
    return dp[1][n];
}

int main() {
    int n;
    cin >> n;
    int *a = new int[n + 1];
    LL **dp = new LL *[n + 1];
    for (int i = 0; i < n + 1; i++) {
        dp[i] = new LL[n + 1];
        scanf("%lld", &a[i]);
    }

    cout << solve(n, a, dp) << endl;

    delete[] a;
    for (int i = 0; i < n + 1; i++)
        delete[] dp[i];
    delete[] dp;
}