//
// Created by LOKKA on 2020/3/17.
//

#include <cstdio>

int a[15][15], n, cnt = 0;

void queen(int i, int q) {
    for (int j = 0; j < n; j++) {
        if (a[i][j] == 0 || a[i][j] == 2)continue;
        int flag = 1, t = 1;
        for (int l = i - 1; l >= 0; l--) {
            if (a[l][j] == q || j - t >= 0 && a[l][j - t] == q || j + t < n && a[l][j + t] == q) {
                flag = 0;
                break;
            }
            t++;
        }
        if (flag) {
            a[i][j] = q;
            if (i < n - 1)queen(i + 1, q);
            else {
                if (q == 2)queen(0, 3);
                else cnt++;
            }
            a[i][j] = 1;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    queen(0, 2);
    printf("%d", cnt);
}