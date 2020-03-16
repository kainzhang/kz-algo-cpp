//
// Created by LOKKA on 2020/3/16.
// 1005 德才论

#include <iostream>
#include <algorithm>

using namespace std;

struct Stu {
    int id, de, ca, sum, rank;
};

bool cmp(const Stu *stua, const Stu *stub) {
    if (stua->rank == stub->rank) {
        if (stua->sum == stub->sum) {
            if (stua->de == stub->de) {
                return stua->id < stub->id;
            } else {
                return stua->de > stub->de;
            }
        } else {
            return stua->sum > stub->sum;
        }
    } else {
        return stua->rank < stub->rank;
    }
}

int main() {
    int n, l, h, cnt = 0;
    cin >> n >> l >> h;
    Stu *stu[100010];
    for (int i = 0; i < n; i++) {
        stu[i] = new Stu;
        cin >> stu[i]->id >> stu[i]->de >> stu[i]->ca;
        stu[i]->sum = stu[i]->de + stu[i]->ca;

        if (stu[i]->de >= l && stu[i]->ca >= l) {
            cnt++;
            if (stu[i]->de >= h && stu[i]->ca >= h)
                stu[i]->rank = 1;
            else if (stu[i]->de >= h && stu[i]->ca < h)
                stu[i]->rank = 2;
            else if (stu[i]->de < h && stu[i]->ca < h && stu[i]->de >= stu[i]->ca)
                stu[i]->rank = 3;
            else
                stu[i]->rank = 4;
        } else {
            stu[i]->rank = 5;
        }
    }
    sort(stu, stu + n, cmp);
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
        cout << stu[i]->id << " " << stu[i]->de << " " << stu[i]->ca << endl;
}