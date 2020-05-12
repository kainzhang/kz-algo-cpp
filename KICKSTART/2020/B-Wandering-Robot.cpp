//
// Created by LOKKA on 2020/5/7.
//

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e5;
double ftr[MAXN];

double getIdx(int x, int y) {
    return ftr[x + y - 2] - ftr[x - 1] - ftr[y - 1] - x - y + 1;
}

double solve() {
    int W, H, L, U, R, D;
    cin >> W >> H >> L >> U >> R >> D;
    double res = 0;
    if (R < W)
        for (int i = 1; i < U; i++)
            res += pow(2, getIdx(i, R));

    if (D < H)
        for (int j = 1; j < L; j++)
            res += pow(2, getIdx(D, j));

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < MAXN; i++)
        ftr[i] = ftr[i - 1] + log2(i);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: %.6f\n", i, solve());
    }
}