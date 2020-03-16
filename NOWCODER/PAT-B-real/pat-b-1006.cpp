//
// Created by LOKKA on 2020/3/16.
// 1006 部分A+B

#include <iostream>

using namespace std;

void func(int x, int dx, int &px) {
    while (x) {
        int tmp = x % 10;
        if (tmp == dx) {
            px = px * 10 + tmp;
        }
        x /= 10;
    }
}

int main() {
    int a, da, b, db, pa, pb;
    pa = pb = 0;

    cin >> a >> da >> b >> db;
    func(a, da, pa);
    func(b, db, pb);
    cout << pa + pb << endl;
}
