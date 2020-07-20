//
// Created by LOKKA on 2020/7/19.
//

#include <bits/stdc++.h>
using namespace std;

int N, M, pre, now;
int K, s, d, min_cnt, min_tsf;
vector<int> G[10005], tmp_path, path, vis(10005);
unordered_map<int, int> line;

int TransferCnt(vector<int> v) {
    int cnt = -1, pre_line = 0, len = v.size();
    for (int i = 1; i < len; i++) {
        if (line[v[i - 1] * 10000 + v[i]] != pre_line) cnt++;
        pre_line = line[v[i - 1] * 10000 + v[i]];
    }
    return cnt;
}

void dfs(int node, int cnt) {
    if (node == d ) {
        if (cnt < min_cnt || (cnt == min_cnt && TransferCnt(tmp_path) < min_tsf)) {
            min_cnt = cnt;
            min_tsf = TransferCnt(tmp_path);
            path = tmp_path;
        }
        return;
    }
    int len = G[node].size();
    for (int i = 0; i < len; i++) {
        if (!vis[G[node][i]]) {
            vis[G[node][i]] = 1;
            tmp_path.push_back(G[node][i]);
            dfs(G[node][i], cnt + 1);
            vis[G[node][i]] = 0;
            tmp_path.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M >> pre;
        for (int j = 1; j < M; j++) {
            cin >> now;
            G[pre].push_back(now);
            G[now].push_back(pre);
            line[pre * 10000 + now] = line[now * 10000 + pre] = i + 1;
            pre = now;
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> s >> d;
        min_cnt = min_tsf = INT_MAX;
        tmp_path.clear();
        tmp_path.push_back(s);
        vis[s] = 1;
        dfs(s, 0);
        vis[s] = 0;
        printf("%d\n", min_cnt);
        int pre_line = 0, pre_tsf = s, len = path.size();
        for (int j = 1; j < len; j++) {
            if (line[path[j - 1] * 10000 + path[j]] != pre_line) {
                if (pre_line)
                    printf("Take Line#%d from %04d to %04d.\n", pre_line, pre_tsf, path[j - 1]);
                pre_line = line[path[j - 1] * 10000 + path[j]];
                pre_tsf = path[j - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", pre_line, pre_tsf, d);
    }
}
