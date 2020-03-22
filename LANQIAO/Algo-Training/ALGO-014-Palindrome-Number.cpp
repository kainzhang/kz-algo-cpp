//
// Created by LOKKA on 2020/3/19.
// 回文数

#include <iostream>
#include <algorithm>

using namespace std;

bool is_pld(string str) { //判断和是否回文
    for (int i = 0; i < str.length() / 2; i++)
        if (str[i] != str[str.length() - i - 1])
            return false;
    return true;
}

int main() {
    int rad, t = 30;  //rad进制，30次计算
    string str, rev;
    cin >> rad >> str;
    for (int s = 1; s <= 30; s++) {
        rev = str;
        reverse(rev.begin(), rev.end());
        int tmp = 0;
        for (int i = str.length() - 1; i >= 0; i--) {
            if (str[i] >= 'A') str[i] -= 7; //'9'与'A'相差8
            if (rev[i] >= 'A') rev[i] -= 7;
            str[i] += rev[i] - '0' + tmp;
            if (str[i] - '0' >= rad) {
                str[i] -= rad;
                tmp = 1;
            } else
                tmp = 0;
        }
        if (tmp)
            str = "1" + str;
        if (is_pld(str)) {
            cout << "STEP=" << s << endl;
            return 0;
        }
    }
    cout << "Impossible!" << endl;
}