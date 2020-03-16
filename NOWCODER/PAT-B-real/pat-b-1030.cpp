//
// Created by LOKKA on 2020/3/16.
// 1030 有几个PAT

#include <iostream>

using namespace std;

int main() {
    char ch;
    int p, a, t;
    p = a = t = 0;
    while(cin >> ch) {
        switch(ch) {
            case 'P': p++; p %= 1000000007; break;
            case 'A': a += p; a %= 1000000007; break;
            case 'T': t += a; t %= 1000000007; break;
            default : break;
        }
    }
    cout << t << endl;
}