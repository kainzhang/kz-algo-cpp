//
// Created by LOKKA on 2020/7/9.
//

#include <bits/stdc++.h>
using namespace std;

struct stu {
    string name;
    int heit;
    bool operator < (const stu &x) const {
        if (heit == x.heit) {
            return name < x.name;
        }
        return heit > x.heit;
    }
};

vector<stu> vec;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i].name >> vec[i].heit;
    }
    sort(vec.begin(), vec.end()); //按从高到低排序
    int L, top = 0;
    for (int i = K; i > 0; i--) {

        // 各排人数
        if (i == K) {
            L = N - N / K * (K - 1);
        } else {
            L = N / K;
        }
        vector<string> row(L);
        row[L / 2] = vec[top].name;

        // 从中间至左边
        int j = L / 2 - 1;
        for (int k = top + 1; k < top + L; k += 2) {
            row[j--] = vec[k].name;
        }

        // 从中间至右边
        j = L / 2 + 1;
        for (int k = top + 2; k < top + L; k += 2) {
            row[j++] = vec[k].name;
        }

        // 更新为下一排最高个
        top += L;

        for (int k = 0; k < L; k++) {
            if (k) cout << " ";
            cout << row[k];
        }
        cout << endl;
    }
}
