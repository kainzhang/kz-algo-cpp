//
// Created by LOKKA on 2020/5/22.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> vec(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> vec[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            vec[1][i] = min(vec[1][i], vec[1][j] + vec[j][i]);
        }
    }
    cout << vec[1][n];
}