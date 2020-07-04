//
// Created by LOKKA on 2020/5/16.
//

#include <bits/stdc++.h>
using namespace std;

int a[1025][1025];

void copy(int tox, int toy, int fromx, int fromy, int r) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            a[tox + i][toy + j] = a[fromx + i][fromy + j];
}

void get_table(int k) {
    int n = 1 << k;
    for (int i = 0; i < n; i++) {
        a[0][i] = i + 1;
    }
    for (int r = 1; r < n; r <<= 1) {
        for (int i = 0; i < n; i += 2 * r) {
            copy(r, r + i, 0, i, r);
            copy(r, i, 0, r + i, r);
        }
    }
}

int main() {
    int k;
    cin >> k;
    get_table(k);
    for (int i = 0; i < 1 << k; i++) {
        for (int j = 0; j < 1 << k; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}