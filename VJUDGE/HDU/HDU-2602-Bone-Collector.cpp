//
// Created by LOKKA on 2020/3/28.
// (01背包

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 5;
int w[MAXN], p[MAXN], dp[MAXN];
int main() {
    int T, N, V;  //N为物品数量，V为背包容量
    scanf("%d", &T);
    while (T--) {
        memset(dp, 0, sizeof(dp));
        scanf("%d %d", &N, &V);
        for (int i = 1; i <= N; i++)
            scanf("%d", &p[i]);
        for (int i = 1; i <= N; i++)
            scanf("%d", &w[i]);

        for (int i = 1; i <= N; i++) {
            for (int j = V; j >=w[i]; j--) {
                dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
            }
        }
        cout << dp[V] << endl;
    }
}



