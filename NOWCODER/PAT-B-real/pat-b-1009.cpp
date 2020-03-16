//
// Created by LOKKA on 2020/3/16.
// 1009 数字黑洞

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void func1(char arr[], int &a, int &b) {
    a = b = 0;
    for (int i = 0; i < 4; i++) {
        b *= 10;
        b += arr[i] - '0';
        a *= 10;
        a += arr[3 - i] - '0';
    }
}

void func2(char arr[], int tmp) {
    for (int i = 0; i < 4; i++) {
        arr[i] = tmp % 10 + '0';
        tmp /= 10;
    }
}

int main() {
    char str[6];
    int numa, numb, res = 0;
    cin >> res;
    do {
        func2(str, res);
        sort(str, str + 4);
        func1(str, numa, numb);
        res = numa - numb;
        printf("%04d - %04d = %04d\n", numa, numb, res);
    } while (res != 6174 && res != 0);
}