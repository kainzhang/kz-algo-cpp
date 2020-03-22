//
// Created by LOKKA on 2020/3/19.
// 瓷砖铺放

#include <iostream>

using namespace std;

int n, ans = 0, a[15];

void force(int len) {
    if (len == n) {
        ans++;
        return;
    } else if (len > n) {
        return;
    }
    force(len + 1);
    force(len + 2);
}

int dnc(int len) {
    if (len < 3) return a[len] = len;
    return a[len] = dnc(len-1) + dnc(len - 2);
}

int main() {
    cin >> n;
    //force(0);
    //cout << ans << endl;
    cout << dnc(n) << endl;
}