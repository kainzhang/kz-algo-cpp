//
// Created by LOKKA on 2020/7/5.
//

#include <bits/stdc++.h>
using namespace std;

struct cus {
    int aT, pT;
    bool operator < (const cus &c) const {
        return aT < c.aT;
    }
};

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    vector<cus> line;
    for (int i = 0; i < N; i++) {
        int HH, MM, SS, P;
        scanf("%d:%d:%d %d", &HH, &MM, &SS, &P);
        cus c;

        // 时间转换为秒
        c.aT = HH * 3600 + MM * 60 + SS;
        c.pT = P * 60;
        if (c.aT > 61200) continue;
        line.push_back(c);
    }

    // 按顾客到达时间排序
    sort(line.begin(), line.end());
    int len = line.size();
    double sumT = 0;

    //  就绪队列，默认值为 8:00:00
    priority_queue <int,vector<int>, greater<int> > win(K, 28800);

    for (int i = 0; i < len; i++ ) {
        int window = win.top(); win.pop();
        int wait = window - line[i].aT;

        if (wait < 0) {
            wait = 0;  // 等待时间小于 0 即没等待
            window = line[i].aT + line[i].pT;
        } else {
            window += line[i].pT;
        }
        sumT += wait;
        win.push(window);  // 窗口重新进入就绪队列
    }
    printf("%.1f\n", sumT / 60 / len);
}
