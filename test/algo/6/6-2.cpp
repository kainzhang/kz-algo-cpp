//
// Created by LOKKA on 2020/5/22.
//

#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int res = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            res += solve(i);
            if (i * i == n) continue;
            res += solve(n / i);
        }
    }
    return res;
};

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
}