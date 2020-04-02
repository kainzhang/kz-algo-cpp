//
// Created by LOKKA on 2020/3/30.
// 数的划分 (dp, dfs

#include <iostream>
#include <algorithm>

using namespace std;
int n, k, ans = 0, dp[205][10];

void dfs(int x, int s, int cnt) {
    if (x == n && cnt == k) {
        ans++;
        return;
    }
    for(int i = s; i + x <= n; i++) {
        if (cnt + 1 > k) return;
        dfs(x + i, i, cnt + 1);
    }
}

void dpf() {
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
        for (int j = 2; j <= min(i, k); j++) {
            dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];
        }
    }
}

int mem_search(int i, int j) {
    if (i < 1) return 0;
    if (dp[i][j]) return dp[i][j];
    if (j == 1) return dp[i][j] = 1;
    return dp[i][j] = mem_search(i - j, j) + mem_search(i - 1, j - 1);
}

int main() {
    cin >> n >> k;
    //dfs(0, 1, 0);
    dpf();
    //cout << ans << endl;
    cout << dp[n][k] << endl;
    //cout << mem_search(n, k) << endl;
}