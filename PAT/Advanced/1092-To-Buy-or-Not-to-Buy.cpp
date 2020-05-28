//
// Created by LOKKA on 2020/5/16.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str1, str2;
    cin >> str1 >> str2;
    map<char ,int> mp;
    for (char c : str1) {
        mp[c]++;
    }
    bool ok = true;
    for (char c : str2) {
        mp[c]--;
        if (mp[c] < 0)
            ok = false;
    }
    int ans = 0;
    map<char, int>::iterator it;
    if (ok) {
        for (it = mp.begin(); it != mp.end(); it++)
            ans += it->second;
    } else {
        for (it = mp.begin(); it != mp.end(); it++)
            if (it->second < 0)
                ans -= it->second;
    }
    cout << (ok ? "Yes " : "No ") << ans << endl;
}