//
// Created by LOKKA on 2020/5/26.
//

#include <bits/stdc++.h>

using namespace std;

string fir[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string sec[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void toMars(string str) {
    int num = stoi(str);
    if (num / 13) {
        cout << sec[num / 13];
        if (num % 13)
            cout << " " << fir[num % 13];
    } else {
        cout << fir[num % 13];
    }
    cout << endl;
}

void toEarth(string str) {
    int i = 0;  // 一个火星文: i = 0, 两个火星文: i = 1
    string num[2];
    for (char c : str) {
        if (c == ' ') { // 笨笨地划分字符串...
            i++;
            continue;
        }
        num[i].push_back(c);
    }
    int sum = 0, f = 0, s = 0;
    for (int j = 0; j < 13; j++) {
        if (fir[j] == num[i]) f = j;    // 个位
        if (sec[j] == num[0]) s = j;    // 十位
    }
    sum += s * 13 + f;
    cout << sum << endl;
}

int main() {
    int N;
    cin >> N;
    getchar();
    while (N--) {
        string str;
        getline(cin, str);
        if (isdigit(str[0])) toMars(str);
        else toEarth(str);
    }
}