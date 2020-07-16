//
// Created by LOKKA on 2020/7/15.
//

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v, post;

bool is_max, is_min;
void dfs(int r) {
    if (r * 2 <= M) {
        if (v[r * 2] <= v[r]) is_max = true;
        if (v[r * 2] >= v[r]) is_min = true;
        dfs(r * 2);
    }
    if (r * 2 + 1 <= M) {
        if (v[r * 2 + 1] <= v[r]) is_max = true;
        if (v[r * 2 + 1] >= v[r]) is_min = true;
        dfs(r * 2 + 1);
    }
    post.push_back(v[r]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    v.resize(M + 1);
    while(N--) {
        for (int i = 1; i <= M; i++) {
            cin >> v[i];
        }
        post.clear();
        is_max = is_min = false;
        dfs(1);
        if (is_max && !is_min) {
            cout << "Max Heap" << endl;
        } else if (!is_max && is_min) {
            cout << "Min Heap" << endl;
        } else {
            cout << "Not Heap" << endl;
        }
        for (int i = 0; i < M; i++) {
            if (i) cout << " ";
            cout << post[i];
        }
        cout << endl;
    }
}
