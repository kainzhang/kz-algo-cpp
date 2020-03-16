//
// Created by LOKKA on 2020/3/16.
// 1001 A+B和C

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        long a, b, c;
        cin >> a >> b >> c;
        if (a + b > c) {
            cout << "Case #" << i << ": true" << endl;
        } else {
            cout << "Case #" << i << ": false" << endl;
        }
    }
}