//
// Created by LOKKA on 2020/7/21.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 505;
int dis[mxN][mxN], tim[mxN][mxN];
int min_dis = INT_MAX, min_time = INT_MAX, d[mxN], t[mxN], preD[mxN], preT[mxN], c[mxN];

void dijkstraD(int s, int N) {
    vector<int> vis(N, 0);
    fill(d, d + mxN, INT_MAX);
    d[s] = 0;
    fill(t, t + mxN, INT_MAX);
    t[s] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1, mnD = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && d[j] < mnD) {
                mnD = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = 1;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && dis[u][v] != INT_MAX) {
                if (d[u] + dis[u][v] < d[v]) {
                    d[v] = d[u] + dis[u][v];
                    t[v] = t[u] + tim[u][v];
                    preD[v] = u;
                } else if (d[u] + dis[u][v] == d[v] && t[u] + tim[u][v] < t[v]) {
                    t[v] = t[u] + tim[u][v];
                    preD[v] = u;
                }
            }
        }
    }
}

void dijkstraT(int s, int N) {
    vector<int> vis(N, 0);
    fill(t, t + mxN, INT_MAX);
    t[s] = 0;
    fill(c, c + mxN, INT_MAX);
    c[s] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1, mnD = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && t[j] < mnD) {
                mnD = t[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = 1;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && tim[u][v] != INT_MAX) {
                if (t[u] + tim[u][v] < t[v]) {
                    t[v] = t[u] + tim[u][v];
                    c[v] = c[u] + 1;
                    preT[v] = u;
                } else if (t[u] + tim[u][v] == t[v] && c[u] + 1 < c[v]) {
                    c[v] = c[u] + 1;
                    preT[v] = u;
                }
            }
        }
    }
}

int src, des;
void PrintPath(int v, int *pre) {
    if (v == src) {
        printf("%d", v);
        return;
    }
    PrintPath(pre[v], pre);
    printf(" -> %d", v);
}

bool IsEqual(int *A, int *B) {
    int tmp = des;
    while(tmp != src) {
        if (A[tmp] != B[tmp])
            return false;
        tmp = A[tmp];
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(dis[0], dis[0] + mxN * mxN, INT_MAX);
    fill(tim[0], tim[0] + mxN * mxN, INT_MAX);
    int N, M, V1, V2, one, ln, tm;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> V1 >> V2 >> one >> ln >> tm;
        dis[V1][V2] = ln;
        tim[V1][V2] = tm;
        if (!one) {
            dis[V2][V1] = ln;
            tim[V2][V1] = tm;
        }
    }
    cin >> src >> des;
    dijkstraD(src, N);
    dijkstraT(src, N);
    if (IsEqual(preD, preT)) {
        printf("Distance = %d; Time = %d: ", d[des], t[des]);
        PrintPath(des, preD);
    } else {
        printf("Distance = %d: ", d[des]);
        PrintPath(des, preD);
        printf("\nTime = %d: ", t[des]);
        PrintPath(des, preT);
    }
}
