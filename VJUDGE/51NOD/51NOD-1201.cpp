//
// Created by LOKKA on 2020/4/10.
// 整数划分


#include <iostream>
#include <cmath>

using namespace std;
const int MOD = 1e9 + 7;
int n, dp[50010][320];

int main() {
    scanf("%d", &n);
    dp[0][0] = 1;
    for (int i = 1; i < 320; i++) {
        for (int j = i; j <= n; j++) {
            dp[j][i] = (dp[j - i][i] + dp[j - i][i - 1]) % MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= sqrt(n * 2); i++)
        ans = (ans + dp[n][i]) % MOD;
    printf("%d\n", ans);
}