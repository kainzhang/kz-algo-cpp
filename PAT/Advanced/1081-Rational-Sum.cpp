//
// Created by LOKKA on 2020/5/25.
//

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int N, num, numS = 0, den, denS = 1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d/%d", &num, &den);
        numS = numS * den + denS * num;
        denS = denS * den;
        int t = gcd(abs(numS), abs(denS));
        numS /= t;
        denS /= t;
    }
    int itg = numS / denS;   // 获得整数部分
    numS %= denS;
    if (itg != 0) {
        printf("%d", itg);    // 输出非 0 整数部分
        if (numS == 0) return 0;    // 分子为 0，结束
        printf(" ");
    }
    if (numS == 0) {    //  整数 分子均为 0
        printf("0");
    } else {    // 分子不为零
        printf("%d/%d", numS, denS);
    }
}