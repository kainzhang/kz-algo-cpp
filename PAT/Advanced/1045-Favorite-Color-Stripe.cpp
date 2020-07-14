//
// Created by LOKKA on 2020/7/13.
//

#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int num;
        cin >> num;
        mp[num] = i;
    }
    int L;
    vector<int> v;
    cin >> L;
    for (int i = 0; i < L; i++) {
        int num;
        cin >> num;
        if (!mp[num]) continue;
        v.push_back(mp[num]);
    }
    int len = v.size();
    vector<int> dp(len + 1);
    int maxn = 0;
    for(int i = 0; i < len; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(v[i] >= v[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxn = max(dp[i], maxn);
    }
    cout << maxn << endl;
}
