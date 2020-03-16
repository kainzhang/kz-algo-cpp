//
// Created by LOKKA on 2020/3/16.
// 1013 组个最小数

#include <iostream>

using namespace std;

int main() {
    static int arr[11];
    for (int i = 0; i < 10; i++)
        cin >> arr[i];
    for (int i = 1; i < 10; i++) {
        if (arr[i] > 0) {
            cout << i;
            arr[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        while (arr[i] > 0) {
            cout << i;
            arr[i]--;
        }
    }
}