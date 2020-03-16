//
// Created by LOKKA on 2020/3/16.
// 1004e 客似云来

#include <iostream>

using namespace std;

int main() {
    int from, to;
    static long long arr[200];
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < 90; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    while (cin >> from >> to) {
        long long ans = 0;
        for (int i = from; i <= to; i++) {
            ans += arr[i - 1];
        }
        cout << ans << endl;
    }
}