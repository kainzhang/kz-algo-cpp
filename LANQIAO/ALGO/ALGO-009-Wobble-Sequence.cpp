//
// Created by LOKKA on 2020/3/17.
// 摆动序列

#include <iostream>

using namespace std;

int main() {
    int k, a[25][25], ans = 0;
    cin >> k;
    for (int i = 2; i <= k; i++) {
        a[i][i] = 2;
        a[i][2] = i * (i - 1);
        for (int j = 3; j < i; j++)
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
    }
    for (int i = 2; i <= k; i++)
        ans += a[k][i];
    cout << ans << endl;
}