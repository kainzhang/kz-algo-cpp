//
// Created by LOKKA on 2020/5/7.
//

#include <bits/stdc++.h>

using namespace std;

int solve() {
    int N, B, t, res = 0;
    cin >> N >> B;
    priority_queue<int, vector<int>, greater<int> > que;
    for (int i = 0; i < N; i++) {
        cin >> t;
        que.push(t);
    }
    while (!que.empty()) {
        if (B >= que.top()) {
            B -= que.top();
            que.pop();
            res++;
        } else {
            break;
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