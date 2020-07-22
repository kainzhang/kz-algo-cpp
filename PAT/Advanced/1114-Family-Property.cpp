//
// Created by LOKKA on 2020/7/21.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 5;

struct Node {
    int id, num, area;
};

struct Res {
    int id, cnt = 0, flag = 0;
    double num = 0, area = 0;
    bool operator < (const Res &x) const {
        return (area == x.area ? id < x.id : area > x.area);
    }
};

vector<int> dad(mxN);
unordered_map<int, int> vis;

int FindDad(int x) {
    int a = x;
    while (x != dad[x]) {
        x = dad[x];
    }
    while (a != dad[a]) {
        int z = a;
        a = dad[a];
        dad[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int da = FindDad(a);
    int db = FindDad(b);
    if (da > db) dad[da] = db;
    else dad[db] = da;
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i < mxN; i++) {
        dad[i] = i;
    }
    vector<Node> v(N);
    for (int i = 0; i < N; i++) {
        int K, fa, mo, chd;
        cin >> v[i].id >> fa >> mo >> K;
        vis[v[i].id]++;
        if (fa != -1) {
            Union(v[i].id, fa);
            vis[fa]++;
        }
        if (mo != -1) {
            Union(v[i].id, mo);
            vis[mo]++;
        }
        for (int j = 0; j < K; j++) {
            cin >> chd;
            Union(v[i].id, chd);
            vis[chd]++;
        }
        cin >> v[i].num >> v[i].area;
    }
    vector<Res> ans(mxN);
    for (int i = 0; i < N; i++) {
        int root = FindDad(v[i].id);
        ans[root].id = root;
        ans[root].num += v[i].num;
        ans[root].area += v[i].area;
        ans[root].flag = 1;
    }
    int cntF = 0;
    for (auto &i : vis) {
        int root = FindDad(i.first);
        ans[root].cnt++;
        if (ans[i.first].flag) cntF++;
    }
    for(int i = 0; i < 10000; i++) {
        if(ans[i].flag) {
            ans[i].num = ans[i].num * 1.0 / ans[i].cnt;
            ans[i].area = ans[i].area * 1.0 / ans[i].cnt;
        }
    }
    sort(ans.begin(), ans.begin() + mxN);
    printf("%d\n", cntF);
    for (int i = 0; i < cntF; i++) {
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].cnt, ans[i].num, ans[i].area);
    }
}
