//
// Created by LOKKA on 2020/3/16.
// 1003e 养兔子

#include <iostream>

using namespace std;

long long fib(int n, long long a, long long b) {
    if (n == 0) return a;
    else if (n == 1) return b;
    return fib(n - 1, b, a + b);
}

int main() {
    int n;
    while (cin >> n)
        cout << fib(n + 1, 0, 1) << endl;
}