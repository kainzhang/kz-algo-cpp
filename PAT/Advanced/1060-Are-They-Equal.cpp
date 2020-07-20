//
// Created by LOKKA on 2020/7/20.
//

#include<bits/stdc++.h>

using namespace std;

int n;
string s1, s2, a1, a2;

string translate(string s) {
    string res;
    int len = s.size(), i = 0, cnt = 0;
    for (; i < len && s[i] == '0'; i++);
    if (s[i] == '.') {
        i++;
        for (; s[i] == '0'; i++) {
            cnt--;
        }
        bool flag = false;
        for (; res.size() < n && i < len; i++) {
            res.push_back(s[i]);
            flag = true;
        }
        while (res.size() < n) {
            res.push_back('0');
        }
        if (!flag) cnt = 0;
    } else {
        for (int j = i; s[j] != '.' && j < len; j++) {
            cnt++;
        }
        for (; s[i] != '.' && res.size() < n && i < len; i++) {
            res.push_back(s[i]);
        }
        if (res.size() < n) i++;

        for (; i < len && res.size() < n; i++)
            res.push_back(s[i]);

        while (res.size() < n) {
            res.push_back('0');
        }
    }
    res += "*10^" + to_string(cnt);
    return res;
}

int main() {
    cin >> n >> s1 >> s2;
    a1 = translate(s1);
    a2 = translate(s2);
    if (a1 == a2)
        cout << "YES 0." << a1;
    else
        cout << "NO 0." << a1 << " 0." << a2;
}
