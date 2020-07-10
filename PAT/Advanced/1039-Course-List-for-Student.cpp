//
// Created by LOKKA on 2020/7/10.
//

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<int> > mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    while (K--) {
        int crs, num;
        cin >> crs >> num;
        while (num--) {
            string one;
            cin >> one;
            mp[one].push_back(crs);
        }
    }
    while (N--) {
        string one;
        cin >> one;
        cout << one << " ";
        vector<int> res = mp[one];
        sort(res.begin(), res.end());
        int len = res.size();
        cout << len;
        for (auto &i : res) {
            cout << " " << i;
        }
        cout << endl;
    }
}
