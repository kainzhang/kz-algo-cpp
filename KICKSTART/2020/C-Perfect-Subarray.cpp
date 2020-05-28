//
// Created by LOKKA on 2020/5/17.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxN = 1e5;
unordered_map<int ,int> mp;

ll solve() {
    int N, minS = 0, maxS;
    ll res = 0;
    cin >> N;
    vector<int> sum(mxN);
    cin >> sum[1];
    for (int i = 2; i <= N; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
        minS = min(sum[i], minS);
        maxS = max(sum[i], maxS);
    }
    mp.clear();
    mp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j * j < maxS; j++) {
            if (mp.count(sum[i] - j * j))
                res += mp[sum[i] - j * j];
            if (sum[i] - j * j < minS)
                break;
        }
        mp[sum[i]]++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: %lld\n", i, solve());
    }
}