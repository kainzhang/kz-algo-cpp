//
// Created by LOKKA on 2020/4/20.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int H[105], ans = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> H[i];

        for (int i = 1; i < N - 1; i++)
            if (H[i] > H[i - 1] && H[i] > H[i + 1])
                ans++;

        printf("Case #%d: %d\n", t, ans);
    }
}