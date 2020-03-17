//
// Created by LOKKA on 2020/3/17.
// 回形取数

#include <iostream>

using namespace std;

int main() {
    int m, n, a[205][205];
    cin >> m >> n;
    for (int x = 0; x < m; x++)
        for (int y = 0; y < n; y++)
            cin >> a[x][y];
    int dx = 0, dy = 0, i, j, cnt = 0, sum = m * n;
    while (cnt < sum) {
        for (i = dx; i < m; i++) {
            if (a[i][dy] > -1) {
                cout << a[i][dy] << " ";
                a[i][dy] = -1;
                cnt++;
            }
        }
        dy++;
        for (j = dy; j < n; j++) {
            if (a[i - 1][j] > -1) {
                cout << a[i - 1][j] << " ";
                a[i - 1][j] = -1;
                cnt++;
            }
        }
        for (i = m - 2; i >= dx; i--) {
            if (a[i][j - 1] > -1) {
                cout << a[i][j - 1] << " ";
                a[i][j - 1] = -1;
                cnt++;
            }
        }
        for (j = n - 2; j >= dy; j--) {
            if (a[i + 1][j] > -1) {
                cout << a[i + 1][j] << " ";
                a[i + 1][j] = -1;
                cnt++;
            }
        }
        dx++;
        m--;
        n--;
    }
}

