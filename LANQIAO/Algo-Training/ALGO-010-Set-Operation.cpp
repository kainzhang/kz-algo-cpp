//
// Created by LOKKA on 2020/3/19.
// 集合运算

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
map<int, int> mp;

int main() {
    int n, m, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        mp[t] += 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        mp[t] += 2;
    }
    map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        if (it->second == 3)
            printf("%d ", it->first);
    }
    printf("\n");
    for (it = mp.begin(); it != mp.end(); it++) {
        printf("%d ", it->first);
    }
    printf("\n");
    for (it = mp.begin(); it != mp.end(); it++) {
        if (it->second == 1)
            printf("%d ", it->first);
    }
    printf("\n");
}