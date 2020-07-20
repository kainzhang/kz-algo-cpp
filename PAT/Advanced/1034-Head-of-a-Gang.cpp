//
// Created by LOKKA on 2020/7/20.
//

#include <bits/stdc++.h>
using namespace std;

map<string, vector<string> > G;
map<string, int> w;
unordered_map<string ,int> vis;

string mx_name;
int mx_time, cnt, tot_time;
void dfs(string name) {
    int time = w[name];
    if (time > mx_time) {
        mx_time = time;
        mx_name = name;
    }
    tot_time += time;
    cnt++;
    vis[name] = 1;
    int len = G[name].size();
    for (int i = 0; i < len; i++) {
        if (!vis[G[name][i]]) {
            dfs(G[name][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    string a, b;
    int time;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> time;
        G[a].push_back(b);
        G[b].push_back(a);
        w[a] += time;
        w[b] += time;
    }
    map<string, int> ans;
    for (auto &i : w) {
        if (!vis[i.first]) {
            cnt = mx_time = tot_time = 0;
            dfs(i.first);
            if (tot_time / 2 > K && cnt > 2) {
                ans[mx_name] = cnt;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i.first << " " << i.second << endl;
    }
}
