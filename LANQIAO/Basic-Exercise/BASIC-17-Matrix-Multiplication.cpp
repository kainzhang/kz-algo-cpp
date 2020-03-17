//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>

using namespace std;
int n, m, arr[50][50], ans[50][50], mid[50][50];

void func(int a[][50], int b[][50]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t = 0;
            for (int k = 0; k < n; k++) {
                t += a[i][k] * b[k][j];
            }
            mid[i][j] = t;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = mid[i][j];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (i == j)ans[i][j] = 1;
            else ans[i][j] = 0;
        }
    while (m) {
        if (m & 1)func(arr, ans);
        func(arr, arr);
        m >>= 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j)cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
}