//
// Created by LOKKA on 2020/7/11.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 205;

int G[mxN][mxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    while (M--) {
        int a, b, l;
        cin >> a >> b >> l;
        G[a][b] = G[b][a] = l;
    }
    int K, mnI, mnS = INT_MAX;
    cin >> K;
    for (int i = 1; i <= K; i++) {
        int n, sum = 0, ok = 1;
        cin >> n;
        vector<int> qry(n);
        set<int> ck;
        for (int j = 0; j < n; j++) {
            cin >> qry[j];
            ck.insert(qry[j]);
            if (j) {
                if (!G[qry[j - 1]][qry[j]]) {
                    ok = 0;
                }
                sum += G[qry[j - 1]][qry[j]];
            }
        }
        cout << "Path " << i << ": ";
        if (!ok) {
            cout << "NA (Not a TS cycle)" << endl;
        } else if (qry[0] != qry[n - 1] || ck.size() != N) {
            cout << sum << " (Not a TS cycle)" << endl;
        } else if (n - 1 != N) {
            cout << sum << " (TS cycle)" << endl;
            if (sum < mnS) {
                mnS = sum;
                mnI = i;
            }
        } else {
            cout << sum << " (TS simple cycle)" << endl;
            if (sum < mnS) {
                mnS = sum;
                mnI = i;
            }
        }
    }
    cout << "Shortest Dist(" << mnI << ") = " << mnS << endl;
}
