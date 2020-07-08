//
// Created by LOKKA on 2020/7/7.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    getline(cin, str);
    map<string, int> mp;
    string tmp;
    int len = str.size();

    // 注意最后一个单词，最后一个字符为 '\0'
    for (int i = 0; i <= len; i++) {
        if (isalnum(str[i])) {
            tmp.push_back(tolower(str[i]));
        } else {
            if (tmp.size()) mp[tmp]++;
            tmp.clear();
        }
    }
    int mx = 0;
    string ans;
    for (auto &i : mp) {
        if (i.second > mx) {
            mx = i.second;
            ans = i.first;
        }
    }
    cout << ans << " " << mx << endl;
}
