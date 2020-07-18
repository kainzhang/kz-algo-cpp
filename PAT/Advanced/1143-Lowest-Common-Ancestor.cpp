//
// Created by LOKKA on 2020/7/18.
//

#include <bits/stdc++.h>
using namespace std;

int M, N, U, V;
unordered_map<int, int> mp;

int main() {
    scanf("%d %d", &M, &N);
    vector<int> pre(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &pre[i]);
        mp[pre[i]]++;
    }
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &U, &V);
        int idx = -1;
        for (int j = 0; j < N; j++) {
            if ((pre[j] >= U && pre[j] <= V) || (pre[j] <= U && pre[j] >= V)) {
                idx = j;
                break;
            }
        }
        if (!mp[U] && !mp[V]) {
            printf("ERROR: %d and %d are not found.\n", U, V);
        } else if (!mp[U] || !mp[V]) {
            printf("ERROR: %d is not found.\n", !mp[U] ? U : V);
        } else if (pre[idx] == U) {
            printf("%d is an ancestor of %d.\n", U, V);
        } else if (pre[idx] == V) {
            printf("%d is an ancestor of %d.\n", V, U);
        } else {
            printf("LCA of %d and %d is %d.\n", U, V, pre[idx]);
        }
    }
}
