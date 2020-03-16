//
// Created by LOKKA on 2020/3/16.
// 1017 打印沙漏

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    char symbol;
    scanf("%d %c", &n, &symbol);
    int t1 = (n - 1) % 2;
    int t2 = (n - 1) / 2;
    int cnt = 0;
    if (n) {
        cnt = 1;
        for (int i = 3; i <= t2;) {
            t2 -= i;
            i += 2;
            cnt++;
        }
    }
    for (int i = 0; i < cnt; i++) {
        for (int k = 0; k < i; k++) {
            cout << " ";
        }
        for (int j = (cnt - i) * 2 - 1; j > 0; j--) {
            cout << symbol;
        }
        cout << endl;
    }
    for (int i = cnt - 2; i >= 0; i--) {
        for (int k = 0; k < i; k++) {
            cout << " ";
        }
        for (int j = (cnt - i) * 2 - 1; j > 0; j--) {
            cout << symbol;
        }
        cout << endl;
    }
    cout << t2 * 2 + t1;
}
