//
// Created by LOKKA on 2020/3/16.
// 1020 完美数列

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, p, arr[100005];
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + t; j < n; j++) {
            if (arr[j] > arr[i] * p)
                break;
            t++;
        }
    }
    cout << t << endl;
}