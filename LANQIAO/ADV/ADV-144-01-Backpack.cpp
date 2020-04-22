//
// Created by LOKKA on 2020/4/22.
// 01背包（DP

#include <iostream>

using namespace std;
int N, M, W[205], V[205], ans = 0, dp[5005];

// （WA）回溯法，样例过一半
//void dfs(int i, int m, int v) {
//    if (i == N) {
//        ans = max(ans, v);
//        return;
//    }
//    dfs(i + 1, m, v);
//    if (m + W[i] <= M)
//        dfs(i + 1, m + W[i], v + V[i]);
//}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &W[i], &V[i]);

    //dfs(0, 0, 0);
    //cout << ans << endl;

    for (int i = 0; i < N; i++)
        for (int j = M; j >= W[i]; j--)
            dp[j] = max(dp[j], dp[j - W[i]] + V[i]);

    cout << dp[M] << endl;
}