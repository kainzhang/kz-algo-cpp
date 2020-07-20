//
// Created by LOKKA on 2020/7/19.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 5e5;

vector<int> p(mxN, 1);

void init() {
    for (int i = 2; i < mxN; i++) {
        if (p[i]) {
            for (int j = i + i; j < mxN; j += i) {
                p[j] = 0;
            }
        }
    }
}

int main() {
    init();
    int N;
    cin >> N;
    printf("%d=", N);
    if (N == 1) {
        printf("1");
        return 0;
    }
    int flag = 0;
    for (int i = 2; i < mxN && N >= 2; i++) {
        int cnt = 0, ok = 0;
        while (p[i] && N % i == 0) {
            cnt++;
            N /= i;
            ok = 1;
        }
        if (ok) {
            if (flag) printf("*");
            printf("%d", i);
            if (cnt >= 2) printf("^%d", cnt);
            flag++;
        }
    }
}
