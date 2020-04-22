//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>

using namespace std;

int main() {
    int n, a[10000], step = 1, tmp;
    cin >> n;
    a[0] = 1;
    for (int i = 2; i <= n; i++) {
        int up = 0;
        for (int j = 0; j < step; j++) {
            tmp = a[j] * i + up;
            a[j] = tmp % 10;
            up = tmp / 10;
        }
        while (up) {
            a[++step - 1] = up % 10;
            up /= 10;
        }
    }
    for (int i = step - 1; i >= 0; i--)
        cout << a[i];
}