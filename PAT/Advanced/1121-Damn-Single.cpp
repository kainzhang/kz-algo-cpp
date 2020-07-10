//
// Created by LOKKA on 2020/7/10.
//

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while (N--) {
        string a, b;
        cin >> a >> b;
        mp[a] = b;
        mp[b] = a;
    }
    int M;
    cin >> M;
    map<string, int> tmp;
    while (M--) {
        string one;
        cin >> one;
        tmp[one]++;
    }
    vector<string> res;
    for (auto &i : tmp) {
        if (mp[i.first].empty() || !tmp[mp[i.first]]) {
            res.push_back(i.first);
        }
    }
    cout << res.size() << endl;
    int flag = 0;
    for (auto &i : res) {
        if (flag) cout << " ";
        cout << i;
        flag++;
    }
}
