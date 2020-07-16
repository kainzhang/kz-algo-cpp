//
// Created by LOKKA on 2020/7/15.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 205;

int N, K, cost[mxN][mxN], c[mxN], hpy[mxN];
unordered_map<int, string> name;
unordered_map<string, int> idx;
vector<int> pre[mxN], path, t_path;
bool vis[mxN];

void dijkstra(int s) {
    fill(c, c + N, INT_MAX);
    c[s] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1, MIN =INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && c[j] < MIN) {
                MIN = c[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && cost[u][v] != INT_MAX) {
                if (c[u] + cost[u][v] < c[v]) {
                    c[v] = c[u] + cost[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (c[u] + cost[u][v] == c[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int cntR = 0, hapyR, avgR;
void dfs(int v) {
    t_path.push_back(v);
    if (v == 0) {
        int sum = 0;
        for (int &i : t_path) {
            sum += hpy[i];
        }
        double avg = sum * 1.0 / (t_path.size() - 1);
        if (sum > hapyR) {
            hapyR = sum;
            avgR = avg;
            path = t_path;
        } else if (sum == hapyR && avg > avgR) {
            avgR = avg;
            path = t_path;
        }
        cntR++;
    }
    for (int &i : pre[v]) {
        dfs(i);
    }
    t_path.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(cost[0], cost[0] + 205 * 205, INT_MAX);
    string city;
    cin >> N >> K >> city;
    idx[city] = 0;
    name[0] = city;
    int happy;
    for (int i = 1; i < N; i++) {
        cin >> city >> happy;
        idx[city] = i;
        name[i] = city;
        hpy[i] = happy;
    }
    for (int i = 0; i < K; i++) {
        string cA, cB;
        int l;
        cin >> cA >> cB >> l;
        int a = idx[cA], b = idx[cB];
        cost[a][b] = cost[b][a] = l;
    }
    dijkstra(0);
    dfs(idx["ROM"]);
    cout << cntR << " " << c[idx["ROM"]] << " " << hapyR << " " << avgR << endl;
    int len = path.size();
    for (int i = len - 1; i >= 0; i--) {
        if (i < len - 1) cout << "->";
        cout << name[path[i]];
    }
}
