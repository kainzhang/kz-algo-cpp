//
// Created by LOKKA on 2020/7/6.
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, p;
    cin >> N >> p;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll i = 0, j = 0, ans = 0;
    while (i < N) {
        ll tmp = A[i] * p;
        while (A[j] <= tmp && j < N) {
            j++;
        }
        ans = max(ans, j - i);
        i++;
    }
    cout << ans << endl;
}
