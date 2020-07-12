//
// Created by LOKKA on 2020/7/12.
//

#include <bits/stdc++.h>
using namespace std;

int G[205][205];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Nv, Ne;
    cin >> Nv >> Ne;
    for (int i = 0; i < Ne; i++) {
        int a, b;
        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;
        vector<int> v(K), mp(205, 0);
        for (int j = 0; j < K; j++) {
            cin >> v[j];
            mp[v[j]] = 1;
        }
        bool isC = true, isM = true;
        for (int j = 0; j < K; j++) {
            if (!isC) break;
            for (int k = j + 1; k < K; k++) {
                if (G[v[j]][v[k]] == 0) {
                    isC = false;
                    cout << "Not a Clique" << endl;
                    break;
                }
            }
        }
        if (!isC) continue;
        for (int j = 1; j <= Nv; j++) {
            if (!mp[j]) {
                for (int k = 0; k < K; k++) {
                    if (!G[v[k]][j]) break;
                    if (k == K - 1) isM = false;
                }
            }
            if (!isM) {
                cout << "Not Maximal" << endl;
                break;
            }
        }
        if (isM) cout << "Yes" << endl;
    }
}