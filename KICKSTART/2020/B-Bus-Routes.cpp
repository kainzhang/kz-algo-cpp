//
// Created by LOKKA on 2020/5/6.
//

#include <bits/stdc++.h>

using namespace std;
using LL = long long;
LL T, N, D;

LL solve() {
    cin >> N >> D;
    vector<LL> num(N);
    LL res;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    for (int i = N - 1; i >= 0; i--) {
        res = D / num[i] * num[i];
        D = res;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: %lld\n", i, solve());
    }
}