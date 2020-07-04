//
// Created by LOKKA on 2020/7/1.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M, N, S;
    cin >> M >> N >> S;
    map<string, int> mp;
    for (int i = 1; i <= M; i++) {
        string str;
        cin >> str;
        // 判断中奖
        if (i == S) {
            // 判断是否已拿奖
            if (mp[str]) {
                // 中奖序号顺延
                S++;
                continue;
            }
            cout << str << endl;
            mp[str]++;
            S += N;
        }
    }
    if (mp.size() == 0) {
        cout << "Keep going..." << endl;
    }
}
