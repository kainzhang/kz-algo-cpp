//
// Created by LOKKA on 2020/5/26.
//

#include <bits/stdc++.h>
using namespace std;
const double INF = 9999;

double isValid(string s) {
    int dot = 0, flag = 0, dec = 0;
    for (char c : s) {
        if (c == '.') {
            dot++;  // 小数点数
            flag = 1;
            continue;
        }
        if (flag) dec++;    // 小数点后位数
        if (isalpha(c) || dot > 1 || dec > 2) return INF;
    }
    double num = stod(s);
    if (fabs(num) > 1000) return INF;
    return num;
}

int main() {
    int N, cnt = 0;
    double sum = 0;
    cin >> N;
    string s;
    while (N--) {
        cin >> s;
        double num = isValid(s);
        if (num == INF) {
            cout << "ERROR: " << s << " is not a legal number" << endl;
        } else {
            sum += num;
            cnt++;
        }
    }
    cout << "The average of " << cnt;
    cout << fixed << setprecision(2);
    switch(cnt) {
        case 0: cout << " numbers is Undefined" << endl; break;
        case 1: cout << " number is " << sum << endl; break;
        default: cout << " numbers is " << sum / cnt << endl; break;
    }
}