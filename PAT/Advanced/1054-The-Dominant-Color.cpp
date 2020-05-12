//
// Created by LOKKA on 2020/5/12.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M, N;
    cin >> M >> N;
    int len = M * N, tmp, ans;
    float haf = len / 2.0;
    map<int, int> mp;
    for (int i = 0; i < len; i++) {
        cin >> tmp;
        mp[tmp]++;
        if (mp[tmp] > haf) {
            ans = tmp;
        }
    }
    cout << ans << endl;
}