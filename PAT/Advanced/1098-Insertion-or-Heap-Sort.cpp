//
// Created by LOKKA on 2020/7/15.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;

void DownAdjust(int lo, int hi) {
    int i = 1, j = i * 2;
    while (j <= hi) {
        if (j + 1 <= hi && b[j] < b[j + 1]) j++;
        if (b[i] >= b[j]) break;
        swap(b[i], b[j]);
        i = j, j = i * 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    a.resize(N + 1), b.resize(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> b[i];
    int p = 2;
    while (p <= N && b[p] >= b[p - 1]) p++;
    int tmp = p;
    while (p <= N && b[p] == a[p]) p++;
    if (p == N + 1) {
        cout << "Insertion Sort" << endl;
        sort(b.begin() + 1, b.begin() + tmp + 1);
    } else {
        cout << "Heap Sort" << endl;
        p = N;
        while (p > 2 && b[p] >= b[1]) p--;
        swap(b[1], b[p]);
        DownAdjust(1, p - 1);
    }
    for (int i = 1; i <= N; i++) {
        if (i > 1) cout << " ";
        cout << b[i];
    }
}
