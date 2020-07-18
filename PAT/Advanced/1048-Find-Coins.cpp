//
// Created by LOKKA on 2020/7/18.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &c[i]);
    }
    sort(c.begin(), c.end());
    int l = 0, r = N - 1;
    while (l < r) {
        if (c[l] + c[r] == M) {
            printf("%d %d\n", c[l], c[r]);
            return 0;
        } else if (c[l] + c[r] > M) {
            r--;
        } else {
            l++;
        }
    }
    printf("No Solution\n");
}
