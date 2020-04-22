//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

bool func(int x) {
    for (int i = 2; i <= ceil(sqrt(x)); i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    queue<int> que;
    int a, b, d, t;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (func(i))cout << i << "=" << i << endl;
        else {
            t = i;
            d = 2;
            while (t) {
                if (t % d == 0) {
                    que.push(d);
                    if (t == d) break;
                    t /= d;
                } else {
                    d++;
                }
            }
            cout << i << "=";
            while (que.size()) {
                cout << que.front();
                que.pop();
                if (que.size())cout << "*";
            }
            cout << endl;
        }
    }
}