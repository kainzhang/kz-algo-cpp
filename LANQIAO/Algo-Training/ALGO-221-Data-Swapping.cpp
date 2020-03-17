//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    x ^= y;
    y ^= x;
    x ^= y;
}

int main() {
    int x, y;
    while(cin >> x >> y) {
        swap(x, y);
        cout << x <<" " << y << endl;
    }
}