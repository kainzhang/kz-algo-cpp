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
    sta[0] = {0, D};
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
                if (sta[i].P < sta[pre].P) {  // 比当前所在站便宜
                    totalP += (sta[i].D - nowD - leftD) * sta[pre].P / davg;
                    leftD = 0.0;
                    pre = i;
                    nowD = sta[i].D;
                    flag = 1;
                    break;
                }
                if (sta[i].P < min_P) {  // 没当前所在站便宜，相对便宜
                    min_P = sta[i].P;
                    nxt = i;
                }
            }
            if (!flag) {
                if (min_P != INT_MAX) {
                    totalP += (sta[pre].P * (cmax - leftD / davg));
                    leftD = cmax * davg - (sta[nxt].D - nowD);
                    nowD = sta[nxt].D;
                    pre =  nxt;
                } else {
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