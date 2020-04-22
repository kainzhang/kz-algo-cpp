//
// Created by LOKKA on 2020/3/30.
// 出现次数最多的整数

#include <iostream>

using namespace std;

int main() {
    int n, tmp, cnt = 1, sav, max = 1, ans = 0;
    cin >> n;
    if (n < 1)
        return 0;
    cin >> sav;
    ans = sav;
    while (--n) {
        cin >> tmp;
        if (tmp == sav) {
            cnt++;
        } else {
            cnt = 1;
            sav = tmp;
        }
        if (cnt > max) {
            max = cnt;
            ans = sav;
        }
    }
    cout << ans << endl;
}