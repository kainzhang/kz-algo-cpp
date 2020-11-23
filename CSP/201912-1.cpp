//
// Created by Kain Zhang on 2020/9/1.
//

#include <bits/stdc++.h>
using namespace std;

bool seven(int x) {
    if (x % 7 == 0) return true;
    while(x) {
        int t = x % 10;
        if (t == 7) return true;
        x /= 10;
    }
    return false;
}

int main() {
    int n, cnt = 0;
    vector<int> a(5);
    cin >> n;
    for (int i = 0; cnt < n; i++) {
        if (seven(i + 1)) a[i % 4]++;
        else cnt++;
    }
    for (int i = 0; i < 4; i++) {
        cout << a[i] << endl;
    }
}