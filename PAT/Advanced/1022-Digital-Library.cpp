//
// Created by LOKKA on 2020/7/11.
//

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string> > title, athr, kwds, pub, yr;

void get_ans(unordered_map<string, vector<string> > &mp, string str) {
    if (mp[str].empty()) {
        cout << "Not Found" << endl;
        return;
    }
    set<string> res(mp[str].begin(), mp[str].end());
    for (auto &i : res) {
        cout << i << endl;
    }
}

int main() {
    int N;
    cin >> N;
    getchar();
    while (N--) {
        string id, tt, aa, kk, pp, yy;
        getline(cin, id);
        getline(cin, tt);
        title[tt].push_back(id);
        getline(cin, aa);
        athr[aa].push_back(id);
        while (cin >> kk) {
            char t = getchar();
            kwds[kk].push_back(id);
            if (t == '\n') break;
        }
        getline(cin, pp);
        pub[pp].push_back(id);
        getline(cin, yy);
        yr[yy].push_back(id);
    }
    int M;
    cin >> M;
    getchar();
    while (M--) {
        int sign;
        string str;
        getline(cin, str);
        sign = str[0] - '0';
        str = str.substr(3);
        cout << sign << ": " << str << endl;
        switch (sign) {
            case 1: get_ans(title, str); break;
            case 2: get_ans(athr, str); break;
            case 3: get_ans(kwds, str); break;
            case 4: get_ans(pub, str); break;
            case 5: get_ans(yr, str); break;
        }
    }
}
