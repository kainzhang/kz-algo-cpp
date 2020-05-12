//
// Created by LOKKA on 2020/5/12.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    scanf("%04d", &num);
    char str[5];
    sprintf(str, "%04d", num);
    if (str[0] == str[1] && str[1] == str[2] && str[2] == str[3]) {
        printf("%s - %s = 0000\n", str, str);
    } else {
        int a, b, ans = 0;
        while (ans != 6174) {
            sort(str, str + 4);
            sscanf(str, "%d", &a);
            sort(str, str + 4, greater<>());
            sscanf(str, "%d", &b);
            ans = b - a;
            printf("%04d - %04d = %04d\n", b, a, ans);
            sprintf(str, "%04d", ans);
        }
    }
}