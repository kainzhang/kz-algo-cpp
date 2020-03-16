//
// Created by LOKKA on 2020/3/16.
// 1002 数字分类

#include <cstdio>

int main() {
    int n, t, i = 1, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a4c = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        switch (t % 5) {
            case 0:
                if (!(t & 1)) a1 += t;
                break;
            case 1:
                a2 += t * i;
                i *= -1;
                break;
            case 2:
                a3++;
                break;
            case 3:
                a4 += t;
                a4c++;
                break;
            case 4:
                a5 = t > a5 ? t : a5;
                break;
        }
    }
    a1 ? printf("%d ", a1) : printf("N ");
    a2 != 0 ? printf("%d ", a2) : printf("N ");
    a3 ? printf("%d ", a3) : printf("N ");
    a4 ? printf("%.1f ", a4 * 1.0 / a4c) : printf("N ");
    a5 ? printf("%d", a5) : printf("N");
}