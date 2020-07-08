//
// Created by LOKKA on 2020/7/7.
//

#include <bits/stdc++.h>
using namespace std;

struct mic {
    int idx, weit, ranc;
};

map<int, mic> mp;
queue<mic> que;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int NP, NG;
    cin >> NP >> NG;
    vector<int> W(NP);
    for (int i = 0; i < NP; i++) {
        cin >> W[i];
    }
    for (int i = 0; i < NP; i++) {
        int idx;
        mic m;
        cin >> idx;
        m.idx = idx;
        m.weit = W[idx];
        que.push(m);
        mp[idx] = m;
    }
    int cnt = 0, rk = ceil(NP * 1.0 / NG) + 1, mxW = -1, mxW_id;
    while (!que.empty()) {
        mic mm = que.front();
        que.pop();
        if (mm.weit > mxW) {
            mxW = mm.weit;
            mxW_id = mm.idx;
        }
        mp[mm.idx].ranc = rk;  // 更新排名
        cnt++;
        if (cnt % NG == 0 || cnt == NP) {  // 一组结束
            que.push(mp[mxW_id]);  // 最胖的老鼠晋级
            mxW = -1;
            if (cnt == NP) {  // 本轮结束
                NP = que.size();  // 更新选手数量
                if (NP == 1) {  // 只剩一老鼠，结束循环
                    mp[mxW_id].ranc = 1;
                    break;
                }
                rk = ceil(NP * 1.0 / NG) + 1;  // 下一组失败者名次
                cnt = 0;
            }
        }
    }
    int flag = 0;
    for (auto &i : mp) {
        if (flag) cout << " ";
        cout << i.second.ranc;
        flag++;
    }
}
