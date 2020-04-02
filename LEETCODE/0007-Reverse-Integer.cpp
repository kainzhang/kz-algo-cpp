//
// Created by LOKKA on 2020/4/3.
//

#include <iostream>

using namespace std;

int reverse(int x) {
    int max = INT_MAX, min = INT_MIN, res = 0;
    while(x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return (res > max || res < min) ? 0 : res ;
}

int main() {
    cout << reverse(123) << endl;
    cout << reverse(-123) << endl;
    cout << reverse(120) << endl;
}