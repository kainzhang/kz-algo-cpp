//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[25][25], ans[25], s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += a[i][j];
        }
        if (cnt > n / 2) cout << j + 1 << " ";
    }
}