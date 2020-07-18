//
// Created by LOKKA on 2020/7/17.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1020;

int N, M, K, Ds, G[mxN][mxN], d[mxN];
bool vis[mxN];

int ans_id = -1;
double ans_dis = -1, ans_avg = DBL_MAX;
void dijkstra(int s) {
    fill(d, d + mxN, INT_MAX);
    d[s] = 0;
    fill(vis, vis + mxN, false);
    for (int i = 0; i < N + M; i++) {
        int u = -1, MIN = INT_MAX;
        for (int j = 1; j <= N + M; j++) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 1; v <= N + M; v++) {
            if (!vis[v] && G[u][v] && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
            }
        }
    }
    int minD = INT_MAX, sum = 0;
    for (int i = 1; i <= N; i++) {
        if (d[i] > Ds) {
            return;
        } else if (d[i] < minD) {
            minD = d[i];
        }
        sum += d[i];
    }
    double avg = sum * 1.0 / N;
    if (minD > ans_dis) {
        ans_dis = minD;
        ans_id = s;
        ans_avg = avg;
    } else if (minD == ans_dis && avg < ans_avg) {
        ans_id = s;
        ans_avg = avg;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K >> Ds;
    string sa, sb;
    int a, b, l;
    for (int i = 0; i < K; i++) {
        cin >> sa >> sb >> l;
        if (sa[0] == 'G') {
            sa = sa.substr(1);
            a = stoi(sa) + N;
        } else {
            a = stoi(sa);
        }
        if (sb[0] == 'G') {
            sb = sb.substr(1);
            b = stoi(sb) + N;
        } else {
            b = stoi(sb);
        }
        G[a][b] = G[b][a] = l;
    }
    for (int i = N + 1; i <= N + M; i++) {
        dijkstra(i);
    }
    if (ans_id == - 1) {
        printf("No Solution");
    } else {
        printf("G%d\n%.1f %.1f", ans_id - N, ans_dis, ans_avg);
    }
}
