//
// Created by LOKKA on 2020/7/17.
//

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int MSize, N, M;
    cin >> MSize >> N >> M;
    while (!isPrime(MSize)) MSize++;
    vector<int> v(MSize);
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        bool flag = false;
        for (int j = 0; j < MSize; j++) {
            int idx = (num + j * j) % MSize;
            if (!v[idx]) {
                v[idx] = num;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << num << " " << "cannot be inserted." << endl;
    }
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        cin >> num;
        for (int j = 0; j <= MSize; j++) {  // 找不到的多一次
            cnt++;
            int idx = (num + j * j) % MSize;
            if (v[idx] == num || !v[idx]) break;
        }
    }
    cout << fixed << setprecision(1);
    cout << cnt * 1.0 / M << endl;
}
