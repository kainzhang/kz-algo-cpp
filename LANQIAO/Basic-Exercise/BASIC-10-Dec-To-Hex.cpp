//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>

using namespace std;

int main() {
    long long a, t;
    cin >> a;
    char tmp;
    string res = "";
    do {
        t = a % 16;
        if (t < 10) {
            tmp = '0' + t;
        } else {
            tmp = 'A' + t - 10;
        }
        res = tmp + res;
        a /= 16;
    } while (a != 0);
    cout << res << endl;
}