//
// Created by LOKKA on 2020/7/18.
//

#include <bits/stdc++.h>
using namespace std;

int G[205][205];

int main() {
    int N, M, K, a, b, n;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        G[a][b] = G[b][a] = 1;
    }
    scanf("%d", &K);
    while (K--) {
        vector<int> vis(N + 1, 0);
        scanf("%d", &n);
        int flag = 1, fst, pre, now, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!i) {
                scanf("%d", &pre);
                fst = pre;
            } else {
                scanf("%d", &now);
                vis[now]++;
                if (!G[pre][now] || vis[now] == 2) {
                    flag = 0;
                }
                pre = now;
            }
        }
        if (n != N + 1 || now != fst) flag = 0;
        if (!flag) printf("NO\n");
        else printf("YES\n");
    }
}
