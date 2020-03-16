//
// Created by LOKKA on 2020/3/16.
// 1010 月饼

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
struct Item {
    int kc, zsj;
    float dj;
};

bool cmp(const Item *ia, const Item *ib) {
    return ia->dj > ib->dj;
}

int main() {
    int n, d, kc, zsj;
    cin >> n >> d;
    Item *item[1050];

    for (int i = 0; i < n; i++) {
        item[i] = new Item;
        cin >> item[i]->kc;
    }
    for (int i = 0; i < n; i++) {
        cin >> item[i]->zsj;
        item[i]->dj = item[i]->zsj * 1.0 / item[i]->kc;
    }
    sort(item, item + n, cmp);

    float ans = 0;
    for (int i = 0; i < n && d; i++) {
        if (item[i]->kc < d) {
            ans += item[i]->zsj;
            d -= item[i]->kc;

        } else {
            ans += d * item[i]->dj;
            d = 0;
        }
    }
    printf("%.2f", ans);
}
