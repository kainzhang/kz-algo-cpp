//
// Created by LOKKA on 2020/7/2.
//

#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int L, K;
    string N;
    cin >> L >> K >> N;
    for (int i = 0; i <= L - K; i++) {

        // 截取字符串
        string s = N.substr(i, K);
        int num = stoi(s);

        // 以字符串输出（数字开头存在 0
        if (is_prime(num)) {
            cout << s << endl;
            return 0;
        }
    }
    cout << "404" << endl;
}
