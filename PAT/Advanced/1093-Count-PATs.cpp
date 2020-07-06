//
// Created by LOKKA on 2020/7/6.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    int p = 0, a = 0, t = 0;
    for (char c : str) {
        switch(c) {
            case 'P': p++; p %= 1000000007; break;
            case 'A': a += p; a %= 1000000007; break;
            case 'T': t += a; t %= 1000000007; break;
        }
    }
    cout << t << endl;
}
