//
// Created by LOKKA on 2020/3/27.
//

#include <iostream>

using namespace std;

const int N = 1e3 + 5;
int n, sum[N], dp[N][N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }

    for (int i = n - 1; i > 0; i --) {
        for (int j = i + 1; j <= n; j ++) {
            dp[i][j] = 1 << 30;
            for (int k = i; k < j; k ++ ) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            dp[i][j] += sum[j] - sum[i - 1];
        }
    }
    cout << dp[1][n] << " ";
}

