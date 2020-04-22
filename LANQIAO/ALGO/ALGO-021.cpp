//
// Created by LOKKA on 2020/3/30.
// 装箱问题

#include <iostream>
#include <algorithm>

using namespace std;
int dp[20005];

int main() {
    int V, n, v;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        for (int j = V; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + v);
        }
    }
    cout << V - dp[V] << endl;
}