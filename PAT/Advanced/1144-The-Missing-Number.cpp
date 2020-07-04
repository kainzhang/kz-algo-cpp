//
// Created by LOKKA on 2020/7/2.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, t;
    cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if (t > 0)
            mp[t]++;
    }
    int ans = 0;
    while(++ans) {
        if (!mp[ans]) {
            cout << ans << endl;
            return 0;
        }
    }
}
