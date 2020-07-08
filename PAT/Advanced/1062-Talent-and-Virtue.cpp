//
// Created by LOKKA on 2020/7/7.
//

#include <bits/stdc++.h>
using namespace std;

struct man {
    string id;
    int vg, tg, rk;
    bool operator < (const man &x) const {
        if (rk == x.rk) {
            if (vg + tg == x.vg + x.tg) {
                if (vg == x.vg) {
                    return id < x.id;
                }
                return vg > x.vg;
            }
            return vg + tg > x.vg + x.tg;
        }
        return rk < x.rk;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, L, H;
    cin >> N >> L >> H;
    vector<man> men;
    for (int i = 0; i < N; i++) {
        man m;
        cin >> m.id >> m.vg >> m.tg;
        if (m.vg < L || m.tg < L) continue;
        if (m.vg >= H && m.tg >= H) {
            m.rk = 1;  // sage
        } else if (m.tg < H && m.vg >= H) {
            m.rk = 2;  // nobleman
        } else if (m.tg < H && m.vg < H && m.vg >= m.tg) {
            m.rk = 3;  // fool
        } else {
            m.rk = 4;  // rest
        }
        men.push_back(m);
    }
    sort(men.begin(), men.end());
    cout << men.size() << endl;
    for (auto &m : men) {
        cout << m.id << " " << m.vg << " " << m.tg << endl;
    }
}
