//
// Created by LOKKA on 2020/5/17.
//

#include <bits/stdc++.h>
using namespace std;

struct node {
    int idx, w;

    bool operator < (const node& x) const {
        return w < x.w;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c;
    cin >> n >> c;
    vector<node> a(n), res;
    for (int i = 0; i < n; i++) {
        cin >> a[i].w;
        a[i].idx = i + 1;
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + a[i].w > c) break;
        sum += a[i].w;
        res.push_back(a[i]);
    }
    if (res.size()) {
        cout << "Cnt: " << res.size() << endl;
        cout << "Ans: " ;
        for (node i : res)
            cout << i.idx << " ";
    } else {
        cout << "No answer!";
    }
}
