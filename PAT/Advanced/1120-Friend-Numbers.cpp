//
// Created by LOKKA on 2020/7/1.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, cnt = 0;
    cin >> N;
    map<int, int> mp;
    // 记录 Friend ID
    for (int i = 0; i < N; i++) {
        int t, num = 0;
        cin >> t;
        while(t) {
            num += t % 10;
            t /= 10;
        }
        mp[num]++;
    }
    cout << mp.size() << endl;
    map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        if (it != mp.begin())
            cout << " ";
        cout << it->first;
    }
}