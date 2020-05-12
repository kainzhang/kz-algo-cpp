//
// Created by LOKKA on 2020/5/8.
//

#include <bits/stdc++.h>

using namespace std;

int solve() {
    int N, K, P, tmp;
    cin >> N >> K >> P;
    vector<vector<int>> dp(N + 1, vector<int>(P + 1, 0));
    for (int i = 1; i <= N; i++) {
        vector<int> pt(K + 1);
        for (int j = 1; j <= K; j++) {
            cin >> tmp;
            pt[j] = pt[j - 1] + tmp;
        }
        for (int j = 1; j <= P; j++) {
            for (int k = 0; k <= min(j, K); k++) {
                dp[i][j] = max(dp[i][j], pt[k] + dp[i - 1][j - k]);
            }
        }
    }
    return dp[N][P];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: %d\n", i, solve());
    }
}