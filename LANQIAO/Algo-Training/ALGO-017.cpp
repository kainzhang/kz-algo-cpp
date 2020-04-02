//
// Created by LOKKA on 2020/3/26.
//

#include <iostream>

using namespace std;
typedef long long ll;

ll n, k, num[50], dp[50][10];

ll trans(int a, int b) {
    ll res = 0;
    for(int i = a; i <= b; i ++) {
        res *= 10;
        res += num[i];
    }
    return res;
}

void solve() {
    for (int i = 1; i < n; i ++) {
        for (int j = 1; j <= k; j ++) {
            for (int p = 0; p < i; p ++) {
                dp[i][j] = max(dp[i][j], dp[p][j-1] * trans(p + 1, i));
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    while(getchar() != '\n');
    for(int i = 0; i < n; i ++) {
        char t = getchar();
        num[i] = t - '0';
        dp[i][0] = trans(0, i);
    }
    solve();
    cout << dp[n - 1][k] << endl;
}