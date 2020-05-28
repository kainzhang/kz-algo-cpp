//
// Created by LOKKA on 2020/5/17.
//

#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    cin >> a[0];
    int cnt = 0, res = 0;
    if (a[0] == K) cnt = 1;
    for (int i = 1; i < N; i++ ) {
        cin >> a[i];
        if (cnt) {
            if (a[i - 1] - a[i] == 1 ) {
                cnt ++;
                if (cnt == K) res++;
                continue;
            } else {
                cnt = 0;
            }
        }
        if (a[i] == K) {
            cnt = 1;
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