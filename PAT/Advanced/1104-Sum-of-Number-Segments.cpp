//
// Created by LOKKA on 2020/5/26.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    double t, ans = 0.0;
    for (int i = 0; i < N; i++) {
        cin >> t;
        ans += t * (N - i) * (i + 1);
    }
    printf("%.2f\n", ans);
}