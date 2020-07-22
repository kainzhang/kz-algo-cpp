//
// Created by LOKKA on 2020/7/21.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id, score = 0, pft = 0, active = 0, s[6];
    bool operator < (const Node &x) const {
        if (score == x.score) {
            if (pft == x.pft) {
                return id < x.id;
            }
            return pft > x.pft;
        }
        return score > x.score;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K, M;
    cin >> N >> K >> M;
    vector<int> p(K + 1);
    for (int i = 1; i <= K; i++) {
        cin >> p[i];
    }
    vector<Node> v(N + 1);
    int uid, pid, pso;
    for (int i = 0; i < M; i++) {
        cin >> uid >> pid >> pso;
        if (!v[uid].active) {
            v[uid].id = uid;
            v[uid].active = 1;
            fill(v[uid].s, v[uid].s + K + 1, -2);
        }
        if (pso > v[uid].s[pid]) {
            v[uid].s[pid] = pso;
            if (pso == p[pid])
                v[uid].pft++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!v[i].active) continue;
        int flag = 0;
        for (int j = 1; j <= K; j++) {
            if (v[i].s[j] >= 0) {
                v[i].score += v[i].s[j];
                flag = 1;
            }
        }
        if (!flag) v[i].active = 0;
    }
    sort(v.begin(), v.end());

    int rk = 0, pre = INT_MAX, cnt = 1;
    for (int i = 0; i <= N; i++) {
        if (!v[i].active) continue;
        if (v[i].score < pre) {
            rk += cnt;
            pre = v[i].score;
            cnt = 0;
        }
        cnt++;
        printf("%d %05d %d", rk, v[i].id, v[i].score);
        for (int j = 1; j <= K; j++) {
            switch (v[i].s[j]) {
                case -2: printf(" -"); break;
                case -1: printf(" 0"); break;
                default: printf(" %d", v[i].s[j]);
            }
        }
        printf("\n");
    }
}
