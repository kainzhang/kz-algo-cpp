//
// Created by LOKKA on 2020/3/16.
// 1008 锤子剪刀布

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int judge(char a, char b) {
    if (a == b) return 0;
    if ((a == 'C' && b == 'J') ||
        (a == 'J' && b == 'B') ||
        a == 'B' && b == 'C')
        return -1;
    return 1;
}

int getType(char a) {
    switch (a) {
        case 'B': return 0;
        case 'C': return 1;
        case 'J': return 2;
    }
    return -1;
}

char maxType(int arr[]) {
    int tmp = *max_element(arr, arr + 3);
    if (arr[0] == tmp) return 'B';
    if (arr[1] == tmp) return 'C';
    return 'J';
}

int main() {
    int n, ans1[3] = {0, 0, 0}, ans2[3] = {0, 0, 0};
    int win1 = 0, win2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        if (judge(a, b) < 0) {
            ans1[getType(a)]++;
            win1++;
        } else if (judge(a, b) > 0) {
            ans2[getType(b)]++;
            win2++;
        }
    }
    printf("%d %d %d\n", win1, n - win1 - win2, win2);
    printf("%d %d %d\n", win2, n - win1 - win2, win1);
    printf("%c %c", maxType(ans1), maxType(ans2));
}