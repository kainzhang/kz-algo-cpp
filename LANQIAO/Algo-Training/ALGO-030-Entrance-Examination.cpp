//
// Created by LOKKA on 2020/3/30.
// 入学考试

#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e3 + 5;
int T, M, t[N], v[N], dp[N];

int main() {
    scanf("%d %d", &T, &M);

    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &t[i], &v[i]);
        for (int j = T; j >= t[i]; j--) {
            dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
        }
    }
    cout << dp[T] << endl;
}