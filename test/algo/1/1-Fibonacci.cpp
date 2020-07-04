//
// Created by LOKKA on 2020/5/16.
//

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2;
vector<int> F(MAXN);

int fib(int n) {
    if (F[n]) return F[n];
    return F[n] = (n < 2) ? 1 : fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    while(cin >> n) {
        cout << "Fibonacci数列第 " << n << " 项: ";
        cout <<  fib(n) << endl;
    }

}