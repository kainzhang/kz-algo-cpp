//
// Created by LOKKA on 2020/3/22.
// 进制转换

#include <iostream>
#include <algorithm>

using namespace std;

void convert(int num, int base) {
    string ans;
    int nm = num;
    while(num) {
        int cur = num % base, sav = num;
        num /= base;
        if (cur < 0) {
            cur = sav - ++num * base;
        }
        if (cur <= 9) {
            ans.push_back(cur + '0');
        } else {
            ans.push_back(cur - 10 + 'A');
        }
    }
    reverse(ans.begin(), ans.end());
    cout << nm << "=" << ans << "(base" << base << ")" << endl;
}

int main() {
    int num, base;
    cin >> num >> base;
    convert(num, base);
}