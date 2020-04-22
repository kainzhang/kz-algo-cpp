//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>

using namespace std;

int main() {
    for (int i = 100; i < 1000; i++) {
        int a = i % 10;
        int b = i / 10 % 10;
        int c = i / 100;
        if (a * a * a + b * b * b + c * c * c == i)
            cout << i << endl;
    }
}