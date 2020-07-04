//
// Created by LOKKA on 2020/7/2.
//

#include <bits/stdc++.h>
using namespace std;

bool is_pnum(string str) {
    int len = str.size();
    for (int i = 0; i <= len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return false;
    }
    return true;
}

string get_sum(string str) {
    string res = str;
    int len = str.size(), tmp = 0;
    for (int i = len - 1; i >= 0; i--) {
        tmp += res[i] - '0' + str[len - i - 1] - '0';
        res[i] = tmp % 10 + '0';
        tmp /= 10;
    }
    if (tmp) {
        res = "1" + res;
    }
    return res;
}

string get_rev(string str) {
    reverse(str.begin(), str.end());
    return str;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string num;
    cin >> num;
    int cnt = 0;
    while(!is_pnum(num)) {
        cnt++;
        if (cnt > 10) {
            cout << "Not found in 10 iterations." <<endl;
            return 0;
        }
        cout << num << " + " << get_rev(num) << " = ";
        num = get_sum(num);
        cout << num << endl;
    }
    cout << num << " is a palindromic number.";
}
