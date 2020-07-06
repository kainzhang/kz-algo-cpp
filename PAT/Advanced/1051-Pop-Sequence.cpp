//
// Created by LOKKA on 2020/7/6.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M, N, K;
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        vector<int> vec(N);
        for (int j = 0; j < N; j++) {
            cin >> vec[j];
        }
        bool ok = true;
        int idx = 0;
        stack<int> stk;
        for (int j = 1; j <= N; j++) {
            stk.push(j);
            if (stk.size() > M) {
                ok = false;
                break;
            }
            while (!stk.empty() && stk.top() == vec[idx]) {
                stk.pop();
                idx++;
            }
        }
        if (idx != N) {
            ok = false;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}