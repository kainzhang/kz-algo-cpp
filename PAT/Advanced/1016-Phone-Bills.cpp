//
// Created by LOKKA on 2020/7/19.
//

#include <bits/stdc++.h>
using namespace std;

struct Rec {
    char name[25];
    int dd, HH, mm, time;
    bool on;
    bool operator < (const Rec &x) const {
        return (strcmp(name, x.name) == 0 ? time < x.time : strcmp(name, x.name) < 0);
    }
};

int N, c[25];
vector<Rec> v(1005);

double GetCharge(Rec A, Rec B) {
    double res = 0;
    while (A.dd != B.dd || A.HH != B.HH || A.mm != B.mm) {
        if (A.dd == B.dd && A.HH == B.HH) {
            res += c[A.HH] * (B.mm - A.mm);
            A.mm = B.mm;
        } else {
            res += c[A.HH] * (60 - A.mm);
            A.mm = 0;
            if (A.HH == 23) {
                A.HH = 0;
                A.dd++;
            } else {
                A.HH++;
            }
        }
    }
    return res / 100;
}

int main() {
    for (int i = 0; i < 24; i++) {
        scanf("%d", &c[i]);
    }
    scanf("%d", &N);
    int MM;
    char sign[10];
    for (int i = 0; i < N; i++) {
        scanf("%s %d:%d:%d:%d %s", v[i].name, &MM, &v[i].dd, &v[i].HH, &v[i].mm, sign);
        v[i].time = (v[i].dd * 24 + v[i].HH) * 60 + v[i].mm;
        if (sign[1] == 'n') v[i].on = true;
        else v[i].on = false;
    }
    sort(v.begin(), v.begin() + N);
    int flag = 0;
    double total_amt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (strcmp(v[i].name, v[i + 1].name) == 0 && v[i].on && !v[i + 1].on) {
            if (!flag) {
                printf("%s %02d\n", v[i].name, MM);
                flag = 1;
            }
            double chag = GetCharge(v[i], v[i + 1]);
            printf("%02d:%02d:%02d %02d:%02d:%02d ", v[i].dd, v[i].HH, v[i].mm, v[i + 1].dd, v[i + 1].HH, v[i + 1].mm);
            printf("%d $%.2f\n", v[i + 1].time - v[i].time, chag);
            total_amt += chag;
        } else if (strcmp(v[i].name, v[i + 1].name)){
            if (flag) {
                printf("Total amount: $%.2f\n", total_amt);
            }
            flag = total_amt = 0;
        }
    }
    if (flag) {
        printf("Total amount: $%.2f\n", total_amt);
    }
}

