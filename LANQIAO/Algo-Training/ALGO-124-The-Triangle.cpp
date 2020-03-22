//
// Created by LOKKA on 2020/3/22.
// 数字三角形

#include <iostream>

using namespace std;

int max_sum(int **a, int n) {
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);

    return a[0][0];
}

int main() {
    int n;
    scanf("%d", &n);
    int **a = new int *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[i + 1];
        for (int j = 0; j <= i; j++)
            scanf("%d", &a[i][j]);
    }
    cout << max_sum(a, n) << endl;
}


