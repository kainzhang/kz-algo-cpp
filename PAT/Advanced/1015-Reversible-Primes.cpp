//
// Created by LOKKA on 2020/4/21.
//

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    int sqr = (int) sqrt(1.0 * x);
    for (int i = 2; i <= sqr; i++)
        if (x % i == 0) return false;
    return true;
}

int radixFunc(int x, int r) {
    int res = 0;
    while (x) {
        res = res * r + x % r;
        x /= r;
    }
    return res;
}

int main() {
    int N, D;
    while (scanf("%d", &N), N >= 0) {
        scanf("%d", &D);
        if (isPrime(N)) {
            N = radixFunc(N, D);
            cout << (isPrime(N) ? "Yes" : "No") << endl;
        } else {
            cout << "No" << endl;
        }
    }
}