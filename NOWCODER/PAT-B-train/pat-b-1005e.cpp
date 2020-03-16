//
// Created by LOKKA on 2020/3/16.
// 1005e 斐波那契凤尾

#include <cstdio>

static int arr[100005];

int main() {
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < 100005; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
        if (arr[i] > 1000000) arr[i] %= 1000000;
    }
    int n;
    while (~scanf("%d", &n)) {
        if (n > 25)
            printf("%06d\n", arr[n + 1]);
        else
            printf("%d\n", arr[n + 1]);
    }
}