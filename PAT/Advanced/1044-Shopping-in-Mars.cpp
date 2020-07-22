//
// Created by LOKKA on 2020/7/21.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> sum;
bool ok = false;

void BinSearch(int l, int r, int x) {
    int lo = l, hi = r;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (sum[mid] == x) {
            printf("%d-%d\n", l + 1, mid);
            ok = true;
            break;
        } else if (sum[mid] < x) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    sum.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    while (!ok) {
        // sum[lo] + M = sum[hi], 二分找右边界, 即 hi
        for (int i = 0; i <= N; i++) {
            BinSearch(i, N, sum[i] + M);
        }
        M++;
    }
}
