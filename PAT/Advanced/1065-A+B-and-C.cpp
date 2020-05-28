//
// Created by LOKKA on 2020/5/25.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string ans[] = {"false", "true"};

bool solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll sum = a + b;
    if (a > 0 && b > 0 && sum < 0) return true; // 溢出: 正数 + 正数 = 负数
    else if (a < 0 && b < 0 && sum >= 0) return false;  // 溢出: 负数 + 负数 = 非负数
    else return sum > c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        cout << ans[solve()] << endl;
    }
}