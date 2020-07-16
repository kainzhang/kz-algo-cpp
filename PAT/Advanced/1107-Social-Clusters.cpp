//
// Created by LOKKA on 2020/7/15.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> dad, is_root, hoby(1005, 0);

int FindDad(int x) {
    int a = x;
    while (x != dad[x]) x = dad[x];
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
    if (da != db) {
        dad[da] = db;
    }
}

void Init(int N) {
    dad.resize(N + 1), is_root.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        dad[i] = i;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    Init(N);
    for (int i = 1; i <= N; i++) {
        int K;
        scanf("%d:", &K);
        while (K--) {
            int t;
            scanf("%d", &t);
            if (!hoby[t]) hoby[t] = i;
            Union(i, FindDad(hoby[t]));
        }
    }
    for (int i = 1; i <= N; i++) {
        is_root[FindDad(i)]++;
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (is_root[i]) cnt++;
    }
    cout << cnt << endl;
    sort(is_root.begin(), is_root.end(), greater<int>());
    for (int i = 0; i < cnt; i++) {
        if (i) cout << " ";
        cout << is_root[i];
    }
}