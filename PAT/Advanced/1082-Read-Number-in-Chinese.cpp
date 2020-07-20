//
// Created by LOKKA on 2020/7/20.
//

#include <bits/stdc++.h>
using namespace std;

string num[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string jw[] = {"", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};

int main() {
    string str;
    cin >> str;
    int flag = 0;
    if (str[0] == '-') {
        printf("Fu");
        str = str.substr(1);
        flag++;
    }
    int len = str.size(), zero = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '0' && i) {
            zero = 1;
        } else {
            if (zero) printf(" ling");
            if (flag++) printf(" ");
            printf("%s", num[str[i] - '0'].c_str());
            zero = 0;
        }
        int tmp = len - i - 1;
        if (tmp && (!zero || tmp == 4 || tmp == 8)) { // tmp为 0时输出 "" 会格式错误
            printf(" %s", jw[tmp % 9].c_str());
        }
    }
}
