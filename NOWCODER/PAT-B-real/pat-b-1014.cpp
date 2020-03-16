//
// Created by LOKKA on 2020/3/16.
// 1014 科学计数法

#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int dot = 0, dote, sign = 1, flag = 0, index = 0, end = 0;
    for (int i = 0; i < str.length();) {
        if (flag) {
            while (str[i] == 0) i++;
            while (i < str.length()) {
                index *= 10;
                index += str[i] - '0';
                i++;
            }
            break;
        } else {
            if (str[i] == '.') dot = i;
            if (str[i] == 'E') {
                if (str[i + 1] == '-') sign = 0;
                else sign = 1;
                flag++;
                end = i - 1;
                i++;
            }
            i++;
        }
    }
    if (str[0] == '-') cout << '-';
    if (sign) dote = dot + index;
    else dote = dot - index;
    int fl = 0;
    while (dote < dot) {
        cout << '0';
        dote++;
        if (!fl) {
            cout << '.';
            fl++;
        }
    }
    cout << str[dot - 1];
    for (int i = dot + 1; i <= end; i++) {
        cout << str[i];
        if (i == dote) cout << '.';
    }
    while (dote > end) {
        cout << '0';
        dote--;
    }
}