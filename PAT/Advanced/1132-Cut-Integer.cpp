//
// Created by LOKKA on 2020/7/2.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string Z;
        cin >> Z;
        int len = Z.length();
        int z = stoi(Z);
        // 左半段
        int l = stoi(Z.substr(0, len / 2));
        // 右半段
        int r = stoi(Z.substr(len / 2, len));
        // 先判断是否为 0
        if (l * r &&  z % (l * r) == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
