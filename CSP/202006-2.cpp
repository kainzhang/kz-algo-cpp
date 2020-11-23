//
// Created by Kain Zhang on 2020/8/22.
// 稀疏向量 (svector

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, idx, val;
    cin >> n >> a >> b;
    unordered_map<int, int> u;
    while (a--) {
        cin >> idx >> val;
        u[idx] = val;
    }
    long long ans = 0;
    while (b--) {
        cin >> idx >> val;
        ans += u[idx] * val;
    }
    cout << ans << endl;
}

/*
INPUT:
10 3 4
4 5
7 -3
10 1
1 10
4 20
5 30
7 40
 */

