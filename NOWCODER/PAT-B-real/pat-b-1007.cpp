//
// Created by LOKKA on 2020/3/16.
// 1007 A除以B

#include <iostream>

using namespace std;

int main() {
    string a, ans = "";
    int b, t1, t2 = 0, flag = 0, j = 0;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        int tmp = t2 * 10 + a[i] - '0';
        t1 = tmp / b;
        if (t1 == 0) {
            t2 = tmp;
        } else {
            t2 = tmp % b;
            flag++;
        }
        if (flag)
            ans.append(1, t1 + '0');
    }
    cout << ans << " " << t2;
}
