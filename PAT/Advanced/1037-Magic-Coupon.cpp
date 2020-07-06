//
// Created by LOKKA on 2020/7/6.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int NC, NP;
    cin >> NC;
    vector<int> C(NC);
    for (int i = 0; i < NC; i++) cin >> C[i];
    sort(C.begin(), C.end());

    cin >> NP;
    vector<int> P(NP);
    for (int i = 0; i < NP; i++) cin >> P[i];
    sort(P.begin(), P.end());

    // 累加负数优惠券和商品
    long long ans = 0, i = 0, j = 0;
    while (C[i] < 0 && P[j] < 0) {
        ans += C[i++] * P[j++];
    }

    // 累加正数优惠券和商品
    i = NC - 1, j = NP - 1;
    while (C[i] > 0 && P[j] > 0) {
        ans += C[i--] * P[j--];
    }
    cout << ans << endl;
}
