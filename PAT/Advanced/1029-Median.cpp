//
// Created by LOKKA on 2020/7/5.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N1, N2;
    cin >> N1;
    vector<int> S1(N1 + 1);
    for (int i = 0; i < N1; i++) {
        cin >> S1[i];
    }
    S1[N1] = INT_MAX;
    cin >> N2;
    int mid = (N1 + N2 - 1) / 2, S2, i = 0, j = 0, cnt = 0;
    cin >> S2;
    while (cnt++ < mid) {
        if (S1[i] < S2) {
            i++;
        } else {
            if (++j < N2) {
                cin >> S2;
            } else {
                S2 = INT_MAX;
            }
        }
    }
    cout << (S1[i] < S2 ? S1[i] : S2) << endl;
}