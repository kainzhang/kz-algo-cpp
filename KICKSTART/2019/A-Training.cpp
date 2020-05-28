//
// Created by LOKKA on 2020/5/12.
//

#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N, P, sum = 0, res = INT_MAX;
    cin >> N >> P;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    sort(S.begin(), S.end());
    for (int i = 0; i < N; i++) {
        sum += S[i];
        if (i >= P - 1) {
            res = min(res, P * S[i] - sum);
            sum -= S[i - P + 1];
        }
    }
    return res;
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