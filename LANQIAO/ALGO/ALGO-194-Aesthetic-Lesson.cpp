//
// Created by LOKKA on 2020/3/16.
//

#include <iostream>
#include <map>

using namespace std;

int a[50005];
map<int, int> mp;

int main() {
    int n, m, t, sum = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &t);
            a[i] = (a[i] * 2) + t;
        }
        mp[a[i]]++;
    }
    int max = (1 << m) - 1;
    for (int i = 0; i < n; i++) {
        int t = a[i] ^max;
        sum += mp[t];
    }
    printf("%d\n", sum / 2);
}