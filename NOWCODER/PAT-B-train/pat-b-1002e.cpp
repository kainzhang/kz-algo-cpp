//
// Created by LOKKA on 2020/3/16.
// 1002e NowCoder数列

#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int a = 7, b = 11, t = 0;
        if (n > 1) {
            if ((n - 2) % 4 == 0) t = 1;
        }
        if (t) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
