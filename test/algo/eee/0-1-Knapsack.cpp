//
// Created by LOKKA on 2020/6/3.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<int> v(N + 1), p(N + 1), dp(M + 1); // v价格 p评分
    for (int i = 1; i <= N; i++)
        cin >> v[i];
    for (int i = 1; i <= N; i++)
        cin >> p[i];

    int ans = 0;
    for (int i = 1; i <=   N; i++) {
        for (int j = M; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + p[i]);    //状态转移方程
            ans = max(ans, dp[j]);
        }
    }
    cout << ans;
}