//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>

int main() {
    int n, m, cur = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = cur; j > 0; j--) {
            cnt++;
            printf("%c", 'A' + j);
            if (cnt == m)break;
        }
        for (int j = 0; j < m - cur; j++) {
            printf("%c", 'A' + j);
        }
        cur++;
        putchar('\n');
    }
}