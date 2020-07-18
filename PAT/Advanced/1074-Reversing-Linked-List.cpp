//
// Created by LOKKA on 2020/7/17.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    string addr, next;
};

unordered_map<string, Node> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string fst;
    int N, K;
    cin >> fst >> N >> K;
    Node t;
    while (N--) {
        cin >> t.addr >> t.val >> t.next;
        mp[t.addr] = t;
    }
    vector<Node> v;
    while (fst[0] != '-') {
        v.push_back(mp[fst]);
        fst = mp[fst].next;
    }
    int len = v.size(), flag = 0;
    for (int i = 0; (i + 1) * K <= len; i++) {
        for (int j = (i + 1) * K - 1; j >= i * K; j--) {
            if (flag++) printf("%s\n%s %d ", v[j].addr.c_str(), v[j].addr.c_str(), v[j].val);
            else printf("%s %d ", v[j].addr.c_str(), v[j].val);
        }
    }
    for (int j = len - len % K; j < len; j++) {
        if (flag++) printf("%s\n%s %d ", v[j].addr.c_str(), v[j].addr.c_str(), v[j].val);
        else printf("%s %d ", v[j].addr.c_str(), v[j].val);
    }
    printf("-1\n");
}
