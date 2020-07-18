//
// Created by LOKKA on 2020/7/17.
//

#include <bits/stdc++.h>
using namespace std;

struct peo {
    string name;
    int age, nw;
    bool operator < (const peo &x) const {
        if (nw == x.nw) {
            if (age == x.age) {
                return name < x.name;
            }
            return age < x.age;
        }
        return nw > x.nw;
    }
};

vector<peo> v;

int main() {
    int N, K;
    cin >> N >> K;
    peo p;
    p.name.resize(50);
    for (int i = 0; i < N; i++) {
        scanf("%s %d %d", &p.name[0], &p.age, &p.nw);
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    int M, Amin, Amax;
    for (int i = 1; i <= K; i++) {
        scanf("%d %d %d", &M, &Amin, &Amax);
        printf("Case #%d:\n", i);
        int len = v.size(), cnt = 0;
        for (int j = 0; j < len ; j++) {
            if (v[j].age >= Amin && v[j].age <= Amax) {
                cnt++;
                printf("%s %d %d\n", v[j].name.c_str(), v[j].age, v[j].nw);
            }
            if (cnt == M) break;
        }
        if (!cnt) {
            printf("None\n");
        }
    }
}
