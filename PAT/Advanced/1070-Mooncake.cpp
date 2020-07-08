//
// Created by LOKKA on 2020/7/7.
//

#include <bits/stdc++.h>
using namespace std;

struct MC {
    double tons, price;
    bool operator < (const MC &x) const {
        return price / tons > x.price / x.tons;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, D;
    cin >> N >> D;
    vector<MC> mc(N);
    for (int i = 0; i < N; i++) {
        cin >> mc[i].tons;
    }
    for (int i = 0; i < N; i++) {
        cin >> mc[i].price;
    }
    sort(mc.begin(), mc.end());
    double sum = 0;
    for (auto &i : mc) {
        if (i.tons < D) {
            sum += i.price;
            D -= i.tons;
        } else {
            sum += (i.price / i.tons) * D;
            break;
        }
    }
    printf("%.2f\n", sum);
}