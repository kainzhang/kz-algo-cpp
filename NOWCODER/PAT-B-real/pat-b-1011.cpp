//
// Created by LOKKA on 2020/3/16.
// 1011 个位数统计

#include <iostream>

using namespace std;

int main() {
    int arr[15] = {0};
    char tmp;
    while (tmp = getchar()) {
        if (tmp == '\n') break;
        arr[tmp - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (arr[i])
            cout << i << ":" << arr[i] << endl;
    }
}