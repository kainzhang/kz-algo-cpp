//
// Created by LOKKA on 2020/5/12.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N;
    vector<int> ext(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> ext[i];
        ext[i] += ext[i - 1];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, r, l;
        cin >> a >> b;
        r = abs(ext[b - 1] - ext[a - 1]);
        if (a < b)
            l = ext[a - 1] + (ext[N] - ext[b - 1]);
        else
            l = ext[b - 1] + (ext[N] - ext[a - 1]);
        cout << (r < l ? r : l) << endl;
    }
}