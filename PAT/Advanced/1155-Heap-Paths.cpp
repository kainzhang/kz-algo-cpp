//
// Created by LOKKA on 2020/7/14.
//

#include <bits/stdc++.h>
using namespace std;

int N, mx = 0, mn = 0;
vector<int> v, res;

void dfs(int root) {
    res.push_back(v[root]);
    if (root * 2 > N && root * 2 + 1 > N ) {
        int len = res.size();
        for (int i = 0; i < len; i++) {
            if (i) cout << " ";
            cout << res[i];
        }
        cout << endl;
    } else {
        if (root * 2 + 1 <= N) {
            if (v[root] >= v[root * 2 + 1]) mx = 1;
            if (v[root] <= v[root * 2 + 1]) mn = 1;
            dfs(root * 2 + 1);
        }
        if (root * 2 <= N) {
            if (v[root] >= v[root * 2]) mx = 1;
            if (v[root] <= v[root * 2]) mn = 1;
            dfs(root * 2);
        }
    }
    res.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    dfs(1);
    if (mx && !mn) {
        cout << "Max Heap" << endl;
    } else if (!mx && mn) {
        cout << "Min Heap" << endl;
    } else {
        cout << "Not Heap" << endl;
    }
}
