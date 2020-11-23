//
// Created by Kain Zhang on 2020/9/12.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        vec[i] *= 10;
    }
    int mid;
    if (n & 1) {
        mid = vec[n / 2];
    } else {
        mid = (vec[n / 2] + vec[n / 2 - 1]) / 2;
    }
    int mx, mi;
    if (vec[n - 1] > vec[0]) {
        mx = vec[n - 1], mi = vec[0];
    } else {
        mx = vec[0], mi = vec[n - 1];
    }
    printf("%d", mx / 10);
    if (mid % 10 == 0) {
        printf(" %d %d", mid / 10, mi / 10);
    }  else {
        printf(" %.1f %d", mid * 1.0 / 10, mi / 10);
    }
}