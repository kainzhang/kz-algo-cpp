//
// Created by LOKKA on 2020/7/21.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 5;

unordered_map<int, int> mp, cnt;
vector<int> dad(mxN);

int FindDad(int x) {
    int a = x;
    while (x != dad[x])
        x = dad[x];
    while (a != dad[a]) {
        int z = a;
        a = dad[a];
        dad[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int dA = FindDad(a);
    int dB = FindDad(b);
    if (dA != dB) dad[dA] = dB;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K, pre;
    cin >> N;
    for (int i = 1; i <= mxN; i++) {
        dad[i] = i;
    }
    for (int i = 0; i < N; i++) {
        cin >> K;
        int id;
        for (int j = 0; j < K; j++) {
            cin >> id;
            if (j) Union(pre, id);
            else pre = id;
            mp[id] = 1;
        }
    }

    int cntB = 0;
    for (int i = 1; i <= mxN; i++) {
        if (mp[i]) {
            cnt[FindDad(i)]++;
            cntB++;
        }
    }

    int Q, a, b;
    cin >> Q;
    cout << cnt.size() << " " << cntB << endl;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        cout << (FindDad(a) == FindDad(b) ? "Yes" : "No") << endl;;
    }
}
