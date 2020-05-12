//
// Created by LOKKA on 2020/3/16.
//

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        getchar();
        string str[105];
        for (int i = 0; i < n; i++) {
            getline(cin, str[i]);
            reverse(str[i].begin(), str[i].end());
        }
        bool flag = true;
        string res = "";
        for (int i = 0; i < str[0].size(); i++) {
            char ch = str[0][i];
            for (int j = 1; j < n; j++) {
                if (str[j][i] != ch) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
            res = ch + res;
        }
        if (res == "") cout << "nai" << endl;
        else cout << res << endl;
    }
}