//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>

using namespace std;

int main() {
    string str = "A";
    int n, step = 1;
    cin >> n;
    while (--n) {
        char c = 'A' + step;
        str = str + c + str;
        step++;
    }
    cout << str;
}