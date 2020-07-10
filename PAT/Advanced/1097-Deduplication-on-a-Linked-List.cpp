//
// Created by LOKKA on 2020/7/8.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, nxt;
};

map<int, Node> mp;
map<int, int> vis;

void print_ll(int cur) {
    while (cur != -1) {
        printf("%05d %d ", cur, mp[cur].key);
        if (mp[cur].nxt == -1) {
            printf("-1\n");
        } else {
            printf("%05d\n",  mp[cur].nxt);
        }
        cur = mp[cur].nxt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int head, N;
    cin >> head >> N;
    for (int i = 0; i < N; i++) {
        Node nd;
        int addr;
        cin >> addr >> nd.key >> nd.nxt;
        mp[addr] = nd;
    }
    int res = head, rem_head = -1;
    Node *res_pre = &mp[head], *rem_pre = NULL;
    while (res != -1) {
        int tmp = mp[res].nxt;
        if (vis[abs(mp[res].key)]) {
            if (rem_head == -1) {
                rem_head = res;
            } else {
                rem_pre->nxt = res;
            }
            rem_pre = &mp[res];
        } else {
            vis[abs(mp[res].key)]++;
            res_pre->nxt = res;
            res_pre = &mp[res];
        }
        res = tmp;
    }

    res_pre->nxt = -1;
    // 如果删除表为空则不访问, 否则出现段错误
    if (rem_pre != NULL) rem_pre->nxt = -1;

    print_ll(head);
    print_ll(rem_head);
}
