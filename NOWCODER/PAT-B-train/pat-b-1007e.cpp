//
// Created by LOKKA on 2020/3/16.
// 1007e 母牛的故事

#include <cstdio>

int main() {
    static int a[80];
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;
    for (int i = 5; i < 60; i++) {
        a[i] = a[i - 1] + a[i - 3];
    }
    int n;
    while (~scanf("%d", &n)) {
        printf("%d\n", a[n]);
    }
}