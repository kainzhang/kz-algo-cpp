//
// Created by LOKKA on 2020/7/13.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, ans = 0;
    cin >> N;
    int a = 1, l, r;
    while (N / a) {
        int now = N / a % 10;
        l = N / (a * 10);
        r = N % a;
        if (now == 0) ans += l * a;
        else if (now == 1) ans += l * a + 1 + r;
        else if (now > 1) ans += (l + 1) * a;
        a *= 10;
    }
    cout << ans;
}
