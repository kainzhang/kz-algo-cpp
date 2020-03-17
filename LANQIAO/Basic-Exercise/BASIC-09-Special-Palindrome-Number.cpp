//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 10000; i < 100000; i++) {
        int a = i % 10;
        int b = i / 10 % 10;
        int c = i / 100 % 10;
        int d = i / 1000 % 10;
        int e = i / 10000;
        if (a + b + c + d + e == n && a == e && b == d)
            cout << i << endl;
    }
    for (int i = 100000; i < 1000000; i++) {
        int a = i % 10;
        int b = i / 10 % 10;
        int c = i / 100 % 10;
        int d = i / 1000 % 10;
        int e = i / 10000 % 10;
        int f = i / 100000;
        if (a + b + c + d + e + f == n && a == f && b == e && c == d)
            cout << i << endl;
    }
}