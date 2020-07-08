//
// Created by LOKKA on 2020/7/8.
//

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;
        vector<int> vec(K), ck(1e6, 0);
        for (int i = 0; i < K; i++) {
            cin >> vec[i];
            ck[vec[i]] = 1;
        }
        bool ok = true;
        for (auto &i : vec) {
            for (auto &j : mp[i]) {
                if (ck[j] == 1) {
                    ok = false;
                    goto fin;
                }
            }
        }
        fin:
        cout << (ok ? "Yes" : "No") << endl;
    }
}
