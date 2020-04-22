//
// Created by LOKKA on 2020/4/19.
//

#include <iostream>

using namespace std;

char ch[] = {"0123456789ABC"};

void calc(int x) {
    cout << ch[x / 13] << ch[x % 13];
}

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    cout << "#";
    calc(r);
    calc(g);
    calc(b);
    cout << endl;
}