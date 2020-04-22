//
// Created by LOKKA on 2020/4/4.
// 纪念品分组（贪心、排序

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int w, n;
    scanf("%d %d", &w, &n);
    int *p = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    sort(p, p + n);
    int lo = 0, hi = n - 1, cnt = 0;
    while (lo <= hi) {
        if (p[lo] + p[hi] <= w)
            lo++;

        hi--; //大于价格上限(w)，单独组
        cnt++;
    }
    cout << cnt << endl;
    delete p;
}