//
// Created by LOKKA on 2020/4/10.
//

#include <iostream>

using namespace std;

int F[32] = {0, 1};

int fib(int N) {      //递归
    if (N < 2) return F[N] = N;
    return F[N] = fib(N - 1) + fib(N - 2);
}

//int fib(int N) {      //递推
//    if (N < 2) return N;
//    for (int i = 2; i <= N; i++)
//        F[i] = F[i - 1] + F[i - 2];
//    return F[N];
//}

int main() {
    int N;
    cin >> N;
    cout << fib(N);
}