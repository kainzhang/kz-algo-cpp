//
// Created by LOKKA on 2020/5/26.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    string str;
    cin >> str;
    unordered_map<char, int> nor, stu;  // 正常的, 卡住的
    int len = str.size(), cnt = 1;
    for (int i = 0; i < len; i++) {
        if (str[i] == str[i + 1]) {
            cnt++;
            if (cnt % k == 0 && !nor.count(str[i])) {
                stu[str[i]]++; // 数量为 k 的整数倍, 且未被标记为正常，则标记为卡住
            } else {
                stu.erase(str[i]);
            }
        } else {
            if (cnt % k) {
                stu.erase(str[i]);
                nor[str[i]]++;
            }
            cnt = 1;
        }
    }
    for (int i = 0; i < len; i++) {
        if (!nor.count(str[i])) {
            cout << str[i];
            nor[str[i]]++;
        }
    }
    cout << endl;
    for (int i = 0; i < len;) {
        cout << str[i];
        if (stu.count(str[i])) i += k;
        else i++;
    }
    cout << endl;
}