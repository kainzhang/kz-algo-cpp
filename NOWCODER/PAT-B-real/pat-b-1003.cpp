//
// Created by LOKKA on 2020/3/16.
// 1003 数素数

#include <iostream>
#include <cmath>

using namespace std;

int prime(int x) {
    int tmp = sqrt(x);
    for (int i = 2; i <= tmp; i++)
        if (x % i == 0) return 0;
    return 1;
}

int main() {
    int m, n, cnt = 1, step = 0;
    cin >> m >> n;
    for (int i = 2; cnt <= n; i++) {
        if (prime(i)) {
            if (cnt > m - 1) {
                cout << i;
                step++;
                if (step % 10 == 0) cout << endl;
                else if (cnt < n) cout << " ";
            }
            cnt++;
        }
    }
}