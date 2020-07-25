//
// Created by LOKKA on 2020/7/20.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    double P, D;
    bool operator < (Node &x) const {
        return D < x.D;
    }
};

double cmax, D, davg;
int N;

int main() {
    scanf("%lf %lf %lf %d", &cmax, &D, &davg, &N);
    vector<Node> sta(N + 1);
    sta[0] = {0, D};  // 加入终点
    for (int i = 1; i <= N; i++) {
        scanf("%lf %lf", &sta[i].P, &sta[i].D);
    }
    sort(sta.begin(), sta.end());
    double nowD = 0, totalP = 0, leftD = 0;
    bool ok = true;
    if (sta[0].D) {
        ok = false;
    } else {
        int pre = 0, nxt;
        while (nowD < D) {
            double min_P = INT_MAX, maxD = nowD + cmax * davg;
            int flag = 0;
            for (int i = pre + 1; i <= N && sta[i].D <= maxD; i++) {
                if (sta[i].P < sta[pre].P) {  // 比上一站便宜，只在上一站加到达这一站需要的油量
                    totalP += (sta[i].D - nowD - leftD) / davg * sta[pre].P;
                    leftD = 0.0;  // 油箱剩余油量可行使距离
                    pre = i;  // 更新站点
                    nowD = sta[i].D;  // 更新当前位置
                    flag = 1;
                    break;
                }
                if (sta[i].P < min_P) {  // 满油行驶距离内没上一站便宜，找到相对最便宜的
                    min_P = sta[i].P;
                    nxt = i;
                }
            }
            if (!flag) {
                if (min_P != INT_MAX) {  // 满油行驶距离内没上一站便宜，在上一站加满
                    totalP += (sta[pre].P * (cmax - leftD / davg));
                    leftD = cmax * davg - (sta[nxt].D - nowD);  // 行驶至当前站剩余可行驶的距离
                    nowD = sta[nxt].D; // 更新位置
                    pre =  nxt;  // 更新站点
                } else {  // 满油状态无法到达后续任何站点
                    nowD += cmax * davg;
                    ok = false;
                    break;
                };
            }
        }
    }
    if (ok) printf("%.2f", totalP);
    else printf("The maximum travel distance = %.2f", nowD);
}