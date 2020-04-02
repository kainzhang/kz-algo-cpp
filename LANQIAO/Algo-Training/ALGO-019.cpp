//
// Created by LOKKA on 2020/3/30.
// 方格取数

#include <iostream>
#include <algorithm>

using namespace std;

int mp[15][15], dp[15][15][15][15];

void func(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                for(int l = 1; l <= n; l++) {
                    int tmp1 = max(dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1]);
                    int tmp2 = max(dp[i - 1][j][k][l - 1], dp[i - 1][j][k - 1][l]);
                    int tmp = max(tmp1, tmp2);
                    dp[i][j][k][l] = tmp + mp[i][j] + mp[k][l];
                    if (i == k && j == l) dp[i][j][k][l] -= mp[i][j];
                }
            }
        }
    }
}

int main() {
    int n, x, y, w;
    scanf("%d", &n);
    while(scanf("%d %d %d", &x, &y, &w)) {
        if (!x && !y && !w) break;
        mp[x][y] = w;
    }
    dp[1][1][1][1] = mp[1][1];
    func(n);
    cout << dp[n][n][n][n] << endl;
}