//
// Created by LOKKA on 2020/7/21.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 5;

vector<int> vis(mxN);

struct Node {
    int arivT, playT, servT, vip;
};

bool cmp1 (const Node& a, const Node& b) {
    return a.arivT < b.arivT;
}

bool cmp2 (const Node& a, const Node& b) {
    return a.servT < b.servT;
}

struct Table {
    int time = 28800, cnt = 0, vip = 0;
};

int main() {
    int N;
    scanf("%d", &N);
    vector<Node> v(N);
    int hh, mm, ss;
    for (int i = 0; i < N; i++) {
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &v[i].playT, &v[i].vip);
        v[i].arivT = (hh * 60 + mm) * 60 + ss;
        if (v[i].playT > 120) v[i].playT = 120;
    }
    sort(v.begin(), v.end(), cmp1);
    int K, M, tmp;
    scanf("%d %d", &K, &M);
    vector<Table> tb(K);
    for (int i = 0; i < M; i++) {
        scanf("%d", &tmp);
        tb[tmp - 1].vip = 1;
    }

    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        int idx = -1, vip_idx = -1, MIN = INT_MAX, vip_MIN = INT_MAX;
        for (int j = 0; j < K; j++) {
            if (tb[j].time < MIN) {
                idx = j;
                MIN = tb[j].time;
            }
            if (tb[j].vip && tb[j].time < vip_MIN) {
                vip_idx = j;
                vip_MIN = tb[j].time;
            }
        }

        int pid = i;
        if (v[pid].vip && tb[vip_idx].time <= v[pid].arivT) {
            idx = vip_idx;
        }
        if (tb[idx].vip) {
            for (int k = i; k < N; k++) {
                if (!vis[k] && v[k].vip && v[k].arivT <= tb[idx].time) {
                    pid = k;
                    i--;
                    break;
                }
            }
        }

        if (v[pid].arivT >= tb[idx].time) {
            v[pid].servT = v[pid].arivT;
            tb[idx].time = v[pid].arivT + v[pid].playT * 60;
        } else {
            v[pid].servT = tb[idx].time;
            tb[idx].time += v[pid].playT * 60;
        }
        if (v[pid].servT < 75600) tb[idx].cnt++;
        vis[pid]++;
    }
    sort(v.begin(), v.end(), cmp2);
    for (int i = 0; i < N; i++) {
        if (v[i].servT >= 75600) continue;
        printf("%02d:%02d:%02d ", v[i].arivT / 3600, v[i].arivT % 3600 / 60, v[i].arivT % 60);
        printf("%02d:%02d:%02d ", v[i].servT / 3600, v[i].servT % 3600 / 60, v[i].servT % 60);
        int waitT = round((v[i].servT - v[i].arivT) * 1.0 / 60);
        printf("%d\n", waitT);
    }
    for (int i = 0; i < K; i++) {
        if (i) printf(" ");
        printf("%d", tb[i].cnt);
    }
}
