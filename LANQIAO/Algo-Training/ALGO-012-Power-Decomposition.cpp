//
// Created by LOKKA on 2020/3/19.
// 幂方分解

#include <cstdio>

void dfs(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    bool flag = false;
    for (int i = 31; i >= 0; i--) {
        if ((1 << i) & n) {
            if (flag) printf("+");
            flag = true;
            if (i == 1) printf("2");
            else {
                printf("2(");
                dfs(i);
                printf(")");
            }
        }
    }
}

int main() {
    int n;
    while (~scanf("%d", &n))
        dfs(n);
}