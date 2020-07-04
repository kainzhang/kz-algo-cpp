//
// Created by LOKKA on 2020/6/10.
//

#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
    int sqr = (int)sqrt(x);
    if (x == 2) return true;
    for (int i = 2; i <= sqr; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    int N, K, t;
    scanf("%d", &N);
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++) {
        scanf("%4d", &t);
        mp[t] = i + 1;
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%4d", &t);
        printf("%04d: ", t);
        if (mp.find(t) == mp.end()) {
            printf("Are you kidding?\n");
        } else {
            if (mp[t] == 1) {
                printf("Mystery Award\n");
            } else if (mp[t] == -1) {
                printf("Checked\n");
            } else if (is_prime(mp[t])) {
                    printf("Minion\n");
            } else {
                printf("Chocolate\n");
            }
            mp[t] = -1;
        }
    }
}