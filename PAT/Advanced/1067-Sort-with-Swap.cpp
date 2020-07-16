//
// Created by LOKKA on 2020/7/16.
//

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        mp[num] = i;
    }
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (mp[i] != i) {
            while (mp[0] != 0) {
                swap(mp[0], mp[mp[0]]);
                cnt++;
            }
        }
        if (mp[i] != i) {
            swap(mp[0], mp[i]);
            cnt++;
        }
    }
    cout << cnt << endl;
}
