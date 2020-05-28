//
// Created by LOKKA on 2020/5/25.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    int i = 0, len = str.size();
    while (str[i] != 'E') i++;
    char sym = str[i + 1];
    int sum = 0;
    for (int j = i + 2; j < len; j++) {
        sum = sum * 10 + str[j] - '0';
    }
    if (str[0] == '-')
        printf("-");
    if (sym == '+') {
        int j = 1, pnt = 2 + sum;
        for (; j < i; j++) {
            if (j == pnt + 1) printf(".");
            if (str[j] == '.') continue;
            printf("%c", str[j]);
        }
        while (j++ <= pnt) {
            printf("0");
        }
    } else {
        printf("0.");
        while(--sum) {
            printf("0");
        }
        for (int j = 1; j < i; j++) {
            if (str[j] == '.') continue;
            printf("%c", str[j]);
        }
    }
    printf("\n");
}