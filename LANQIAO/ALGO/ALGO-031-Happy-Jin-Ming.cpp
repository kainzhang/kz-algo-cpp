//
// Created by LOKKA on 2020/3/30.
// 开心的金明

#include <iostream>

using namespace std;
int dp[30005];

int main() {
    int N, m, v, p;
    scanf("%d %d", &N, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &v, &p);
        for (int j = N; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + v * p);
        }
    }

    cout << dp[N] << endl;
}