//
// Created by LOKKA on 2020/7/10.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int addr, data, nxt;
};

map<int, Node> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int hd, N, K;
    cin >> hd >> N >> K;
    for (int i = 0; i < N; i++) {
        Node tmp;
        cin >> tmp.addr >> tmp.data >> tmp.nxt;
        mp[tmp.addr] = tmp;
    }

    vector<Node> v[3];
    while (hd != -1) {
        if (mp[hd].data < 0) {
            v[0].push_back(mp[hd]);
        } else if (mp[hd].data <= K) {
            v[1].push_back(mp[hd]);
        } else {
            v[2].push_back(mp[hd]);
        }
        hd = mp[hd].nxt;
    }

    int flag = 0;
    for (int i = 0; i < 3; i++) {
        int len = v[i].size();
        for (int j = 0; j < len; j++) {
            if (!flag++) {
                printf("%05d %d ", v[i][j].addr, v[i][j].data);
            } else {
                printf("%05d\n%05d %d ", v[i][j].addr, v[i][j].addr, v[i][j].data);
            }
        }
    }
    printf("-1\n");
}
