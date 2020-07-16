//
// Created by LOKKA on 2020/7/16.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    string addr, nxt;
    bool operator < (const Node &x) const {
        return key < x.key;
    }
};

map<string, Node> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    string hd;
    cin >> N >> hd;
    for (int i = 0; i < N; i++) {
        string addr;
        Node node;
        cin >> node.addr >> node.key >> node.nxt;
        mp[node.addr] = node;
    }
    vector<Node> v;
    string head = hd;
    while (head != "-1") {
        v.push_back(mp[head]);
        head = mp[head].nxt;
    }
    sort(v.begin(), v.end());
    int len = v.size();
    if (!len) {
        cout << "0 -1" << endl;
        return 0;
    }
    cout << len << " " << v[0].addr << endl;
    for (int i = 0; i < len; i++) {
        cout << v[i].addr << " " << v[i].key;
        if (i < len - 1) cout << " " << v[i + 1].addr << endl;
        else cout << " -1" << endl;
    }
}
