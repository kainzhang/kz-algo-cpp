//
// Created by LOKKA on 2020/7/6.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 5;

struct node {
    char data;
    int next;
};

vector<node> lst(mxN);
map<int, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a1, a2, N, addr;
    cin >> a1 >> a2 >> N;
    for (int i = 0 ; i < N; i++) {
        cin >> addr;
        cin >> lst[addr].data >> lst[addr].next;
    }
    addr = a1;
    while (addr != -1) {
        mp[addr]++;
        addr = lst[addr].next;
    }
    addr = a2;
    int cnt = 0;
    while (addr != -1 && cnt < N) {
        mp[addr]++;
        if (mp[addr] == 2) {
            printf("%05d\n", addr);
            return 0;
        }
        addr = lst[addr].next;
        cnt++;
    }
    printf("-1\n", addr);
}
