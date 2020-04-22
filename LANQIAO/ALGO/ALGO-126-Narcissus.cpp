//
// Created by LOKKA on 2020/3/16.
//

#include<iostream>

using namespace std;

int main() {
    int n, c, t = 0;
    cin >> n;
    c = n;
    while(c) {
        t += (c % 10) * (c % 10) * (c % 10);
        c /= 10;
    }
    (t == n) ? cout << "YES" : cout << "NO";
    cout << endl;
}