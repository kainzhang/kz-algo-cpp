//
// Created by LOKKA on 2020/3/22.
// 旅行家的预算 (贪心

#include <iostream>

using namespace std;

int main() {
    double d1, c, d2, p[1000], d[1000], ans = 0, left = 0;
    int n;
    cin >> d1 >> c >> d2 >> p[0] >> n;
    double max_d = c * d2;
    for (int i = 1; i <= n; i ++) {
        cin >> d[i] >> p[i];
        if (d[i] - d[i-1] > max_d) {
            cout << "No Solution" << endl;
            return 0;
        }
    }
    d[n + 1] = d1;
    p[n + 1] = 0;
    for (int i = 0, j; i <= n; i = j) {
        for(j = i + 1; j <= n + 1; j ++) {
            if (d[j] - d[i] > max_d) { //超出满油能行驶的最远距离 (先判断
                j--;
                break;
            }
            if (p[j] < p[i]) //j站比i油价便宜
                break;
        }
        if (p[j] < p[i]) { //目的地比出发地便宜，只加刚好到达目的地的油量
            ans += p[i] * ((d[j] - d[i]) / d2 - left);
            left = 0;
        } else { //目的地比出发地贵，直接在出发地加满
            ans += p[i] * (c - left);
            left = c - (d[j] - d[i]) / d2;
        }
    }
    printf("%.2f", ans);
}