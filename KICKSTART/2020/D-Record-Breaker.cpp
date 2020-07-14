//
// Created by LOKKA on 2020/7/12.
//

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int solve() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int mxV = -1, cnt = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] > mxV) {
            if (i == N - 1) {
                cnt++;
            } else if (v[i] > v[i + 1]) {
                cnt++;
            }
            mxV = v[i];
        }
    }
    return cnt;
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