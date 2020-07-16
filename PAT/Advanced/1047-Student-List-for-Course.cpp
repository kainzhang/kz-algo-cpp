//
// Created by LOKKA on 2020/7/16.
//

#include <bits/stdc++.h>
using namespace std;

vector<string> G[2505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string stu;
        int C;
        cin >> stu >> C;
        while (C--) {
            int crs;
            cin >> crs;
            G[crs].push_back(stu);
        }
    }
    for (int i = 1; i <= K; i++) {
        int len = G[i].size();
        printf("%d %d\n", i, len);
        sort(G[i].begin(), G[i].end());
        for (int j = 0; j < len; j++) {
            printf("%s\n", G[i][j].c_str());
        }
    }
}
