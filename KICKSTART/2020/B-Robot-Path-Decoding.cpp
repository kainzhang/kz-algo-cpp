//
// Created by LOKKA on 2020/5/6.
//

#include <bits/stdc++.h>

using namespace std;
using LL = long long;

vector<LL> solve() {
    string str;
    cin >> str;
    stack<LL> stk;
    stk.push(1);
    LL x = 1, y = 1, MOD = 1e9;
    for (char c : str) {
        switch (c) {
            case 'N':
                y -= stk.top();
                break;
            case 'S':
                y += stk.top();
                break;
            case 'W':
                x -= stk.top();
                break;
            case 'E':
                x += stk.top();
                break;
            case '(':
                break;
            case ')':
                stk.pop();
                break;
            default:
                stk.push(stk.top() * (c - '0') % MOD);
        }
        if (x <= 0) x += MOD;
        else if (x > MOD) x -= MOD;
        if (y <= 0) y += MOD;
        else if (y > MOD) y -= MOD;
    }
    return {x, y};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        vector<LL> ans = solve();
        printf("Case #%d: %lld %lld\n", i, ans[0], ans[1]);
    }
}