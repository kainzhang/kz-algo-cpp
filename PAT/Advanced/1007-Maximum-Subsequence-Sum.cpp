//
// Created by LOKKA on 2020/7/3.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K;
    cin >> K;
    vector<int> vec(K);

    // l r 赋初始值 !!!
    int sum = 0, l = 0, r = K - 1, ans = INT_MIN, hd = 0;
    for (int i = 0; i < K; i++) {
        cin >> vec[i];
        sum += vec[i];  // 序列累加
        if (sum < 0) {  // 序列结束
            sum = 0;
            hd = i + 1;  // 新序列开头
        } else if (sum > ans) {
            ans = sum;
            l = hd;
            r = i;
        }
    }
    if (ans < 0) ans = 0; // 题目要求, 最大子序列和为负数时输出 0
    cout << ans << " " << vec[l] << " " << vec[r] << endl;
}