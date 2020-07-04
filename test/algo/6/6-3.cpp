//
// Created by LOKKA on 2020/5/22.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C, N;
    while (cin >> C >> N) {
        vector<int> prs(N + 1), pnt(N + 1), dp(C + 1, 0);
        for (int i = 0; i < N; i++) {
            cin >> prs[i] >> pnt[i];
            for (int j = C; j >= prs[i]; j--){
                dp[j] = max(dp[j], dp[j - prs[i]] + pnt[i]);
            }
        }
        cout << dp[C] << endl;
    }
}