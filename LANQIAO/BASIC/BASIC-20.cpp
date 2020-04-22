//
// Created by LOKKA on 2020/4/6.
// 数的读法 （有 Bug

#include <iostream>

using namespace std;

string num[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string dig[] = {"", "", "shi", "bai", "qian", "wan", "shi", "bai", "qian", "yi", "shi", "bai"};

//              0   1     2      3      4       5      6      7      8      9     10     11
int main() {
    string str;
    cin >> str;
    int len = str.size();
    for (int i = 0; i < len; i++) {
        int t = len - i;
        if (str[i] == '0') {
            if (t == 9 || t == 5 || t == 1)
                cout << dig[t] << " ";
            else if (str[i + 1] != '0')
                cout << num[0] << " ";
        } else if (str[i] == '1' && (t == 10 || t == 6 || t == 2)) {
            if (i > 0) {
                if (str[i - 1] == '0')
                    cout << num[1] << " ";
            }
            cout << dig[t] << " ";
        } else {
            cout << num[str[i] - '0'] << " ";
            cout << dig[t] << " ";
        }
    }
}