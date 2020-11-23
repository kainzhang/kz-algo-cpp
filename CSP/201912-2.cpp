//
// Created by Kain Zhang on 2020/9/1.
//

#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> mp;
vector<pair<int, int> > vec(1005);
vector<int> res(5);

void func(int x, int y) {
    if (mp[make_pair(x, y + 1)] && mp[make_pair(x, y - 1)] && mp[make_pair(x + 1, y)] && mp[make_pair(x - 1, y)]) {
        res[mp[make_pair(x - 1, y - 1)] + mp[make_pair(x - 1, y + 1)] + mp[make_pair(x + 1, y - 1)] + mp[make_pair(x + 1, y + 1)]]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        vec[i] = make_pair(x, y);
        mp[vec[i]] = 1;
    }
    for (auto &i : vec) {
        func(i.first, i.second);
    }
    for (int &i : res) {
        cout << i << endl;
    }
}

/*
7
1 2
2 1
0 0
1 1
1 0
2 0
0 1
 */