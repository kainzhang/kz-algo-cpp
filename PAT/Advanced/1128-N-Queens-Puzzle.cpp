//
// Created by LOKKA on 2020/7/1.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K;
    cin >> K;
    while(K--) {
        int N, t, flag = 1;
        cin >> N;
        vector<int> vec;
        for (int i = 0; i < N; i++) {
            cin >> t;
            vec.push_back(t);
            // 左、右对角线变量
            int l = t - 1, r = t + 1;
            // 检查之前的所有行
            for (int j = i - 1; j >= 0 && flag; j--) {
                if (vec[j] == t || vec[j] == l || vec[j] == r) {
                    flag = 0;
                }
                l--, r++;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}
