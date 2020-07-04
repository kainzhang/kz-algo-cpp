//
// Created by LOKKA on 2020/7/3.
//

#include <bits/stdc++.h>
using namespace std;

struct num {
    double exp;
    int coe;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int KA, KB;
    cin >> KA;
    vector<num> A(KA);
    for (int i = 0; i < KA; i++) {
        cin >> A[i].coe >> A[i].exp;
    }
    cin >> KB;
    vector<num> B(KB);
    for (int i = 0; i < KB; i++) {
        cin >> B[i].coe >> B[i].exp;
    }

    map<int, double> mp;
    for(int i = 0; i < KA; i++) {
        for (int j = 0; j < KB; j++) {
            double EXP = A[i].exp * B[j].exp;
            mp[A[i].coe + B[j].coe] += EXP;
        }
    }

    int cnt = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        // 排除系数为 0 的
        if (it->second)
            cnt++;
    }
    printf("%d",  cnt);
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        // 排除系数为 0 的
        if (it->second)
            printf(" %d %.1f", it->first, it->second);
    }
}