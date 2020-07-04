//
// Created by LOKKA on 2020/5/22.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r;
    bool operator < (const Node& x) const {
        return r < x.r;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Node> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].l >> vec[i].r;
        if (vec[i].r < vec[i].l) {
            swap(vec[i].r, vec[i].l);
        }
    }
    sort(vec.begin(), vec.end(), less<Node>());
    int flag = vec[0].r, cnt = 1;
    for (int i = 1; i < n; i++) {
        if (vec[i].l > flag) {
            cnt++;
            flag = vec[i].r;
        }
    }
    cout << n - cnt << endl;
}