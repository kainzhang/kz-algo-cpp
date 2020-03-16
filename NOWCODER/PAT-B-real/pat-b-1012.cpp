//
// Created by LOKKA on 2020/3/16.
// 1012 D进制的A+B

#include <iostream>

using namespace std;
long long a, b, d, t;

void func(long long num) {
    if (num == 0) return;
    func(num / d);
    cout << num % d;
}

int main() {
    cin >> a >> b >> d;
    t = a + b;
    func(t);
}