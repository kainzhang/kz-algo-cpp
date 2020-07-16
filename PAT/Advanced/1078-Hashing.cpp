//
// Created by LOKKA on 2020/7/16.
//

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M, N;
    cin >> M >> N;
    while(!isPrime(M)) M++;
    vector<int> vis(M, 0), ans;
    for (int i = 0; i < N; i++) {
        int num, idx, ok = 0;
        cin >> num;
        for (int j = 0; j < M; j++) {
            idx = (num + j * j) % M;
            if (!vis[idx]) {
                vis[idx] = 1;
                ok = 1;
                break;
            }
        }
        if (ok) ans.push_back(idx);
        else ans.push_back(-1);
    }
    int len = ans.size();
    for (int i = 0; i < len; i++) {
        if (i) cout << " ";
        if (ans[i] == -1) cout << "-";
        else cout << ans[i];
    }
}
