//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>

using namespace std;

int main() {
    int n, a[1050], x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x;
    for (int i = 0; i < n; i++)
        if (a[i] == x) {
            cout << i + 1;
            return 0;
        }
    cout << -1;
}
