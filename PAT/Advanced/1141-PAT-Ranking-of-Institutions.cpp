//
// Created by LOKKA on 2020/7/21.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 5;

struct Node {
    string name;
    double sum = 0;
    int Ns, tws;
    bool operator < (const Node& x) const {
        if (tws == x.tws) {
            if (Ns == x.Ns) {
                return name < x.name;
            }
            return Ns < x.Ns;
        }
        return tws > x.tws;
    }
};

vector<Node> v(mxN);
unordered_map<string, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, sco, cnt = 0;
    string tid, iid;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tid >> sco >> iid;
        transform(iid.begin(), iid.end(), iid.begin(), ::tolower);
        int idx = mp[iid];
        if (!idx) {
            idx = ++cnt;
            mp[iid] = idx;
            v[idx].name = iid;
        }
        v[idx].Ns++;
        switch(tid[0]) {
            case 'B': v[idx].sum += sco * 1.0 / 1.5; break;
            case 'A': v[idx].sum += sco * 1.0; break;
            case 'T': v[idx].sum += sco * 1.5; break;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        v[i].tws = (int) v[i].sum;   // 务必排序前转换，否则有一个测试点不通过
    }
    sort(v.begin() + 1, v.begin() + cnt + 1);
    printf("%d\n", cnt);
    int rk = 0, pre = -1;
    for (int i = 1; i <= cnt; i++) {
        if (v[i].tws != pre) {
            pre = v[i].tws;
            rk = i;
        }
        printf("%d %s %d %d\n", rk, v[i].name.c_str(), v[i].tws, v[i].Ns);
    }
}